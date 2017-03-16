#include <cstdio>
#include <cstring>
double p[1000010];
double tmp[1000010];
int main()
{
  //  freopen("in","r",stdin);
    freopen("out2","w",stdout);
    int t;
    scanf("%d",&t);
    int cas = 0;
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        for(int i=0; i<a; i++)
        scanf("%lf",&p[i]);
        tmp[0] = 1;
        for(int i=1; i<=a; i++)
        tmp[i] = tmp[i-1] * p[i-1];
        double ans = (b-a+1)*tmp[a]+(2*b-a+2)*(1-tmp[a]);
        if(ans>2+b)
        ans = 2+b;
        for(int i=0; i<=a; i++)
        if(ans>tmp[a-i]*(2*i+b-a+1)+(1-tmp[a-i])*(2*b+2*i+2-a))
        ans = tmp[a-i]*(2*i+b-a+1)+(1-tmp[a-i])*(2*b+2*i+2-a);
        printf("Case #%d: %.6lf\n",++cas,ans);
    }
    return 0;
}
