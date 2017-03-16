#include <cstdio>
#include <cstring>

int main() {
    int t;
    long long r, paint, ret;

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%lld%lld", &r, &paint);
        for (ret = 0; paint >= 2 * r + 4 * ret + 1; ) {
            paint -= (2 * r + 4 * ret + 1);
            ret++;
        }
        printf("Case #%d: %lld\n", cas, ret);
    }

    return 0;
}
