#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int64_t Solve(int32_t a, int32_t b, int32_t k, int32_t idx) {
    for (int32_t i = idx; i >= 0; i--) {
        if ((1 << i) & k) {
            if (!((1 << i) & a) || !((1 << i) & b)) {
                return 1LL * (a + 1) * (b + 1);
            } else {
                return Solve((1 << i) ^ a, (1 << i) ^ b, (1 << i) ^ k, i - 1) + (1LL << i * 2) + (1LL << i) * ((b ^ (1 << i)) + 1) + ((a ^ (1 << i)) + 1) * (1LL << i);
            }
        } else if (((1 << i) & a) && ((1 << i) & b)) {
            return Solve((1 << i) ^ a, (1 << i) - 1, k, i - 1) + Solve((1 << i) - 1, (1 << i) ^ b, k, i - 1) + Solve((1 << i) - 1, (1 << i) - 1, k, i - 1);
        } else if ((1 << i) & a) {
            return Solve((1 << i) ^ a, b, k, i - 1) + Solve((1 << i) - 1, b, k, i - 1);
        } else if ((1 << i) & b) {
            return Solve(a, (1 << i) ^ b, k, i - 1) + Solve(a, (1 << i) - 1, k, i - 1);
        }
    }
    return 1;
}
int32_t main() {
    int32_t cas;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic ++) {
        int32_t a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        printf("Case #%d: %lld\n", ic, Solve(a - 1, b - 1, k - 1, 31));
    }
}
