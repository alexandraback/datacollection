#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include "gmpxx.h"
typedef mpz_class big; 

using namespace std;

big interpret(uint32_t x, big base)
{
    big n = 0;
    big b = 1;
    for (int i = 0; i < 32; i++)
    {
        if (x & (1<<i))
        {
            n += b;
        }
        b *= base;
    }
    return n;
}

big find_div(big x)
{
    if (mpz_probab_prime_p(x.get_mpz_t(), 50) == 2)
    {
        /* if this is clearly prime, don't bother */
        return 0;
    }

    /* for the test case (n=32, j=500), it's enough to scan divisors up to 10 :) */
    for (big k = 2; k <= 10; k++)
    {
        if (x % k == 0)
        {
            return k;
        }
    }
    
    return 0;
}

int build_sol(uint32_t x, big divs[11])
{
    for (int b = 10; b >= 2; b--)
    {
        big xi = interpret(x, b);
        divs[b] = find_div(xi);
        if (divs[b] == 0)
        {
            return 0;
        }
    }
    
    return 1;
}

int main(int argc, char* argv[])
{
    int t, n, j;
    cin >> t;
    assert(t == 1);
    cin >> n >> j;
    cerr << n << " " << j << "\n";
    
    cout << "Case #1:\n";

    int num = 0;
    big divs[11];

    for (uint32_t x = 1 + (1 << (n-1)); num < j; x += 2)
    {
        if (build_sol(x, divs))
        {
            for (int i = n-1; i >= 0; i--)
            {
                cout << ((x & (1<<i)) ? "1" : "0");
            }
            
            for (int b = 2; b <= 10; b++)
            {
                cout << " " << divs[b];
            }
            cout << "\n";
            num++;
        }
    }
}
