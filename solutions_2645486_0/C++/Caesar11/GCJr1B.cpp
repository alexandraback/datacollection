#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int v[100];
int e,r,n,ans;

void dfs(int l,int cur,int sum)
{
    if (l==n+1)
    {
        ans=max(ans,sum);
        return;
    }

    for (int i=0;i<=cur;i++)
    {
        int next=cur-i+r;
        next=min(next,e);
        dfs(l+1,next,sum+i*v[l]);
    }
}

main()
{
    int t,i,ys;

    freopen("B-small-attempt0.in","r",stdin);
    freopen("Bsmall.out","w",stdout);

    scanf("%d",&t);
    ys=0;
    while (t--)
    {
        scanf("%d%d%d",&e,&r,&n);
        for (i=1;i<=n;i++)
            scanf("%d",&v[i]);
        ans=0;

        dfs(1,e,0);
        printf("Case #%d: %d\n",++ys,ans);
    }

    return 0;
}

