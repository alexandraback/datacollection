#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
map<string, int> l, r;
#define MAXN 1005
int ln, rn;
int g[MAXN][MAXN],match[MAXN],vst[MAXN];
int dfs(int u)
{
    for(int i = 0; i < rn; i++)
        if (!vst[i] && g[u][i])
        {
            vst[i] = 1;
            if (match[i] == -1 || dfs(match[i]) == 1)
            {
                match[i] = u;
                return 1;
            }
        }
    return 0;
}
int solve()
{
    memset(match, -1, sizeof(match));
    int ans = 0;
    for(int i = 0; i < ln; i++)
    {
        memset(vst, 0, sizeof(vst));
        ans += dfs(i);
    }
    return ans;
}
int main()
{
    int t,i,j,k,n;

    freopen("gccl.in","r",stdin);
    freopen("gccl.out","w",stdout);
    scanf("%d\n",&t);
    for(int cnt=1;cnt<=t;cnt++)
    {
        l.clear();
        r.clear();
        ln = rn = 0;
        for(i=0;i<MAXN;i++)for(j=0;j<MAXN;j++)
            g[i][j] = 0;
        scanf("%d",&n);
        string ls, rs;
        for(i=0;i<n;i++){
            cin>>ls>>rs;
            int lid, rid;
            if(l[ls] == 0)
                l[ls] = ++ln;
            if(r[rs] == 0)
                r[rs] = ++rn;
            lid = l[ls] - 1;
            rid = r[rs] - 1;
            g[lid][rid] = 1;
        }
        int mch = solve();
        //printf("")
        printf("Case #%d: %d\n", cnt, n - ln - rn + mch);

    }
    return 0;
}
