#include <cstdio>
using namespace std;
void solve(unsigned n, unsigned j) {
    unsigned limit = 10000;

    unsigned count = 0;
    for(unsigned i = (1 << (n - 1)) | 1; count < j; i += 2) {
        unsigned long long proof[10 - 2 + 1];
        for(unsigned base = 2; base <= 10; base++) {
            for(unsigned long long test = 2; test < limit; test++) {
                unsigned long long num = 0, power = 1;
                bool big = false;
                for(unsigned copy_i = i; copy_i; copy_i >>= 1) {
                    if(power > test)
                        power %= test, big = true;
                    if(copy_i & 1)
                        num += power;
                    power *= base;
                }
                if(num <= test && !big)
                    break;
                if(num % test == 0) {
                    proof[base - 2] = test;
                    goto is_composite;
                }
            }
            goto not_jamcoin;
is_composite: ;
        }
        count++;
        for(unsigned k = 0; k < n; k++)
            putchar('0' + ((i >> (n - 1 - k)) & 1));
        for(unsigned base = 2; base <= 10; base++)
            printf(" %llu", proof[base - 2]);
        printf("\n");
not_jamcoin: ;
    }
}
int main() {
    unsigned t;
    scanf("%u\n", &t);
    for(unsigned i = 1; i <= t; i++) {
        unsigned n, j;
        scanf("%u %u", &n, &j);

        printf("Case #%u:\n", i);
        solve(n, j);
    }
}

