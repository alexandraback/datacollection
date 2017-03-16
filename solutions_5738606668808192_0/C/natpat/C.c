#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX 10000
#define N 16
#define J 50

void printBase2(uint64_t n)
{
    uint64_t one = 1;
    uint64_t mask;
    for(int i = 63; i >= 0; i--)
    {
        mask = one << (i);
        if(mask & n)
            printf("1");
        else if(mask < n)
            printf("0");
    }
}
    

uint64_t ipow(uint64_t base, uint64_t exp)
{
    uint64_t result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

uint64_t findDivisior(uint64_t a, uint64_t primes[MAX], uint64_t trivial) {
    uint64_t sqr = (uint64_t)(sqrt(a));
    for(uint64_t i = 0; i < MAX; i++)
    {
        if(primes[i] == trivial) continue;
        if(primes[i] > sqr) return 0;
        if(a % primes[i] == 0)
            return primes[i];
    }
    return 0;
}

int main ()
{
    printf("Case #1:\n");
    uint64_t max = MAX;
    uint64_t primes[max];
    uint64_t n_primes = 0;
    uint64_t i;

    for (i = 2; n_primes < max; i++) {
        uint64_t j;

        for (j = 0; j < n_primes; j++) {
            if (i % primes[j] == 0) {
                goto not_prime;
            }
        }
        primes[n_primes] = i;
        n_primes++;

        not_prime:
        ;
    }

    int coinsFound = 0;
    for(uint64_t num = 0; num < (2 << N-2); num++)
    {
        uint64_t divisors[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
        int foundAll = 1;
        for(int b = 2; b <= 10; b++)
        {
            uint64_t check = ipow(b, N-1) + 1;
            uint64_t mask = 1;
            for(int i = 0; i < N-2; i++)
            {
                if(mask > num)
                    break;
                if(mask & num) {
                    check += ipow(b, i + 1);
                }
                mask = mask << 1;
            }
            /*if(b == 2)
            {
                printBase2(check);
                printf("\n");
            }*/

            //printf("%" PRIu64 "\n", check);
            uint64_t divisor = findDivisior(check, primes, b);
            //printf("%" PRIu64 "\n", divisor);
            if(divisor == 0)
            {
                foundAll = 0;
                break;
            }
            divisors[b-2] = divisor;
        }
        if(foundAll)
        {
            printBase2((num<<1) + ((uint64_t)(1)<<N-1) + (uint64_t)1);
            for(int i = 0; i < 9; i++)
                printf(" %" PRIu64, divisors[i]);
            printf("\n");
            coinsFound++;
        }
        if(coinsFound == J)
        {
            return 0;
        }
    }

    return 0;
}

