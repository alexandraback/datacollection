#include <stdio.h>
#include <string.h>
#include <math.h>

double P[120000];
int A, B;

double calc(int stroke);

int main()
{
    int T, t;
    int i;
    double p;
    double result, tmp_result;

    scanf("%d", &T);
    for(t = 0; t < T; t++) {
        scanf("%d%d", &A, &B);
        for(i = 0; i < A; i++) {
            scanf("%lf", &P[i]);
        }

        // keep typing
        p = 1.0;
        for(i = 0; i < A; i++) {
            p *= P[i];
        }
        result = p * (B - A + 1) + (1.0 - p) * (B + B - A + 2);

        // enter
        if(result > B + 2) {
            result = (double) B + 2;
        }

        // backspace
        for(i = A; i > 0; i--) {
            tmp_result = calc(A - i);
            if(tmp_result < result)
                result = tmp_result;
        }


        printf("Case #%d: %.6lf\n", t + 1, result);
    }

    return 0;
}

double calc(int stroke)
{
    int i, n;
    double p;

    p = 1.0;
    n = A - stroke;
    for(i = 0; i < n; i++) {
        p *= P[i];
    }

    return (stroke + stroke + B - A + 1) * p +
                (stroke + stroke + B - A + 1 + B + 1) * (1.0 - p);
}

