#include<stdio.h>

int s[300];
int t, n, i, j, k, cases, x;
double a, b, c, y;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &t);
    for (cases = 1; cases <= t; ++cases)
    {
        printf("Case #%d:", cases);
        scanf("%d", &n);
        x = 0;
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &s[i]);
            x += s[i];
        }
        for (i = 0; i < n; ++i)
        {
            a = s[i];
            b = s[i] + x;
            while (b - a > 1e-10)
            {
                c = (a + b) / 2;
                y = (c - s[i]) / x;
                for (j = 0; j < n; ++j)
                    if (j != i && s[j] < c)
                        y += (c - s[j]) / x;
                if (y > 1 - 1e-10)
                    b = c;
                else
                    a = c;
            }
            printf(" %.6f", (a - s[i]) * 100 / x + 1e-7);
        }
        printf("\n");
    }
    return 0;
}