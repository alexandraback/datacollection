#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a,n,t,f[105];
long long now,x,ans;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&a,&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&f[i]);
        if(a==1)
        {
            printf("Case #%d: %d\n",cas,n);
            continue;
        }
        sort(f+1,f+n+1);
        now=a;
        ans=n;
        x=0;
        for(int i=1;i<=n;i++)
        {
            if(f[i]<now)
            {
                now+=f[i];
            }
            else
            {
                while(now<=f[i])
                {
                    now+=now-1;
                    x++;
                }
                now+=f[i];
            }
            if(n-i+x<ans)ans=n-i+x;
        }
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
