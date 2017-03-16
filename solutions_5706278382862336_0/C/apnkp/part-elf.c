#include <stdio.h>

long long gcd (long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int is_valid (long long P, long long Q)
{
    long long G = gcd (P, Q);
    P = P / G;
    Q = Q / G;

    if (P > Q)
        return 0;

    /* Check if Q is a power of 2 */
    if (Q & (Q-1))
        return 0;

    return 1;
}

int main (void)
{
    int T;
    scanf ("%d", &T);

    for (int i = 1; i <= T; i++) {
        long long P, Q;
        scanf ("%lld/%lld", &P, &Q);

        printf ("Case #%d: ", i);
        if (is_valid (P, Q)) {
            int ans = 1;
            double ratio = P / (double)Q;
            double x = 2 * ratio - 1;
            //printf ("%lf ", x);
            while (x < 0) {
                ratio *= 2;
                x = 2 * ratio - 1;
                //printf ("%lf ", x);
                ans++;
            }

            printf ("%d\n", ans);
        } else {
            printf ("impossible\n");
        }
    }

    return 0;
}
