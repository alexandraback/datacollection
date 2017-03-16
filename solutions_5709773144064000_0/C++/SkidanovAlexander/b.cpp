#include <stdio.h>

int main() {
    int t = 1, tt;
    double X, F, C;
    for (scanf("%d", &tt); t <= tt; ++ t) {
        scanf("%lf %lf %lf", &C, &F, &X);

        double addt = 0;
        double prod = 2;
        double ans = X / prod;
        while (true) {
            double cur = addt + C / prod + X / (prod + F);
            if (cur + 1e-7 < ans) {
                addt += C / prod;
                prod += F;
                ans = cur;
            }
            else break;
        }
        printf("Case #%d: %.18lf\n", t, ans);
    }

    return 0;
}
