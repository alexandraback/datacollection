#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,m;
double a[111111];
long double p,ans,x;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    for (int tt=1; tt<=T; tt++)
    {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++)
            scanf("%lf",&a[i]);
        ans=(long double)(m+2);
        p=1.0;
        for (int i=1; i<=n; i++)
        {
            p*=(long double)a[i];
            x=(long double)(n-i+m-i+1)*p+(long double)(n-i+m-i+1+m+1)*(1.0-p);
            if (x<ans)
                ans=x;
        }
        printf("Case #%d: %.6lf\n",tt,double(ans));
    }
}
