#include <stdio.h>
#include <math.h>

#define MAX 100011

int main() {
    int t, T, A, B, i, j;
    double p[MAX], correct[MAX], min, x;

    scanf("%d", &T);

    for(t = 1; t <= T; t++) {
        scanf("%d%d", &A, &B);

        correct[0] = 0.0;
        for(i = 1; i <= A; i++) {
            scanf("%lf", &p[i]);
            p[i] = log(p[i]);
            correct[i] = correct[i-1] + p[i];
            //printf("%g ", correct[i]);
        }

        min = (B + 2.0) * 1000000;
        //printf("min %lf\n", min);
        for(i = 0; i <= A; i++) {
            x = (A - i + B - i + 1) * exp(correct[i]) + (A - i + B - i + B + 2) * (1.0 - exp(correct[i]));
            //printf("x %lf\n", x);
            x = round(x * 1000000.0);
            min = min < x ? min : x;
        }

        printf("Case #%d: %.6lf\n", t, min / 1000000);
    }
}
