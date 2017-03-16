#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int N;
        scanf("%d", &N);
        int s[205];
        int X = 0;
        for (int n = 0; n < N; ++n) {
            scanf("%d", s+n);
            X += s[n];
        }
        printf("Case #%d:", t);
        for (int i = 0; i < N; ++i) {
            double l = 0;
            double u = 100;
            double quota = X;
            for (int j = 0; j < N; ++j) {
                if (s[j] < s[i]) {
                    quota -= (s[i] - s[j]);
                }
            }
            if (quota < 0) {
                printf(" 0");
                continue;
            }
            while (u-l > 1e-6) {
                double m = (l+u)/2;
                // printf("%f %f %f\n", l, m, u);
                double b = s[i] + 1.0 * m / 100.0 * X;
                quota = 1.0 * X * (100 - m) / 100;
                // printf("quota: %f\n", quota);
                // printf("b: %f\n", b);
                for (int j = 0; j < N; ++j) {
                    if (s[j] < b && j != i) {
                        // printf("s[j]: %d\n", s[j]);
                        quota -= (b - s[j]);
                        if (quota < 0) {
                            break;
                        }
                    }
                }
                // printf("quota: %f\n", quota);
                if (quota < 0) {
                    u = m;
                } else {
                    l = m;
                }
                // break;
            }
            printf(" %.6lf", l);
        }
        printf("\n");
    }
}