#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include<cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<bitset>

#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define dbg(x) cout << __LINE__ << ' ' << #x << " = " << (x) << endl


typedef long long ll;

using namespace std;

const int N = 10010;


const int MAX_V = N+2;
const ll INF = (1LL<<60);
 
class State{
public:
  ll cost, pos;
  bool operator<(const State &s)const{
    return cost > s.cost;
  }
};
 
class Edge{
public:
  ll to, cap, cost, rev;
};
 
ll V, h[MAX_V], dist[MAX_V], prevv[MAX_V], preve[MAX_V];//頂点数、ポテンシャル、距離、前の頂点、前のエッジ
vector<Edge> G[MAX_V];
 
void addEdge(int from, int to, ll cap, ll cost){
  G[from].push_back((Edge){to, cap, cost, G[to].size()});
  G[to].push_back((Edge){from, 0, -cost, G[from].size()-1});
}
 
void clearEdge(){
  rep(i, MAX_V)G[i].clear();
}

ll min_cost_flow(int s, int t, ll f, ll PO){
  ll ret = 0;
  rep(i, V)h[i] = 0;
  h[t] = -PO;
  
  while(f>0){
    //ダイクストラ
    priority_queue<State> Q;
    rep(i, V)dist[i] = INF;
    dist[s] = 0;
    Q.push((State){0, s});
    while(!Q.empty()){
      State now = Q.top();
      Q.pop();
      int v = now.pos;
      if(dist[v] < now.cost)continue;
      rep(i, G[v].size()){
        Edge e = G[v][i];
        if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          Q.push((State){dist[e.to], e.to});
        }
      }
    }
    if(dist[t] == INF)return -1;
    //ポテンシャルの更新
    rep(v, V)h[v] += dist[v];
    //増加路に流す
    ll mini = f;
    for(int v = t;v != s; v = prevv[v]){
      mini = min(mini, G[prevv[v]][preve[v]].cap);
    }
    f -= mini;
    ret += mini * h[t];
    for(int v = t; v != s; v= prevv[v]){
      Edge &e = G[prevv[v]][preve[v]];
      e.cap -= mini;
      G[v][e.rev].cap += mini;
    }
  }
  return ret;
}


ll E, R, n;



int main(){
  int T;
  cin >> T;
  rep(tc, T){
    clearEdge();
    cout << "Case #" << tc+1<<": " << flush;
    cin >> E >> R >> n;
    V = n+2;
    int src = n;
    int sink = n+1;
    
    ll PO = 0;
    rep(i, n){
      ll v;
      if(i == 0)addEdge(src, i, E,0);
      else {
	addEdge(src, i, min(R, E), 0);
	addEdge(i-1, i, max(E-R, 0LL), 0);
      }
      
      cin>> v;
      PO = max(PO, v);
      addEdge(i, sink, E, -v);
    }
    cout << -min_cost_flow(src, sink, E+(n-1)*min(R, E), PO) << endl;
  }
  return 0;
}
