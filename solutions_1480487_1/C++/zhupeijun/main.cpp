#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    freopen("small.in","r",stdin);
    freopen("small.out","w",stdout);
    int n,T,i,j,cn;
    double s[205],sum;
    double ans[205];
    scanf("%d",&T);
    cn = 1;
    while(T--)
    {
        scanf("%d",&n);
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&s[i]);
            sum += s[i];
        }
        for(i=0;i<n;i++)
        {
            double l,r,m;
            l = 0,r = 1;
            while(fabs(r - l) > 1e-9)
            {
                m = (l + r) / 2.0;
                double tmp = 0;
                for(j=0;j<n;j++)
                {
                    if(i == j) continue;
                    tmp += max(0.0,(m - ((s[j] - s[i]) / sum)));
                }
                if(tmp > 1.0 - m) r = m;
                else l = m;
            }
            ans[i] = l;
        }
        printf("Case #%d: ",cn);
        for(i=0;i<n;i++)
        {
            printf("%lf",ans[i] * 100);
            if(i == n-1) putchar('\n');
            else putchar(' ');
        }
        cn++;
    }
    return 0;
}
