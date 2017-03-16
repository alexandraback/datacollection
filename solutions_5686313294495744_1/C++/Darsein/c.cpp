#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(a) (a).begin(),(a).end()
#define INIT(a) memset((a),0,sizeof(a))
#define fs first
#define sc second
#define pb push_back
#define sz size() 
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1e9;

struct edge{
  int from,to,cost,cap,rev;
  edge(int a,int b,int c,int d,int e)
    :from(a),to(b),cost(c),cap(d),rev(e){}
};

struct dinic{
  int n;
  vector< vector<edge> > graph;
  vi level,iter;

  dinic(int a=0):n(a){graph.resize(a);}

  void AddEdge(int s,int g,int c,int p){
    graph[s].pb( edge(s,g,c,p,graph[g].sz) );
    graph[g].pb( edge(g,s,-c,0,graph[s].sz-1) );
  }

  void DeleteEdge(int s, int g){
    int id = -1, rev = -1;
    rep(e,graph[s].sz){
      if(graph[s][e].to == g){
	id = e; rev = graph[s][e].rev;
      }
    }
    if(id<0)return;

    swap(graph[s][id],graph[s].back());
    swap(graph[g][rev],graph[g].back());
    graph[s][id].rev = rev;
    graph[g][rev].rev = id;
    graph[s].pop_back(); graph[g].pop_back();
  }

  void bfs(int s){
    level = vi(n,-1);
    level[s] = 0;
    queue<int> q; q.push(s);
    while(q.sz){
      int v = q.front(); q.pop();
      for(edge e: graph[v]){
	if(e.cap > 0 && level[e.to] < 0){
	  level[e.to] = level[v] + 1;
	  q.push(e.to);
	}
      }
    }
  }
  
  int dfs(int v, int t, int f){
    if(v==t)return f;
    for(int &i = iter[v];i<(int)graph[v].sz;i++){
      edge &e = graph[v][i];
      if(e.cap > 0 && level[v] < level[e.to]){
	int d = dfs(e.to,t,min(f,e.cap));
	if(d > 0){
	  e.cap -= d;
	  graph[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }
  
  int max_flow(int s, int t){
    int res = 0;
    for(;;){
      bfs(s);
      if(level[t]<0)return res;
      iter = vi(n,0);
      int f;
      while((f=dfs(s,t,INF))>0)res += f;
    }
  }
};


int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    int n; cin >> n;

    map<string,int> f,s;
    int a=0, b=0;
    vector<int> aa(n), bb(n);
    rep(i,n){
      string x,y;
      cin >> x >> y;
      if(f.count(x) == 0) f[x] = a++;
      if(s.count(y) == 0) s[y] = b++;
      aa[i] = f[x]; bb[i] = s[y];
    }

    int v = a+b+2;
    dinic d(v);
    rep(i,a) d.AddEdge(0,i+1,0,1);
    rep(i,b) d.AddEdge(a+1+i,v-1,0,1);
    rep(i,n) d.AddEdge(aa[i]+1,a+1+bb[i],0,1);

    cout << "Case #" << casenum << ": ";
    cout << n - (a+b - d.max_flow(0,v-1)) << endl;
  }
}
