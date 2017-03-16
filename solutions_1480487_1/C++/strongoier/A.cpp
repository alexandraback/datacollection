#include <cstdio>

const double EPS = 1e-6;

int a[222];

int main()
{
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; ++ k)
    {
        printf("Case #%d:", k);
        int n, s = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++ i)
        {
            scanf("%d", &a[i]);
            s += a[i];
        }
        for (int i = 1; i <= n; ++ i)
        {
            double l = 0, r = 100 + EPS;
            while (r - l > EPS)
            {
                double m = (l + r) / 2, t = a[i] + s * m / 100, p = 100 - m;
                for (int j = 1; j <= n; ++ j)
                    if (j != i && t - a[j] > EPS)
                        p -= (t - a[j]) / s * 100;
                if (p < -EPS)
                    r = m;
                else
                    l = m;
            }
            printf(" %.6lf", l);
        }
        putchar('\n');
    }
    return 0;
}
