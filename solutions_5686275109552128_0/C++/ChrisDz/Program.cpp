#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

int compute(const std::vector<int>& diners)
{
    int minTime = std::numeric_limits<int>::max();

    for (int stackLimit = 1; stackLimit <= 1000; ++stackLimit)
    {
        int time = stackLimit;

        for (auto d : diners)
        {
            int stacks = static_cast<int>(std::ceil(double(d) / double(stackLimit)));
            time += std::max(stacks - 1, 0);
        }

        minTime = std::min(minTime, time);
    }

    return minTime;
}

int main()
{
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        int D;
        std::cin >> D;

        std::vector<int> diners;
        for (int j = 0; j < D; ++j)
        {
            int d;
            std::cin >> d;
            diners.push_back(d);
        }

        std::cout << "Case #" << i << ": " << compute(diners) << std::endl;
    }

    return 0;
}
