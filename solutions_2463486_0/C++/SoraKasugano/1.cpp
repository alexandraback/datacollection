#include <cstdio>
const int maxn = 10000001;
int f[maxn];
long long root(long long x) {
    long long l = 1, r = x;
    while (l <= r) {
        long long m = l + r >> 1;
        if (m <= x / m) l = m + 1;
        else r = m - 1;
    }
    return l - 1;
}
bool ok(long long x) {
    long long y = 0;
    for (long long z = x ; z ; z /= 10) y = y * 10 + z % 10;
    for (; x || y ; x /= 10, y /= 10) if (x % 10 != y % 10) return false;
    return true;
}
int main() {
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    f[0] = 0;
    for (long long i = 1 ; i < maxn ; ++i) f[i] = f[i - 1] + int(ok(i) && ok(i * i));
    for (int c = 1 ; c <= t ; ++c) {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        long long x = root(a), y = root(b);
        if (x * x < a) ++x;
        printf("Case #%d: %d\n", c, f[y] - f[x - 1]);
    }
    return 0;
}
