#include <iostream>

int main()
{
    unsigned T;
    std::cin >> T;
    for (unsigned t = 1; t <= T; ++t)
    {
        unsigned N, J;
        std::cin >> N >> J;
        std::cout << "Case #" << t << ":" << std::endl;
        for (unsigned i = 1; i + 1 < N; ++i)
        {
            for (unsigned j = i + 1; j + 1 < N; j += 2)
            {
                for (unsigned k = j + 1; k + 1 < N; ++k)
                {
                    for (unsigned l = k + 1; l + 1 < N; l += 2)
                    {
                        if (J == 0)
                        {
                            goto next_case;
                        }
                        std::cout << '1';
                        for (int p = 1; p < i; ++p)
                        {
                            std::cout << '0';
                        }
                        std::cout << '1';
                        for (int p = i + 1; p < j; ++p)
                        {
                            std::cout << '0';
                        }
                        std::cout << '1';
                        for (int p = j + 1; p < k; ++p)
                        {
                            std::cout << '0';
                        }
                        std::cout << '1';
                        for (int p = k + 1; p < l; ++p)
                        {
                            std::cout << '0';
                        }
                        std::cout << '1';
                        for (int p = l + 1; p + 1 < N; ++p)
                        {
                            std::cout << '0';
                        }
                        std::cout << "1 3 4 5 6 7 8 9 10 11" << std::endl;
                        --J;
                    }
                }
            }
        }
        next_case:;
    }
    return 0;
}
