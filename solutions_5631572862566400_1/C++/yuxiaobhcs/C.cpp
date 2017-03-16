#include<stdio.h>
#include<memory.h>
#include<vector>
using namespace std;
int T,N;
int f[1010];
int vis[1010],cir[1010],num[1010];
vector<int> g[1010];
int dfs(int u,int v,int dep) {
    int tans=dep;
    for (int i=0; i<g[u].size(); i++) {
        if (g[u][i]==v) continue;
        int tmp=dfs(g[u][i],v,dep+1);
        if (tmp>tans) tans=tmp;
    }
    return tans;
}
int main() {
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);

    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        scanf("%d",&N);
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        for (int i=1; i<=N; i++) g[i].clear();
        for (int i=1; i<=N; i++) {
            scanf("%d",&f[i]);
            g[f[i]].push_back(i);
        }
        int x,cnt=0,ans=0,ans2=0;
        for (int i=1; i<=N; i++) {
            if (!vis[i]) {
                x=i;
                while (1) {
                    vis[x]=++cnt;
                    if (vis[f[x]]>=vis[i]) {
                        int y=vis[x]-vis[f[x]]+1;
                        if (y>ans) ans=y;
                        cir[x]=y;
                        if (y==2) {
                            int cnt2=2;
                            cnt2+=dfs(x,f[x],0);
                            cnt2+=dfs(f[x],x,0);
                            ans2+=cnt2;
                        }
                        break;
                    } else if (vis[f[x]]) {
                        break;
                    }
                    x=f[x];
                }
            }
        }
        if (ans2>ans) ans=ans2;
        printf("Case #%d: %d\n",cas,ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
