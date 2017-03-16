#include <iostream>
#include <stdio.h>
using namespace std;

int a, b;
double p[100000];
double dMin;

int two[4] = {1, 2, 4, 8};

bool bittest(int a, int bit)
{
    return a & (two[bit]);
}

int main()
{
    int t, k = 1;
    cin >> t;
    FILE *out = fopen("out.out", "w");
    while (t--)
    {
        dMin = 99999999.0;
        cin >> a >> b;
        int i;
        for (i = 0; i < a; i++)
        {
            cin >> p[i];
        }
        int m2 = 1;
        for (i = 0; i < a; i++)
        {
            m2 *= 2;
        }
        double sum;
        int kk;
        for (kk = 0; kk <= a + 1; kk++)
        {
            sum = 0.0;
            for (i = 0; i < m2; i++)
            {
                int j, firstwrong = -1;
                double pp = 1.0;
                for (j = 0; j < a; j++)
                {
                    if (bittest(i, j))
                        pp *= p[j];
                    else
                    {
                        pp *= (1 - p[j]);
                        if (firstwrong == -1)
                            firstwrong = j;
                    }
                }
                if (kk == a + 1)
                {
                    sum += pp * (b + 2);
                }
                else
                {
                    int tmp = b - a + 1;
                    if (firstwrong != -1 && a - kk - 1 >= firstwrong)
                        tmp += b + 1;
                    tmp += kk * 2;
                    sum += pp * tmp;
                }
            }
            if (sum < dMin)
                dMin = sum;
        }
        fprintf(out, "Case #%d: %.6f\n", k, dMin);
        k++;
    }
    return 0;
}
