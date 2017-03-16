#include <iostream>
#include <cmath>
#include <cstdint>
#include <inttypes.h>
// Available at http://gmplib.org/ (Tested working using version 5.1.1)
#include <gmpxx.h>


mpz_class calcAprx(mpz_class startingRadius, mpz_class paint)
{
    return (sqrt(4 * startingRadius * startingRadius - 4 * startingRadius + 8 * paint + 1) - 2 * startingRadius + 1) / 4;
}

mpz_class calc(mpz_class startingRadius, mpz_class kpl)
{
    return kpl * (2 * kpl + 2 * startingRadius - 1);
}

mpz_class solve()
{
    mpz_class startingRadius, paint;

    std::cin >> startingRadius >> paint;

    mpz_class start = calcAprx(startingRadius, paint);

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
