#include <cstdio>

const int MAXB=100000+10;
int A,B;
double pc[MAXB],pm[MAXB];

double min(double x,double y)
{
    if (x<y) return x;
    return y;
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int tot;
    scanf("%d",&tot);
    for (int tc=0;tc<tot;++tc)
    {
        scanf("%d%d",&A,&B);
        double ans=1000000, p=1;
        pm[0]=1;
        for (int i=0;i<A;++i)
        {
            scanf("%lf",&pc[i]);
            p*=pc[i];
            pm[i+1]=pm[i]*pc[i];
        }
        for (int i=1;i<=A;++i)
        {
            ans=min(ans, pm[A-i]*(B-A+2*i+1)+(1-pm[A-i])*(2*B-A+2*i+2));
        }
        ans=min(ans,(B-A+1)*p+(2*B-A+2)*(1-p));
        ans=min(ans,2+B);
        printf("Case #%d: %.6lf\n", tc+1, ans);
    }
    return 0;
}
