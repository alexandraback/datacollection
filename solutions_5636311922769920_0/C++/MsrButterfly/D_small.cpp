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

int main(int argc, const char *argv[]) {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    size_t t = 0;
    scanf("%zd", &t);
    for (size_t i = 0; i < t; ++i) {
        printf("Case #%zd:", i + 1);
        uint64_t k, c, s;
        scanf("%llu %llu %llu", &k, &c, &s);
        uint64_t max = int_pow(k, c);
        uint64_t step = k == 1 ? 1 : (max - 1) / (k - 1);
        for (uint64_t j = 1; j <= max; j += step) {
            printf(" %llu", j);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
