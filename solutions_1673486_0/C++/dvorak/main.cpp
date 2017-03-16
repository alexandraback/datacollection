#include <cstdio>
#include <cstdlib>

double min(double a, double b) {
    return a < b ? a : b;
}
double p[5];
int a, b, r;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int cas = 1;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &a, &b);
        for (int i = 0; i < a; i++)
            scanf("%lf", &p[i]);
        double ans[4] = {};
        r = 100;
        for (int i = 0; i < (1 << a); i++) {
            double nowp = 1;
            r = 100;
            for (int j = 0; j < a; j++) {
                if (((1 << (a - 1 - j)) & i) == 0) {
                    nowp *= (1 - p[j]);
                    if (r == 100)
                        r = j;
                } else
                    nowp *= p[j];
            }

            for (int j = 0; j <= a; j++) {
                if (r >= a - j) {
                    ans[j] += nowp * (j + j + b - a + 1);
                } else {
                    ans[j] += nowp * (j + j + b - a + 1 + b + 1);
                }
            }
        }
        double res = 1 + b + 1;
        for (int i = 0; i <= a; i++)
            res = min(res, ans[i]);
        printf("Case #%d: %.6lf\n", cas++, res);
    }
}