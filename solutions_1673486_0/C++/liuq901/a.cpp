#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        double ans=m+2,p=1;
        for (int i=1;i<=n;i++)
        {
            double x;
            scanf("%lf",&x);
            p*=x;
            double now=n-i+m-i+1+(1-p)*(m+1);
            ans=min(ans,now);
        }
        static int id=0;
        printf("Case #%d: %.10f\n",++id,ans);
    }
    return(0);
}

