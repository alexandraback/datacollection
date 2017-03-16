#include <cstdio>
#include <cstring>

int digs(int x) {
    int r = 0;
    while (x) {
        r |= (1 << (x % 10));
        x /= 10;
    }
    return r;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            printf("Case #%d: INSOMNIA\n", t);
            continue;
        }
        int ag = 0;
        int k = n;
        ag = digs(k);
        while (ag != (1 << 10) - 1) {
            k = k + n;
            ag |= digs(k);
        }
        printf("Case #%d: %d\n", t, k);
    }
    return 0;
}
