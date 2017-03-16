#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const long long inf = 1LL<<60;
#define foreach(it,o) for(__typeof((o).begin()) it = (o).begin(); it != (o).end(); ++it)

struct edge{
  int src,dst;
  long long cost;
  edge(){src=-1,dst=-1,cost=inf;}
  edge(int src, int dst, long long cost):src(src), dst(dst),cost(cost){}
  bool operator>(const edge &t)const{
    return cost != t.cost ? cost > t.cost : src != t.src ? src > t.src : dst > t.dst;
  }
};

typedef vector<edge> edges;
typedef vector<edges> graph;


bool solve(graph &g, int st, int kth){
  // const int n = g.size();
  // const int st = g.size()-1;
  // const int gl = g.size()-2;
  // long long h[n+1];
  vector<long long> A[g.size()];

  /*
  // calc potential
  for(int i = 0; i <= n; ++i) h[i] = 0;
  for(int k = 0; k <= n; ++k){
    for(int i = 0; i < n; ++i){
      foreach(e,g[i]){
        if(h[e->dst] > h[e->src] + e->cost ){
          h[e->dst] = h[e->src] + e->cost;
          if( k == n ) return make_pair(-1,-1);
        }
      }
    }
  }

  // refrect potential
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < (int)g[i].size(); ++j){
      g[i][j].cost += h[g[i][j].src] - h[g[i][j].dst];
    }
  }
  */

  // Johnson
  priority_queue<edge,vector<edge>,greater<edge> > Q;
  Q.push(edge(st,st,0));
  
  while(!Q.empty()){
    edge e = Q.top(); Q.pop();
    //cout << e.src << ' ' << e.dst << ' ' << e.cost << endl;
    if( (int)A[e.dst].size() >= kth ) continue;
    A[e.dst].push_back( e.cost );
    foreach(f,g[e.dst]){
      Q.push(edge(f->src,f->dst,f->cost+e.cost));
    }
  }

  for(int i = 0; i < (int)g.size(); ++i){
    // cout << st << ' ' << i << ' ' << A[i].size() << endl;
    if( A[i].size()>=2 ) return true;
  }
  return false;

  // return A[gl].size();
  /*
  // recover
  long long ret = 0;
  for(int i = 0; i < min(kth,(int)A[gl].size()); ++i){
    ret += A[gl][i] + h[gl] - h[st];
  }
  */
  // return make_pair(A[gl].size(),ret);
}

int main()
{
  int T;
  cin >> T;
  for(int tc=1;tc<=T;++tc){
    int N;
    cin >> N;
    graph g(N);
    for(int i = 0; i < N; ++i){
      int m;
      cin >> m;
      for(int j = 0; j < m; ++j){
        int d;
        cin >> d;
        --d;
        g[i].push_back(edge(i,d,1));
      }
    }

    /*
    for(int i = 0; i < N; ++i){
      g[N].push_back(edge(N,i,1));
    }
    */
    bool res = false;
    for(int i = 0; i < N; ++i){
      if( solve(g,i,2) ){
        res = true;
      }
    }

    cout << "Case #" <<tc << ": " << (res?"Yes":"No") << endl;
      
  }
  return 0;
}
