//Michał Glapa
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
//Make sure no overflow problems
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define ld long double
#define mini(x,y) x=min(x,y)
#define maxi(x,y) x=max(x,y)
#define CLR(a,x) memset(a,x,sizeof(a))
#define SIZE(x) ((int)x.size())
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;
const ld EPS = 10e-9;
typedef vector<int> vi;
typedef pair<int,int> pii;

///////////////////////////////////////////////////////////////
//
//
////////////////////////////////////////////////////////////////////////////////
//Dinic algorithm
//Michał Glapa 2013

//USAGE:
//FlowNetwork F = FlowNetwork(n); //where n is the number of vertices
//to add edge F.add_edge(int from, int to, int capacity)
// to get max flow  use F.compute_max_flow()
struct FlowNetwork
{
  struct Edge
  {
    int to, cross_ref;
    long long f;
    Edge(){}
    Edge(int to, int cross_ref, long long f):to(to),cross_ref(cross_ref),f(f){}
  };
  int n, source, sink;
  long long flow;
  vector<int> d,pt;
  vector<vector<Edge> > graph;
  map<pair<int,int>, int> find_edge;
  bool bfs()
  {
    for(int i=0;i<=n;i++)
    {
      d[i]=-1;
      pt[i]=0;
    }
    queue<int> q;
    q.push(source);
    d[source]=0;
    while(!q.empty())
    {
      int akt = q.front();
      q.pop();
      vector<Edge> & tmp = graph[akt];
      for(int i=0;i<(int)tmp.size();i++)
      {
        if(tmp[i].f && d[tmp[i].to]==-1)
        {
          d[tmp[i].to]=d[akt]+1;
          q.push(tmp[i].to);
        }
      }
    }
    return d[sink]!=-1;
  }
  long long dfs(int v,long long cap)
  {
    if(v==sink || cap==0)
      return cap;
    int sum=0;
    for(;pt[v]<(int)graph[v].size();pt[v]++)
    {
      Edge & nx = graph[v][pt[v]];
      if(d[nx.to]==d[v]+1 && nx.f)
      {
        int pushed = dfs(nx.to,min(cap,nx.f));
        nx.f-=pushed;
        graph[nx.to][nx.cross_ref].f+=pushed;
        sum+=pushed;
        cap-=pushed;
        if(cap==0)
          break;
      }
    }
    return sum;
  }
  static const long long INF = 1000000000000000000LL;
  FlowNetwork(int n, int source, int sink): n(n),source(source),sink(sink),flow(0)
  {
    d = pt =  vector<int> (n+1);
    graph = vector<vector<Edge> > (n+1);
  }
  long long compute_max_flow()
  {
    while(bfs())
      flow+=dfs(source,INF);
    return flow;
  }
  void add_edge(int u, int v, long long f)
  {
    if(find_edge.find(make_pair(u,v))==find_edge.end())
    {
      int us = graph[u].size(),vs = graph[v].size();
      graph[u].push_back(Edge(v,vs,f));
      graph[v].push_back(Edge(u,us,0));
      find_edge[make_pair(u,v)] = us;
      find_edge[make_pair(v,u)] = vs;
    }
    else
    {
      int uu = find_edge[make_pair(u,v)];
      graph[u][uu].f+=f;
    }
  }
  vector<int> get_cut() {
    bfs();
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (d[i] != -1)
        res.push_back(i);
    }
    return res;
  }
};
////////////////////////////////////////////////////////////////////////////////
void wtf(string s, int n, vector<int>& cnt) {
  for(auto i : s)
    cnt[i - 'A'] -= n;
}
void solve() {
  unordered_map<string, int> id[2];
  vector<pii> edges;
  int n;
  cin >> n;
  vector<int> ids  {0, n};
  REP(i, n) {
    vector<int> tmp;
    REP(j, 2) {
      string x;
      cin >> x;
      int cid = -1;
      if (id[j].count(x) == 0) {
        cid = ids[j];
        id[j][x] = ids[j]++;
      } else {
        cid = id[j][x];
      }
      tmp.pb(cid);
    }
    edges.emplace_back(tmp[0], tmp[1]);
  }
  int s = ids[1] + 1,
      t = ids[1] + 2,
      sz = ids[1] + 3;
  FlowNetwork f(sz, s, t);
  for (auto e : edges)
    f.add_edge(e.x, e.y, 1);
  FOR(i, n, ids[1] - 1) {
    f.add_edge(i, t, 1);
  }
  FOR(i, 0, ids[0] - 1) {
    f.add_edge(s, i, 1);
  }
  int l = ids[0] - 0,
      r = ids[1] - n;
  int res = n - (l +  r - f.compute_max_flow());
  cout << res << endl;

}
#undef int
int main()
#define int long long
{
  int z;
  cin >> z;
  FOR(i,1, z) {
    cout <<"Case #" <<i << ": ";
    solve();
  }

}
