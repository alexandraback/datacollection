#include <cstdio>

using namespace std;

double sum,s[210];
int n;

double solve(int k)
{
    double l,r,mid,key,coun;
    int i;
    l=0;r=100;
    while (r-l>1e-10)
    {
        mid=(l+r) / 2;
        key=s[k]+sum*mid / 100;coun=mid;
        for (i = 1;i<=n;i++)
        {
            if (s[i]>=key || i==k) continue;
            coun+=(key-s[i]) / sum*100;
        }
        if (coun>100) r=mid; else l=mid;
    }
    return l;
}

int main()
{
    //freopen("Safety.in","r",stdin);
    //freopen("Safety.out","w",stdout);
    int t,tt,i;
    double ans[210];
    scanf("%d",&tt);
    for (t = 1;t<=tt;t++)
    {
        scanf("%d",&n);
        for (i = 1;i<=n;i++) scanf("%lf",&s[i]);
        sum=0;
        for (i = 1;i<=n;i++) sum+=s[i];
        for (i = 1;i<=n;i++) ans[i]=solve(i);
        printf("Case #%d:",t);
        for (i = 1;i<=n;i++) printf(" %.6lf",ans[i]);
        printf("\n");
    }
}
