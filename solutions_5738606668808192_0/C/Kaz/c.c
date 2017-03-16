#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// small:
#define N 16
#define J 50

// large:
//#define N 32
//#define J 500

#define N_HIGHBIT (1 << (N-1))

const static uint8_t PRIMES[] = {
    // no jamcoin is a multiple of 2 in any base
    3, 5, 7, 11, 13, 17, 19, 23, 29, 31 // ...
};

uint8_t find_factor(uint64_t x) {
    #pragma unroll // constant modulus optimizations
    for (int pr = 0; pr < sizeof(PRIMES) / sizeof(PRIMES[0]); pr++) {
        if (x % PRIMES[pr] == 0)
            return PRIMES[pr];
    }
    return 0;
}

uint64_t try_coin(uint32_t num, uint8_t *factors) {
    uint64_t x; // numeric value of jamcoin in base
    #pragma unroll // multiplication by constant optimizations
    for (int base = 2; base <= 10; base++) {
        if (base == 2) {
            x = num;
        } else {
            x = 0;
            uint32_t n = num;
            uint64_t pval = 1;
            for (bool bit; bit = n & 1, n > 0; n >>= 1) {
                if (bit) {
                    x += pval;
                }
                pval *= base;
            }
        }
        uint8_t factor = find_factor(x);
        if (!factor)
            return 0;
        factors[base-2] = factor;
    }
    return x;
}

int main() {
    printf("Case #1:\n");
    uint8_t factors[9];
    for (int coingen=0, coins=0; coins<50; coingen++) {
        uint32_t n = ((coingen << 1) + 1) | N_HIGHBIT;
        uint64_t x = try_coin(n, factors);
        if (x) {
            printf("%lu %hd %hd %hd %hd %hd %hd %hd %hd %hd\n", x,
                (short)factors[0], (short)factors[1], (short)factors[2],
                (short)factors[3], (short)factors[4], (short)factors[5],
                (short)factors[6], (short)factors[7], (short)factors[8]);
            coins++;
        }
    }
}
