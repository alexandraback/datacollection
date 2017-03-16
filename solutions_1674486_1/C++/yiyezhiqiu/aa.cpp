#include<iostream>
#include<cstdio>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 1009
#define maxm 100009

struct edge{
    int v;
    int next;
};

int start[maxn];
edge e[maxm];
int deg[maxn];
int n;
int nn;
int vis[maxn][maxn];

void init(){
    nn = 0;
    memset(vis,0,sizeof(vis));
    memset(deg,0,sizeof(deg));
    memset(start,-1,sizeof(start));
}

void addedge(int u,int v){
    e[nn].v = v;
    e[nn].next = start[u];
    start[u] = nn++;
}

bool bfs(){
    queue<edge> que;
    for(int i=1;i<=n;i++){
        edge tmp;
        if(deg[i]==0){
            tmp.v = i;
            tmp.next = i;
            vis[i][i] = 1;
            que.push(tmp);
        }
        
    }
    while(!que.empty()){
        edge tmp = que.front();
        int u = tmp.v;
        int flag = tmp.next;
        que.pop();
        for(int i=start[u];i!=-1;i=e[i].next){
            int v = e[i].v;
            if(!vis[v][flag]){
                vis[v][flag] = 1;
                edge tt;
                tt.v = v;
                tt.next = flag;
                que.push(tt);
            }
            else return true;
        }
    }
    return false;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int cas = 1;cas<=T;cas++){
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++){
            int num;
            scanf("%d",&num);
            for(int j=0;j<num;j++){
                int v;
                scanf("%d",&v);
                deg[i]++;
                addedge(v,i);
            }
        }
        int flag = bfs();
        printf("Case #%d: ",cas);
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
