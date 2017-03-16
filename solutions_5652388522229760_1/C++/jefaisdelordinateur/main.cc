#include <iostream>
#include <vector>

int main()
{
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        int N;
        std::cin >> N;
        std::cout << "case #" << i << ": ";
        if (N == 0)
            std::cout << "INSOMNIA";
        else
        {
            bool done = false;
            std::vector<bool> digits;
            digits.resize(10, false);
            int current = 0;
            for (int j = 0; !done; ++j)
            {
                done = true;
                current += N;
                int tmp = current;
                while (tmp > 0)
                {
                    digits[tmp % 10] = true;
                    tmp /= 10;
                }
                for (int i = 0; i < 10; ++i)
                    if (!digits[i])
                        done = false;
            }
            std::cout << current;
        }
        std::cout << '\n';
    }
}
