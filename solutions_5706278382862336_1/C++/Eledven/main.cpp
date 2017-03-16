#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cassert>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int INF = 1 << 28;

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
    if (qq != 1) {
        return -1;
    }
    p -= 1;
    for (int i = 0; i < step; i++) {
        if (p < (1LL << i)) {
            return step - i;
        }
        p -= 1LL << i;
    }
    return -1;
}

int main() {
    int nt;
    assert(scanf("%d", &nt) == 1);
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
