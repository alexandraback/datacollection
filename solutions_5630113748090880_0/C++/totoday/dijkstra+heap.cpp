struct Edge{
    int v,next,c;
}edge[MAXN];

struct Node{
    int id,val;
    bool operator<(const Node &a)const{
        return val>a.val;
    }
}x;

int head[MAX];
int dis[MAX];
int vis[MAX];
int tot;

void init(){
    mem(head,-1);
    mem(dis,INF);
    mem(vis,0);
    tot=0;
}

void add_edge(int a,int b,int c){
    edge[tot]=(Edge){b,head[a],c};
    head[a]=tot++;
    edge[tot]=(Edge){a,head[b],c};
    head[b]=tot++;
}

int dijkstra(int s,int t){
    priority_queue<Node> q;
    x=(Node){s,0};
    dis[s]=0;
    q.push(x);
    while(!q.empty()){
        x=q.top();
        q.pop();
        int u=x.id;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(!vis[v]&&dis[v]>dis[u]+edge[i].c){
                dis[v]=dis[u]+edge[i].c;
                q.push((Node){v,dis[v]});
            }
        }
    }
    return dis[t];
}