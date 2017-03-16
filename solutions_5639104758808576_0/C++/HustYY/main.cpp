#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,n,ans,sum;
    char s[1111];
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%d%s",&n,s);
        ans=0;sum=s[0]-'0';
        for (int i=1;i<=n;++i)
        {
            ans=max(ans,i-sum);
            sum+=s[i]-'0';
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
