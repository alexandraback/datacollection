#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 100010
int T;
int m,n;
double p[N];
double a[N];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("outa.txt","w",stdout);
    cin>>T;
    for (int ttt=1;ttt<=T;ttt++)
    {
        cin>>n>>m;
        for (int k=1;k<=n;k++)
            scanf("%lf",&p[k]);
        a[0]=1;
        for (int k=1;k<=n;k++)
            a[k]=a[k-1]*p[k];
        double ans=1e8;
        for (int k=1;k<=n;k++)
        {
            double ans0=0;
            double temp1,temp2,temp;
            temp1=a[n-k]*(2*k+m-n+1);
            temp2=(1-a[n-k])*(2*k+m-n+2+m);
            ans0=temp1+temp2;
            if (ans0<ans)
               ans=ans0;
        }
        double ans0;
        ans0=a[n]*(m-n+1)+(1-a[n])*(m-n+1+m+1);
        if (ans0<ans)
            ans=ans0;
        if (m+2<ans) ans=m+2;
        printf("Case #%d: %.6lf\n",ttt,ans);
    }
    return 0;
}
