#include <stdio.h>
#include <vector>
#include <string.h>
#define MAX ((1<<20)+3)
#define MAXN 203

using namespace std;

bool vis[MAX],dp[MAX];
vector<int> v[MAXN];
int cnt[MAXN],next[MAX],n,need[MAXN];

void btrack(int bt)
{
    int i,sz,j;
    if (vis[bt]) return ;
    vis[bt]=1;
    dp[bt]=0;
    if (bt==(1<<n)-1)
    {
        dp[bt]=1;
        return ;
    }
    for (i=0;i<n;i++)
    {
        if (bt&(1<<i)) continue;
        if (cnt[need[i]]==0) continue;
        cnt[need[i]]--;
        sz=v[i].size();
        for (j=0;j<sz;j++) cnt[v[i][j]]++;
        btrack(bt+(1<<i));
        for (j=0;j<sz;j++) cnt[v[i][j]]--;
        cnt[need[i]]++;
        if (dp[bt+(1<<i)])
        {
            dp[bt]=1;
            next[bt]=i;
            break;
        }
    }
}

int main()
{
    freopen("din.txt","r",stdin);
    freopen("dout.txt","w",stdout);
    int test,cas,k,i,x,j;
    scanf("%d",&test);
    for (cas=1;cas<=test;cas++)
    {
        scanf("%d%d",&k,&n);
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        for (i=0;i<k;i++)
        {
            scanf("%d",&x);
            cnt[x]++;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&need[i],&k);
            for (j=0;j<k;j++)
            {
                scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        btrack(0);
        if (dp[0])
        {
            printf("Case #%d:",cas);
            i=0;
            while (i<(1<<n)-1)
            {
                printf(" %d",next[i]+1);
                i+=(1<<(next[i]));
            }
            printf("\n");
        }
        else printf("Case #%d: IMPOSSIBLE\n",cas);
        for (i=0;i<n;i++) v[i].clear();
    }
    return 0;
}
