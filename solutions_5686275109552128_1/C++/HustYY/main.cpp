#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,n,p[1111],tmp,ans;
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",p+i);
        ans=1000;
        for (int i=1;i<=1000;++i)
        {
            tmp=i;
            for (int j=1;j<=n;++j) tmp+=(p[j]-1)/i;
            ans=min(ans,tmp);
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
