#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 100005;
double v[maxn], f[maxn];
int test, testi, n, m;

void work() {
    int i; double v, p = 1;
    scanf("%d%d", &n, &m);
    double ans = m + 2, tmp;
    for (i = 0; i < n; ++i) {
        tmp = (n - i + m - i + 1) * p + (n - i + m - i + 1 + m + 1) * (1 - p);
        if (tmp < ans) ans = tmp;
        scanf("%lf", &v); p *= v;
    }
    tmp = (m - n + 1) * p + (m - n + 1 + m + 1) * (1 - p);
    if (tmp < ans) ans = tmp;
    printf("Case #%d: %.6lf\n", testi, ans);
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &test);
    for (testi = 1; testi <= test; ++testi)
        work();
    return 0;
}
