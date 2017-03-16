#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;


llong gcd(llong a, llong b) {
    return b ? gcd(b, a % b) : a;
}

int get_lq_pow2(llong n) {
    assert(n > 0);
    llong res = 1;
    int p = 0;
    while(res <= n) {
        p++;
        res <<= 1LL;
    }
    assert(p >= 1);
    return p - 1;
}

bool is_pow2(llong n) {
    return (1LL << (llong)get_lq_pow2(n)) == n;
}

int main() {
#ifdef DEBUG
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    int T;
    scanf("%d\n", &T);
    for(int t = 1; t <= T; ++t) {
        bool is_valid = true;
        llong p, q;
        scanf("%lld/%lld\n", &p, &q);
        llong g = gcd(p, q);
        p /= g;
        q /= g;
        // printf_debug("%lld %lld, %d %d\n", p, q, get_lq_pow2(p), get_lq_pow2(q));
        if(p > q || !is_pow2(q)) {
            is_valid = false;
        }
        int ans = get_lq_pow2(q) - get_lq_pow2(p);
        assert(ans >= 0);
        printf("Case #%d: ", t);
        if(is_valid) {
            printf("%d\n", ans);
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}