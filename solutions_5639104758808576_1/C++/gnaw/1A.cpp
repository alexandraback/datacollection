#include<cstdio>
using namespace std;
int a[1024];
int main()
{
    int T,ans,sum,n;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        ans=0;
        sum=0;
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
            scanf("%1d",&a[i]);
        for(int i=0;i<=n;i++)
        {
            if(sum>=i)
            {
                sum+=a[i];
            }
            else
            {
                ans+=i-sum;
                sum=i+a[i];
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
