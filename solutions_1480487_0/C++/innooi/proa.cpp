#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int n, a[300];
double ans[300];
bool v[300];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("a.ans", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i);
        double sum = 0;
        for (int i = 1; i <= n; ++i) sum += a[i];
        memset(v, 0, sizeof (v));
        double s, p;
        int cnt;
        do {
            s = cnt = 0;
            for (int i = 1; i <= n; ++i) if (!v[i]) s += a[i], cnt++;
            p = (s + sum) / cnt;
            cnt = 0;
            for (int i = 1; i <= n; ++i) if (!v[i] && a[i] > p) cnt++, v[i] = 1;
        } while (cnt);
        printf("Case #%d:", ca);
        for (int i = 1; i <= n; ++i) if (v[i]) printf(" 0.0");
            else printf(" %.6f", (p - a[i]) / sum * 100);
        puts("");
    }
    return 0;
}