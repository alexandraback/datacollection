#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

int t,n,m,k,f[20],maxn,x,i,j,g[20];
bool ans,flag;
set<int> S;

void dfs(int pos)
{
    if(ans)return;
    if(pos==n)
    {
        S.clear();
        for(i=0;i<maxn;i++)
        {
            x=1;
            for(j=0;j<n;j++)
                if(i&(1<<j))x=x*f[j];
            S.insert(x);
        }
        flag=1;
        for(i=0;i<k;i++)
            if(S.find(g[i])==S.end())flag=0;
        if(flag)
        {
            ans=1;
            for(i=0;i<n;i++)
                printf("%d",f[i]);
            puts("");
        }
        return;
    }
    for(f[pos]=2;f[pos]<=m;f[pos]++)
        dfs(pos+1);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ans=0;
    scanf("%d",&t);
    puts("Case #1:");
    scanf("%d%d%d%d",&t,&n,&m,&k);
    maxn=1<<n;
    while(t--)
    {
        for(i=0;i<k;i++)
            scanf("%d",&g[i]);
        ans=0;
        dfs(0);
    }
    return 0;
}
