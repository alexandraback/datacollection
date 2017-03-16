#include <bits/stdc++.h>

using namespace std;

void update(long long x, int &sta) {
    for (; x; x /= 10) {
        int y = x % 10;
        sta |= (1 << y);
    }
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: ", ca);
        if (n == 0) {
            printf("INSOMNIA\n");
        } else {
            long long x = n;
            int sta = 0;
            update(x, sta);
            for (;sta != ((1 << 10) - 1);) {
                x += 1LL * n;
                update(x, sta);
            }
            printf("%lld\n", x);
        }
    }
    return 0;
}