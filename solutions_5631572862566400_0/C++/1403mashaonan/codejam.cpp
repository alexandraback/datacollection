#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#pragma comment(linker,"/STACK:102400000,102400000")

using namespace std;
#define   MAX           1005
#define   MAXN          1000005
#define   maxnode       105
#define   sigma_size    2
#define   lson          l,m,rt<<1
#define   rson          m+1,r,rt<<1|1
#define   lrt           rt<<1
#define   rrt           rt<<1|1
#define   middle        int m=(r+l)>>1
#define   LL            long long
#define   ull           unsigned long long
#define   mem(x,v)      memset(x,v,sizeof(x))
#define   lowbit(x)     (x&-x)
#define   pii           pair<int,int>
#define   bits(a)       __builtin_popcount(a)
#define   mk            make_pair
#define   limit         10000

//const int    prime = 999983;
const int    INF   = 0x3f3f3f3f;
const LL     INFF  = 0x3f3f;
const double pi    = acos(-1.0);
const double inf   = 1e18;
const double eps   = 1e-9;
const LL     mod   = 1e9+7;
const ull    mxx   = 1333331;

/*****************************************************/
inline void RI(int &x) {
      char c;
      while((c=getchar())<'0' || c>'9');
      x=c-'0';
      while((c=getchar())>='0' && c<='9') x=(x<<3)+(x<<1)+c-'0';
}
/*****************************************************/

struct Edge{
    int v,next;
}edge[MAX];
int head[MAX];
int tot;
int vis[MAX];
int viss[MAX];
int ans;
int cnt[MAX];
int im[MAX];
void init(){
    mem(head,-1);
    mem(vis,0);
    mem(viss,0);
    mem(cnt,0);
    mem(im,0);
    tot=0;
    ans=0;
}

void add_edge(int a,int b){
    edge[tot]=(Edge){b,head[a]};
    head[a]=tot++;
}

int dfs1(int u,int fa,int d){
    vis[u]=1;
    int maxn=0;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(!vis[v]&&!im[v]){
            maxn=max(maxn,dfs1(v,u,d+1));
        }
    }
    return maxn+1;
}

void dfs(int u,int fa,int d){
    vis[u]=d;
    viss[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(!vis[v]) dfs(v,u,d+1);
        else {
            ans=max(ans,vis[u]-vis[v]+1);
        }
    }
    vis[u]=0;
}

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,kase=0;
    cin>>t;
    while(t--){
        kase++;
        int n;
        cin>>n;
        init();
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            add_edge(a,i);
            cnt[i]=a;
        }
        for(int i=1;i<=n;i++){
            if(cnt[cnt[i]]==i){
                im[i]=1;
                //cout<<i;
            }
        }
        printf("Case #%d: ",kase);
        int ret=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&im[i]){
                ret+=dfs1(i,-1,1);
            }
        }
        //cout<<ret<<endl;
        mem(vis,0);
        for(int i=1;i<=n;i++){
            if(!viss[i]){
                dfs(i,-1,1);
            }
        }
        cout<<max(ans,ret)<<endl;
    }
    return 0;
}




