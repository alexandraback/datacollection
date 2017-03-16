#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cassert>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int INF = 1 << 28;

int dp[1111][111];
int f(int p, int step) {
    if (p > (1LL << step)) {
        return INF;
    }
    if (p == 0) {
        return INF;
    }
    while (p % 2 == 0) {
        p /= 2;
        step--;
    }
    if (step == 0) {
        return p == 1 ? 0 : INF;
    }
    int &res = dp[p][step];
    if (res != -1) {
        return res;
    }
    res = INF;
    for (int y = 0; y <= step; y++) {
        int t = step - y;
        for (int x = 0; x <= (1 << y); x++) {
            int rem = 2 * p - (1 << t) * x;
            if (rem < 0 || (rem & ((1 << y) - 1)) != 0) {
                continue;
            }
            int z = rem >> y;
            if (0 <= z && z <= (1 << t)) {
                res = min(res, 1 + f(x, y));
                res = min(res, 1 + f(z, t));
            }
        }
    }
    return res;
}

int solve(long long p, long long q) {
    long long d = __gcd(p, q);
    p /= d;
    q /= d;
    long long qq = q;
    int step = 0;
    while (qq % 2 == 0) {
        step++;
        qq /= 2;
    }
    eprintf("%lld %lld %d\n", p, q, step);
    if (qq != 1) {
        return -1;
    }
    return f(p, step);
}

int main() {
    int nt;
    assert(scanf("%d", &nt) == 1);
    memset(dp, -1, sizeof(dp));
    for (int tt = 1; tt <= nt; tt++) {
        long long p, q;
        assert(scanf("%lld/%lld", &p, &q) == 2);
        int ret = solve(p, q);
        if (ret == -1) {
            printf("Case #%d: impossible\n", tt);
        } else {
            printf("Case #%d: %d\n", tt, ret);
        }
    }
    return 0;
}
