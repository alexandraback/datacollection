#include <cstdio>
#include <cstdlib>

double min(double a, double b) {
    return a < b ? a : b;
}
double p[10005], ans[10005];
int a, b, r;

int main() {
    freopen("inbig", "r", stdin);
    freopen("outbig", "w", stdout);
    int cas = 1;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &a, &b);
        for (int i = 0; i < a; i++)
            scanf("%lf", &p[i]);

        r = 100;
        double nowp = 1;

        for (int i = 0; i < a; i++)
            nowp *= p[i];
        for (int i = 0; i <= a; i++)
            ans[i] = nowp * (i + i + b - a + 1);
        nowp = 1;
        for (int i = 0; i < a; i++) {
            double pp = nowp * (1 - p[i]);
            for (int j = 0; j < (a - i); j++) {
                ans[j] += pp * (j + j + b - a + 1 + b + 1);
            }
            for (int j = a - i; j <= a; j++) {
                ans[j] += pp * (j + j + b - a + 1);
            }
            nowp *= p[i];
        }

        double res = 1 + b + 1;
        for (int i = 0; i <= a; i++)
            res = min(res, ans[i]);
        printf("Case #%d: %.6lf\n", cas++, res);
    }
}