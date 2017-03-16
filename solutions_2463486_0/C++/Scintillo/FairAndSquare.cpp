#include <iostream>
// Available at http://gmplib.org/ (Tested working using version 5.1.1)
#include <gmpxx.h>

bool isPal(std::string const& str)
{
    unsigned int a = 0;
    unsigned int b = str.length() - 1;

    while(a < b)
    {
        if(str[a] != str[b])
            return false;

        a++;
        b--;
    }

    return true;
}

uint64_t solve()
{
    mpz_class a, b;

    std::cin >> a >> b;

    mpz_class aSqrt = sqrt(a);
    mpz_class bSqrt = sqrt(b) + 1;

    uint64_t total = 0;

    for(mpz_class i = aSqrt; i <= bSqrt; i++)
    {
        if(isPal(i.get_str()))
        {
            mpz_class candidate = i * i;

            if(candidate >= a && candidate <= b && isPal(candidate.get_str()))
            {
                total++;
            }
        }
    }

    return total;
}

int main()
{
    unsigned int t;
    std::cin >> t;

    for(unsigned int i = 1; i <= t; ++i)
    {
        std::cout << "Case #" << i << ": " << solve() << std::endl;
    }
}
