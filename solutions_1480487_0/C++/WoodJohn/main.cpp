#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t, i;
    cin >> t;
    FILE *out = fopen("out.out", "w");
    for (i = 1; i <= t; i++)
    {
        int n;
        int sum = 0;
        int j;
        int p[205];
        cin >> n;
        for (j = 0; j < n; j++)
        {
            cin >> p[j];
            sum += p[j];
        }
        double res[205];
        for (j = 0; j < n; j++)
        {
            double left = 0.0, right = (double)sum;
            double mid;
            double ret;
            while (1)
            {
                int k;
                mid = (left + right) / 2;
                double c = mid + p[j];
                double tmp = sum - mid;
                for (k = 0; k < n; k++)
                {
                    if (k == j)
                        continue;
                    if (p[k] < c)
                        tmp -= c - p[k];
                }
                if (tmp == 0)
                {
                    ret = mid;
                    break;
                }
                if (tmp < 0)
                    right = mid;
                else if (tmp > 0)
                    left = mid;
                if (right - left < 10e-8)
                {
                    ret = mid;
                    break;
                }
            }
            res[j] = ret / sum;
        }
        fprintf(out, "Case #%d: ", i);
        for (j = 0; j < n - 1; j++)
        {
            fprintf(out, "%.6f ", res[j] * 100);
        }
        fprintf(out, "%.6f\n", res[n - 1] * 100);
    }
    return 0;
}
