#include <algorithm>
#include <bitset>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

uint64_t int_pow(uint64_t base, uint64_t power) {
    uint64_t ret = 1;
    while (power--) {
        ret *= base;
    }
    return ret;
}

uint64_t calc_pos(uint64_t k, uint64_t c, uint64_t pa, uint64_t pb) {
    uint64_t base = 1;
    uint64_t ret = 0;
    while (--c) {
        base *= k;
        ret += (pa - 1) * base;
    }
    ret += pb;
    return ret;
}

int main(int argc, const char *argv[]) {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    size_t t = 0;
    scanf("%zd", &t);
    for (size_t i = 0; i < t; ++i) {
        printf("Case #%zd:", i + 1);
        uint64_t k, c, s;
        scanf("%llu %llu %llu", &k, &c, &s);
        if ((c == 1 && k > s) || c > 1 && k > 2 * s) {
            printf(" IMPOSSIBLE");
        } else if (c == 1) {
            for (uint64_t j = 1; j <= k; ++j) {
                printf(" %llu", j);
            }
        } else {
            for (uint64_t j = 1; j <= k / 2; ++j) {
                printf(" %llu", calc_pos(k, c, 2 * j - 1, 2 * j));
            }
            if (k % 2 == 1) {
                printf(" %llu", int_pow(k, c));
            }
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
