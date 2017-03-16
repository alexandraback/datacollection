double edge[MAX][MAX];
double path[MAX][MAX];
double dis[MAX];
int vis[MAX];
int use[MAX][MAX];
int pre[MAX];
int n;

void init(){
    mem(edge,0);
    mem(path,0);
    mem(vis,0);
    mem(use,0);
}
double prim(){
    vis[1]=1;
    dis[0]=INF;
    double ans=0;
    for(int i=1;i<=n;i++){
        dis[i]=edge[1][i];
        pre[i]=1;
    }
    while(1){//prim算法
        int x=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&dis[i]<dis[x]) x=i;
        }
        if(!x) break;
        vis[x]=1;
        ans+=dis[x];
        use[pre[x]][x]=use[x][pre[x]]=1;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&dis[i]>edge[x][i]){//计算MST
                dis[i]=edge[x][i];
                pre[i]=x;
            }
            else if(vis[i]&&i!=x){//计算x到前面每个点的路中的权值最大的边
                path[i][x]=path[x][i]=max(path[i][pre[x]],edge[pre[x]][x]);
            }
        }
    }
    return ans;
}