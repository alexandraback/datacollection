#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[1024],b[1024];
int main()
{
    int T,maxn,ans,t;

    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            ans=max(ans,a[i]);
        }
        maxn=ans;
        for(int i=1;i<maxn;i++)
        {
            int cnt=0;
            for(int j=1;j<=n;j++)
                cnt+=(a[j]-1)/i;
            ans=min(cnt+i,ans);
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
