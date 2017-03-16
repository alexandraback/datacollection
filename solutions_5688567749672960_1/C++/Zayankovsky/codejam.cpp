#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

int main()
{
    long long T, N, answer;
    std::cin >> T;
    for (long long i = 1; i <= T; ++i)
    {
        std::cin >> N;
        bool inc_after = N % 10 == 0;
        if (inc_after)
        {
            --N;
        }
        long long n = log10(N) + 1;
        if (n > 1)
        {
            answer = -1;
        }
        else
        {
            answer = 0;
        }
        for (long long j = 1; j < n; ++j)
        {
            answer += pow(10, j / 2) + pow(10, j - j / 2) - 1;
        }
        std::string half = std::to_string((long long)(N / pow(10, n - n / 2)));
        std::reverse(half.begin(), half.end());
        long long add = stoll(half);
        answer += add;
        if (add > 1)
        {
            ++answer;
        }
        answer += N % (long long)pow(10, n - n / 2);
        std::cout << "Case #" << i << ": " << answer + inc_after << std::endl;
    }
    return 0;
}
