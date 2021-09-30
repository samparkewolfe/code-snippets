template <typename T> std::vector<T> scaleVectorBetweenMinus1And1(const std::vector<T>& unscaledVec)
{
    std::vector<T> vec = unscaledVec;

    T largestVal = std::max(*max_element(vec.begin(), vec.end()), abs(*min_element(vec.begin(), vec.end())));

    for (auto& e : vec)
    {
        e *= (1 / largestVal);
    }

    return std::move(vec);
}

template <typename T> std::vector<T> minMaxScaleVector(const std::vector<T>& unscaledVec)
{
    std::vector<T> vec = unscaledVec;

    T min = *min_element(vec.begin(), vec.end());
    T max = *max_element(vec.begin(), vec.end());

    for (auto& e : vec)
    {
        e = ((e - min) / (max - min));
    }

    return std::move(vec);
}

template <typename T> auto findFurthestDistanceFrom0(const T& vecBegin, const T& vecEnd)
{
    return std::max(*std::max_element(vecBegin, vecEnd), std::abs(*std::min_element(vecBegin, vecEnd)));
}

template <typename ArrayType>
float findFurthestValueFrom0InVectorOfArrays(std::vector<ArrayType>& frames)
{
    float furthestDistanceFrom0 =
        findFurthestDistanceFrom0(frames[0].begin(), frames[0].begin() + frames[0].size());

    for (auto& frame : frames)
    {
        float furthestDistanceFrom0InFrame = findFurthestDistanceFrom0(frame.begin(), frame.begin() + frames[0].size());

        if (furthestDistanceFrom0InFrame > furthestDistanceFrom0)
        {
            furthestDistanceFrom0 = furthestDistanceFrom0InFrame;
        }
    }
    return furthestDistanceFrom0;
}
