#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX_V 2222
const int inf = 1<<21;

struct edge { int to,cap,rev; };
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int f,int t,int cap)
{
  G[f].push_back((edge){t,cap,(int)G[t].size()});
  G[t].push_back((edge){f,0,(int)G[f].size()-1});
}

 void bfs(int s)
{
  memset(level,-1,sizeof(level));
  queue<int> q;
  level[s] = 0;
  q.push(s);
  while( !q.empty() ) {
    int v = q.front(); q.pop();
    for( int i = 0; i < int(G[v].size()); i++ ) {
      edge& e = G[v][i];
      if( e.cap > 0 && level[e.to] < 0 ) {
        level[e.to] = level[v]+1;
        q.push(e.to);
      }
    }
  }
}

int dfs(int v,int t,int f)
{
  if( v == t ) return f;
  for( int &i = iter[v]; i < int(G[v].size()); i++ ) {
    edge& e = G[v][i];
    if( e.cap > 0 && level[v] < level[e.to] ) {
      int d  = dfs(e.to,t,min(f,e.cap));
      if( d > 0 ) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t)
{
  int flow = 0;
  for(;;) {
    bfs(s);
    if( level[t] < 0 ) return flow;
    memset(iter,0,sizeof(iter));
    int f;
    while( (f = dfs(s,t,inf)) > 0 ) {
      flow += f;
    }
  }
}

int main(void)
{
  int T,ttt;
  int n;
  double a[1111],b[1111];
  scanf("%d",&T);
  for( ttt = 1; ttt <= T; ttt++ ) {
    printf("Case #%d: ",ttt);
    for( int i = 0; i < MAX_V; i++ ) G[i].clear();
    scanf("%d",&n);
    for( int i = 0; i < n; i++ ) scanf("%lf",a+i);
    for( int i = 0; i < n; i++ ) scanf("%lf",b+i);
    for( int i = 0; i < n; i++ ) {
      add_edge(0,i+1,1);
    }
    for( int i = 0; i < n; i++ ) {
      for( int j = 0; j < n; j++ ) {
        if( a[i] > b[j] ) add_edge(i+1,n+j+1,1);
      }
    }
    for( int i = 0; i < n; i++ ) {
      add_edge(n+i+1,MAX_V-1,1);
    }
    int res1 = max_flow(0,MAX_V-1);
    for( int i = 0; i < MAX_V; i++ ) G[i].clear();
    for( int i = 0; i < n; i++ ) {
      add_edge(i+1,0,1);
    }
    for( int i = 0; i < n; i++ ) {
      for( int j = 0; j < n; j++ ) {
        if( a[i] < b[j] ) add_edge(n+j+1,i+1,1);
      }
    }
    for( int i = 0; i < n; i++ ) {
      add_edge(MAX_V-1,n+i+1,1);
    }
    int res2 = max_flow(MAX_V-1,0);
    printf("%d %d\n",res1,n-res2);
  }
  return 0;
}
