#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<bitset>
#define LL long long

const int MAXN=1007;
const int MAXM=0;
const long long LLINF=9000000000000000000;
const int INF=2147483647;//careful because of floyed and so on
const int MOD=1000000007;
double eps=0.00000001;

using namespace std;

int dfs_cnt;
int scc_cnt;
int sccno[MAXN];
int dfn[MAXN],low[MAXN];
stack<int>stk;
vector<int> G[MAXN];
vector<int> H[MAXN];
int T;
int n;
int ans;

void tarjan(int now){
    dfs_cnt++;
    dfn[now]=low[now]=dfs_cnt;
    stk.push(now);
    for (int i=0;i<(int)G[now].size();i++){
            int v=G[now][i];
            if (dfn[v]==0){
                    tarjan(v);
                    low[now]=min(low[now],low[v]);
            }
            else{
                    if (!sccno[v]){
                            low[now]=min(low[now],dfn[v]);
                    }
            }
    }
    if (low[now]==dfn[now]){
            int tmp=0;
            scc_cnt++;
            while (1){
                    int x=stk.top();
                    stk.pop();
                    sccno[x]=scc_cnt;
                    tmp++;
                    if (x==now) break;
            }
            ans=max(ans,tmp);
    }
}

void find_scc(int n){
    dfs_cnt=scc_cnt=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(sccno,0,sizeof(sccno));
    for (int i=1;i<=n;i++){
            if (dfn[i]==0){
                    tarjan(i);
            }
    }
}

int bfs2(int x){
    queue<int>Q;
    bool vis[MAXN];
    int d[MAXN];
    int res=0;
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    vis[x]=1;
    Q.push(x);
    while (!Q.empty()){
            int now=Q.front();
            res=max(res,d[now]);
            //printf("%d\n",now);
            Q.pop();
            for (int i=0;i<(int)H[now].size();i++){
                    int v=H[now][i];
                    if (!vis[v]){
                            d[v]=d[now]+1;
                            vis[v]=1;
                            Q.push(v);
                    }
            }
    }
    return res+1;
}

int bfs(int x,int y){
    int res1=0,res2=0;
    for (int i=0;i<(int)H[x].size();i++){
            if (H[x][i]==y) continue;
            //printf("bfs2 %d\n",H[x][i]);
            res1=max(res1,bfs2(H[x][i]));
    }
    for (int i=0;i<(int)H[y].size();i++){
            if (H[y][i]==x) continue;
            //printf("bfs2 %d\n",H[y][i]);
            res2=max(res2,bfs2(H[y][i]));
    }
    //printf("%d %d\n",res1,res2);
    return res1+res2+2;
}

void g_clear(){
    ans=0;
    for (int i=0;i<MAXN;i++){
            G[i].clear();
            H[i].clear();
    }
}

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
            g_clear();
            scanf("%d",&n);
            for (int i=1;i<=n;i++){
                    int x;
                    scanf("%d",&x);
                    G[i].push_back(x);
                    H[x].push_back(i);
            }
            find_scc(n);
            for (int i=1;i<=n;i++){
                    for (int j=1;j<=n;j++){
                            if (i!=j && G[i][0]==j && G[j][0]==i){
                                    //printf("%d %d %d\n",i,j,bfs(i,j));
                                    ans=max(ans,bfs(i,j));
                            }
                    }
            }
            printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
/*
1
10
7 8 10 10 9 2 9 6 3 3

4
4
2 3 4 1
4
3 3 4 1
4
3 3 4 3
10
7 8 10 10 9 2 9 6 3 3
*/
