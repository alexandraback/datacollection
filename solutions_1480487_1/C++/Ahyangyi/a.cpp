#include <stdio.h>

int t, n;

double pt[200], sum;
double ans[200];

int main ()
{
    scanf ("%d", &t);
    for (int i = 0; i < t; i ++)
    {
        sum = 0;
        scanf ("%d", &n);
        for (int j = 0; j < n; j ++)
        {
            scanf ("%lf", pt + j);
            sum += pt[j];
        } 

        for (int j = 0; j < n; j ++)
            pt[j] /= sum;

        for (int j = 0; j < n; j ++)
        {
            double l = 0, m, r = 1;

            while (l < r - 1e-12)
            {
                m = (l + r) / 2;

                double tot = 0;
                for (int k = 0; k < n; k ++)
                    if (k != j)
                    {
                        /*
                         * pt[j] + m = pt[k] + req
                         */
                        double req = pt[j] + m - pt[k];
                        if (req > 0)
                            tot += req;
                    }
                if (tot > 1 - m)
                    r = m;
                else
                    l = m;
            }

            ans[j] = (l + r) / 2;
        }

        printf ("Case #%d:", i + 1);
        for (int j = 0; j < n; j ++)
            printf (" %.6lf", ans[j] * 100);
        printf ("\n");
    }

    return 0;
}
