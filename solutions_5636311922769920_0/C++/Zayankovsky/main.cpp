#include <iostream>

int main()
{
    unsigned T;
    std::cin >> T;
    for (unsigned t = 1; t <= T; ++t)
    {
        unsigned K, C, S;
        std::cin >> K >> C >> S;
        std::cout << "Case #" << t << ":";
        if (S * C < K)
        {
            std::cout << " IMPOSSIBLE" << std::endl;
            continue;
        }
        unsigned item = 0;
        for (unsigned s = 0; s * C < K; ++s)
        {
            unsigned long long position = 0;
            for (unsigned c = 0; c < C; ++c)
            {
                position *= K;
                position += item;
                if (item + 1 < K)
                {
                    ++item;
                }
            }
            std::cout << ' ' << position + 1;
        }
        std::cout << std::endl;
    }
    return 0;
}
