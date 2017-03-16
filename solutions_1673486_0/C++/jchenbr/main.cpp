#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=100000;
double f[N+5],a[N+5];
int n,m;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0,out","w",stdout);
    int total,cc=0;
    cin>>total;
    while (total--)
    {
        scanf("%d %d",&n,&m);
        f[0]=1.0;
        for (int i=1;i<=n;i++)scanf("%lf",a+i),f[i]=a[i]*f[i-1];
        double ans=m+2;

        for (int i=n;i>=0;i--)
        {
            double tmp=(n-i)+(m-i) + (1-f[i])*(m+1) +1;
            ans=min(ans,  tmp);
            //printf("{%d,%lf}\n",i,tmp);
        }
        
        printf("Case #%d: %lf\n",++cc,ans);
    }
    return 0;
}