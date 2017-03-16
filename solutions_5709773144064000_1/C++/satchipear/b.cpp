#include <stdio.h>

int main() {
    double c, f, x;
    int tn;
    scanf("%d", &tn);
    for (int cn = 1; cn <= tn; cn++) {
        scanf("%lf%lf%lf", &c, &f, &x);
        double bestNFloat = (f * x - 2 * c) / (f * c);
        // printf("%lf\n", bestNFloat);
        int bestN = (int)(bestNFloat + 1e-8);
        // printf("%d\n", bestN);
        printf("Case #%d: ", cn);
        if (bestN <= 0) {
            printf("%.8lf\n", x / 2);
        } else {
            double ans = 0;
            for (int i = 0; i < bestN; i++) {
                ans += c / (2 + i * f);
            }
            ans += x / (2 + bestN * f);
            printf("%.8lf\n", ans);
        }
    }
    return 0;
}
