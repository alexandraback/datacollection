#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

using ull = unsigned long long;

int a, b, k, l;

int max_bit(int i) {
    int r = 0;
    while ((i >> r) !=  0) {
        r++;
    }
    return r;
}

int set_bits(int x) {
    int r = 0;
    while (x != 0) {
        if (x & 1) r++;
        x = x >> 1;
    }
    return r;
}

int main() {
    int tcc;
    scanf("%d", &tcc);
    for (int tc = 1; tc <= tcc; tc++) {
        scanf("%d%d%d", &a, &b, &k);
        ull r = 0;
        // l = max_bit(b);
        //int m = 1 << (max_bit(a) - l);
        for (int j = 0; j < a; j++) {
            for (int m = 0; m < b; m++) {
                if ((m & j) < k) r++;
            }
        }
        printf("Case #%d: %llu\n", tc, r);
    }
    return 0;
}
