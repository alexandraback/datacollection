#include<bits/stdc++.h>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define s(i) scanf("%d",&i)
#define sl(i) scanf("%ld",&i)
#define sll(i) scanf("%lld",&i)
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define NREP(i,a,b) \
for (int i = int(a); i >= int(b); i--)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 1000000000 // 2 billion
#define EPS 1e-9
#define MOD 1000000007

const int maxnodes = 100009;

int nodes = maxnodes, src, dest;
int dist[maxnodes],work[maxnodes];

struct Edge {
  int to, rev;
  int f, cap;
};

vector <Edge> g[maxnodes];

// Adds bidirectional edge
void addEdge(int s, int t, int cap ,int revcap){
  Edge a = {t, g[t].size(), 0, cap};
  Edge b = {s, g[s].size(), 0, revcap};
  g[s].push_back(a);
  g[t].push_back(b);
}

bool dinic_bfs() {
  fill(dist, dist + nodes, -1);
  dist[src] = 0;
  queue <int> qu;qu.push(src);
  while( !qu.empty() )
  {
      int u = qu.front();qu.pop();
      for(int j = 0;j < g[u].size() ;j++)
      {
          Edge &e = g[u][j];
          int v = e.to;
          if(dist[v] == -1 && e.f < e.cap)
          {
              dist[v] = dist[u] + 1;
              qu.push(v);
          }
      }
  }
  return dist[dest] >= 0;
}

int dinic_dfs(int u, int f) {
  if (u == dest)
    return f;
  for (int &i = work[u]; i < (int) g[u].size(); i++) {
    Edge &e = g[u][i];
    if (e.cap <= e.f) continue;
    int v = e.to;
    if (dist[v] == dist[u] + 1) {
      int df = dinic_dfs(v, min(f, e.cap - e.f));
      if (df > 0) {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int maxFlow(int _src, int _dest) {
  src = _src;
  dest = _dest;
  int result = 0;
  while (dinic_bfs()) {
    fill(work, work + nodes, 0);
    while (int delta = dinic_dfs(src, INF))
      result += delta;
  }
  return result;
}

int calculateIndex( string str , vector < string > k )
{
    int idx = lower_bound( k.begin() , k.end() , str ) - k.begin();
    return idx;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    int t ;
    s(t) ;
    REP( T , 1 , t )
    {
        REP( i , 0 , 2002 )
            g[i].clear();
        vector < pair < string , string > > topics;
        int n ; s(n) ;
        set < string > lhs , rhs;
        REP( i , 0 , n - 1 )
        {
            pair < string , string > a;
            cin >> a.first >> a.second ;
            lhs.insert( a.first );
            rhs.insert( a.second );
            topics.push_back( a );
        }
        vector < string > lhsafterSet , rhsafterSet;
        set < string >::iterator it = lhs.begin();
        while( it != lhs.end() )
        {
            lhsafterSet.push_back( *it );
            it++;
        }
        it = rhs.begin();
        while( it != rhs.end() )
        {
            rhsafterSet.push_back( *it );
            it++;
        }
        REP( i , 0 , lhs.size() - 1 )
        {
            addEdge( 0 , i + 1 , 1 , 0 );
        }
        REP( j , 0 , rhs.size() - 1 )
        {
            addEdge( 1001 + j , 2001 , 1 , 0 );
        }
        vii transformation;
        REP( i , 0 , topics.size() - 1 )
        {
            transformation.push_back( ii( calculateIndex( topics[i].first , lhsafterSet ) , calculateIndex( topics[i].second , rhsafterSet ) ) );
            addEdge( 1 + calculateIndex( topics[i].first , lhsafterSet ) , 1001 + calculateIndex( topics[i].second , rhsafterSet ) , 1 , 0 );
        }
        si lhsgoodNodes , rhsgoodNodes;
        set < ii > goodEdges;
        int mf = maxFlow( 0 , 2001 );
        REP( i , 1 , lhs.size() )
        {
            REP( j , 0 , g[i].size() - 1 )
            {
                if( g[i][j].f > 0 )
                {
                    lhsgoodNodes.insert( i - 1 );
                    rhsgoodNodes.insert( g[i][j].to - 1001 );
                    goodEdges.insert( ii( i - 1 , g[i][j].to - 1001 ) ) ;
                }
            }
        }
        int ans = 0 ;
        TRvii( transformation , it )
        {
            if( lhsgoodNodes.count( it -> first ) == 1 && rhsgoodNodes.count(it -> second) == 1 && goodEdges.count(ii( it -> first , it -> second ) ) == 0 )
                ans++;
        }
        printf("Case #%d: %d\n",T,ans);
    }
    return 0;
}
