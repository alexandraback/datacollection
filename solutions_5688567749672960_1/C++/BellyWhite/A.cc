#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

inline LL reverse(LL x) {
    LL y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}
inline int len(LL x) {
    int ret = 0;
    while (x) {
        ++ret;
        x /= 10;
    }
    return ret;
}
inline LL pow10(int n) {
    LL ret = 1;
    while (n--) ret *= 10;
    return ret;
}
LL gao(LL n) {
    LL ans = 0;
    while (n > 9) {
        int l = len(n);
        if (len(n - 1) != l) {
            --n;
            --l;
            ++ans;
            if (n <= 9) break;
        }
        int k = l / 2;
        LL t = pow10(k);
        if (n % t == 0) n -= t - 1, ans += t - 1;
        LL m = reverse(n);
        if (m % t != 1) {
            ans += n % t;
            n = reverse(n - n % t + 1);
        }
        t = pow10(l - k);
        ans += n % t;
        n -= n % t;
    }
    return ans + n;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        LL n;
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", cas, gao(n));
    }
}
