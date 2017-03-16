#include<cstdio>
#include<algorithm>
using namespace std;
double a[100000],s[100000];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        for (int i=0; i<m; i++)
            scanf("%lf",&a[i]);
        double kt,p=1;
        for (int i=0;i<m;i++)
            p*=a[i];
        kt=(p*(n-m+1))+(1-p)*(n-m+1+n+1);
        double ans=min(kt,n+2.0);
        s[0]=a[0];
        for (int i=1;i<m;i++)
            s[i]=s[i-1]*a[i];
        for (int i=m-1; i ;i--)
            ans=min(ans,s[i-1]*(m-i+n-i+1)+(1-s[i-1])*(m-i+n-i+1+n+1));
        printf("Case #%d: %f\n",cas,ans);
    }
    return 0;
}
