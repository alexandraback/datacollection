#include <stdio.h>

double ans;
int a,b;
double p[100010];
int t;
double q,temp;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k;
    scanf("%d", &t);
    for (k = 1;k <= t;k++)
    {
        scanf("%d%d", &a, &b);
        for (i = 1;i <= a;i++)
            scanf("%lf", &p[i]);
        ans = b + 2;
        q = 1.0;
        for (i = 1;i <= a;i++)
        {
            q *= p[i];
            temp = (1.0 - q) * (b + 1) + a - i + b - i + 1;
            //printf("%d %.3lf\n", i, temp);
            if (temp < ans)
                ans = temp;
        }
        printf("Case #%d: %.7lf\n", k, ans);
    }
    return 0;
}
