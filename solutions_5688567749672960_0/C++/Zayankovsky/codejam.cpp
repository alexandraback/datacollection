#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

int main()
{

    size_t F[1000001];
    F[1] = 1;
    for (size_t i = 2; i <= 1000000; ++i)
    {
        F[i] = F[i - 1] + 1;
        if (i % 10 == 0)
        {
            continue;
        }
        std::string str = std::to_string(i);
        std::reverse(str.begin(), str.end());
        size_t j = std::stoul(str);
        if (j < i && F[j] < F[i - 1])
        {
            F[i] = F[j] + 1;
        }
    }

    long long T, N, answer;
    std::cin >> T;
    for (long long i = 1; i <= T; ++i)
    {
        std::cin >> N;
        /*long long n = log10(N) + 1;
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
        std::cout << "Case #" << i << ": " << answer << std::endl;*/
        std::cout << "Case #" << i << ": " << F[N] << std::endl;
    }
    return 0;
}
