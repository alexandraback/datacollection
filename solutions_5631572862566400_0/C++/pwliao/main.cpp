#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[1005],perm[1005];
int n;
bool check(int k)
{
    for(int i=1; i<=k; i++)
        if(perm[i-1]!=f[perm[i]]&&perm[i+1]!=f[perm[i]])
            return false;
    return true;
}
int md;
bool used[1005];
bool dfs(int d)
{
    if(d==md+1)
    {
        perm[0]=perm[md];
        perm[md+1]=perm[0];
        return check(md);
    }
    for(int i=1; i<=n; i++)
    {
        if(!used[i])
        {
            used[i]=true;
            perm[d]=i;
            if(dfs(d+1)) return true;
            used[i]=false;
        }
    }
    return false;
}
int solve()
{
    for(int i=n; i>=1; i--)
    {
        memset(used,0,sizeof(used));
        md=i;
        if(dfs(1)) return i;
    }
    return 1;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("small.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cases=1; cases<=T; cases++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&f[i]);
        printf("Case #%d: %d\n",cases,solve());
    }
    return 0;
}
