#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

int n, m;
ll a[105], b[105], aa[105], bb[105], res;

void f(int x, ll t1, int y, ll t2, ll sum) {
    if (x > n || y > m) {
        res = max(res, sum);
        return;
    }
    if (aa[x] == bb[y]) {
        if (t1 < t2) f(x + 1, a[x + 1], y, t2 - t1, sum + t1);
        else f(x, t1 - t2, y + 1, b[y + 1], sum + t2);
        return;
    }
    f(x + 1, a[x + 1], y, t2, sum);
    f(x, t1, y + 1, b[y + 1], sum);
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int icase, tt = 0, i;
    scanf("%d", &icase);
    while (icase--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++) scanf("%lld%lld", &a[i], &aa[i]);
        for (i = 1; i <= m; i++) scanf("%lld%lld", &b[i], &bb[i]);
        res = 0;
        f(1, a[1], 1, b[1], 0);
        printf("Case #%d: %lld\n", ++tt, res);

    }
    return 0;
}
