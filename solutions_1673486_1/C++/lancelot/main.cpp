#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
double w[100010];
double p[100010];
double sa[100010];
double sb[100010];
double b[100010];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("al.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int Cas=1; Cas<=T; Cas++)
    {
        int n,len;
        scanf("%d%d",&n,&len);
        for(int i=0; i<n; i++)
            scanf("%lf",&p[i]);
        double tmp=1.0;
        for(int i=0;i<n;i++)
        {
            w[i]=tmp*(1-p[i]);
            tmp=tmp*p[i];
        }
        sa[0]=w[0];
        sb[n-1]=w[n-1];
        for(int i=1;i<n;i++)
        {
            sa[i]=w[i]+sa[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            sb[i]=sb[i+1]+w[i];
        }
        double ans=len+2;

        b[0]=sa[n-1]*(len*2-n+2)+tmp*(len-n+1);
        ans=min(ans,b[0]);
        //printf("%lf\n",b[0]);
        for(int i=1;i<=n;i++)
        {
            if(i!=n)
            b[i]=sa[n-1-i]*(len*2-n+2)+sb[n-i]*(len-n+1)+tmp*(len-n+1)+i*2;
            else b[i]=sb[n-i]*(len-n+1)+tmp*(len-n+1)+i*2;
          //  printf("%lf\n",b[i]);
        ans=min(ans,b[i]);
        }
        printf("Case #%d: %lf\n",Cas,ans);
    }

    return 0;
}
