
#include <iostream>
#include <cmath>
#include <cstdint>
#include <inttypes.h>


uint64_t calcAprx(long double startingRadius, long double paint)
{
    return (sqrt(4 * startingRadius * startingRadius - 4 * startingRadius + 8 * paint + 1) - 2 * startingRadius + 1) / 4;
}

uint64_t calc(uint64_t startingRadius, uint64_t kpl)
{
    return kpl * (2 * kpl + 2 * startingRadius - 1);
}

uint64_t solve()
{
    uint64_t startingRadius, paint;

    std::cin >> startingRadius >> paint;

    uint64_t start = calcAprx(startingRadius, paint);

    while(calc(startingRadius, start) < paint)
    {
        start++;
    }

    while(calc(startingRadius, start) > paint)
    {
        start--;
    }

    return start;
}

int main()
{
    unsigned int T;
    std::cin >> T;

    for(unsigned int i = 1; i <= T; i++)
    {
        std::cout << "Case #" << i << ": " << solve() << std::endl;
    }

    return 0;
}
