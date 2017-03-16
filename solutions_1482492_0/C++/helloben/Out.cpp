#include <cstdio>
#include <math.h>
#include <algorithm>

using namespace std;

int n,m;
double dis;
struct dat
{
    double d,t;
}car[2010];

double calc(double dis,double g)
{
    return sqrt(2.0*dis/g);
}

double solve(double g)
{
    int i;
    double ans,v,tmp,f[2010];

    for (i = n-1;i>=1;i--)
        if (car[i].d>dis) n--;
    if (car[n].d>dis)
    {
        v=(car[n].d-car[n-1].d) / (car[n].t-car[n-1].t);
        car[n].t-=(car[n].d-dis) / v;
        car[n].d=dis;
    }
    for (i = 1;i<=n;i++)
    {
        f[i]=max(calc(car[i].d,g),car[i].t);
        for (int j = 1;j<i;j++)
        {
            tmp=calc(car[i].d-car[j].d,g)+f[j];
            if (tmp>f[i]) f[i]=tmp;
        }
    }
    return f[n];
}

int main()
{
    freopen("Out.in","r",stdin);
    freopen("Out.out","w",stdout);
    int t,tt,i;
    double g,ans;
    scanf("%d",&tt);
    for (t = 1;t<=tt;t++)
    {
        scanf("%lf%d%d",&dis,&n,&m);
        for (i = 1;i<=n;i++) scanf("%lf%lf",&car[i].t,&car[i].d);
        printf("Case #%d:\n",t);
        for (i = 1;i<=m;i++)
        {
            scanf("%lf",&g);
            ans=solve(g);
            printf("%.8lf\n",ans);
        }
    }
}
