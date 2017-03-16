#include <cstdio>

#define N 20

int n, m;
int a[N], f[1 << N];

void out(int s) {
    for (int i = 0, first = 1; i < n; ++i)
        if (s >> i & 1) {
            if (first) first = 0;
            else putchar(' ');
            printf("%d", a[i]);
        }
    puts("");
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int m = 1 << n;
    for (int st = 1; st < m; ++st) {
        f[st] = 0;
        for (int i = 0; i < n; ++i) if (st >> i & 1)
            f[st] += a[i];
    }
    for (int s1 = 1; s1 < m; ++s1) {
        int k = m - 1 - s1;
        for (int s2 = k; s2; s2 = (s2 - 1) & k)
            if (f[s1] == f[s2]) {
                out(s1);
                out(s2);
                return;
            }
    }
    puts("Impossible");
}

int main() {
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d:\n", ++cas);
        solve();
    }
    return 0;
}
