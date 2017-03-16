#define _GLIBCXX_DEBUG
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long Weight;
const Weight INF=1LL << 30;

struct Edge{
  int src,dst;
  Weight weight,cap; // weightが辺のコストを表す
  int rev; // 逆辺の番号
  Edge(int src,int dst,Weight weight=0,Weight cap=0,int rev=-1):
    src(src),dst(dst),weight(weight),cap(cap),rev(rev)
  {}
};

struct Node:public vector<Edge>{};
bool operator<(const Edge &a,const Edge &b){
        return a.weight<b.weight;
}
bool operator>(const Edge &a,const Edge &b){return b<a;}

typedef vector<Node> Graph;

typedef vector<vector<Weight> > Matrix;

//srcからdstへ向かう容量cap,コストcostの辺をグラフに追加する
void add_edge(Graph &G,int src,int dst,Weight cap,Weight cost){
  G[src].push_back(Edge(src,dst,cost,cap,G[dst].size()));
  G[dst].push_back(Edge(dst,src,-cost,0,G[src].size()-1));
}

// sからtへの流量fの最小費用流を求める
// 流せない場合は-1を返す
// 流量がdoubleの場合は誤差死に注意
Weight min_cost_flow(Graph &G,int s,int t,Weight f){
  typedef pair<Weight,int> P;
  Weight res=0;
  int V=G.size();
  vector<Weight> h(V,0);
  vector<int> prevv(V);
  vector<int> preve(V);
  if(s==t)return 0;
  bool start=true;
  while(f>0){
    vector<Weight> dist(V,INF);
    if(start){
      bool update=true;
      dist[s]=0;
      while(update){
        update=false;
        REP(v,V){
          if(dist[v]==INF)continue;
          REP(i,G[v].size()){
            Edge &e=G[v][i];
            if(e.cap>0&&dist[e.dst]>dist[v]+e.weight){
              dist[e.dst]=dist[v]+e.weight;
              prevv[e.dst]=v;
              preve[e.dst]=i;
              update=true;
            }
          }
        }
      }
      start=0;
    }else{
      priority_queue<P,vector<P>,greater<P> > que;
      dist[s]=0;
      que.push(P(0,s));
      while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(dist[v]<p.first)continue;
        for(int i=0;i<(int)G[v].size();i++){
          Edge &e=G[v][i];
          if(e.cap>0&&dist[e.dst]>dist[v]+e.weight+h[v]-h[e.dst]){
            dist[e.dst]=dist[v]+e.weight+h[v]-h[e.dst];
            prevv[e.dst]=v;
            preve[e.dst]=i;
            que.push(P(dist[e.dst],e.dst));
          }
        }
      }
    }
    if(dist[t]==INF){
      return -1;
    }
    for(int v=0;v<V;v++)h[v]+=dist[v];

    Weight d=f;
    for(int v=t;v!=s;v=prevv[v]){
      d=min(d,G[prevv[v]][preve[v]].cap);
    }
    f-=d;
    res+=d*h[t];
    for(int v=t;v!=s;v=prevv[v]){
      Edge &e=G[prevv[v]][preve[v]];
      e.cap-=d;
      G[v][e.rev].cap+=d;
    }
  }
  return res;
}
int main() {
  int T;
  cin >> T;
  for(int caze = 1; caze <= T; caze++) {
    int N;
    cin >> N;
    string x[N], y[N];
    vector<string> xs, ys;
    for(int i = 0; i <N; i++) {
      cin >> x[i] >> y[i];
      xs.push_back(x[i]);
      ys.push_back(y[i]);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    Graph G(xs.size() * 2 + ys.size() * 2 + 2);
    int src = xs.size() * 2 + ys.size() * 2;
    int dst = src + 1;
    const long B = -1000000;
    for(int i = 0; i < xs.size(); i++) {
      add_edge(G, src, i, INF, 0);
      add_edge(G, i, i + xs.size(), 1, B);
      add_edge(G, i, i + xs.size(), INF, 0);
    }
    for(int i = 0; i < ys.size(); i++) {
      add_edge(G, xs.size() * 2 + ys.size() + i, dst, INF, 0);
      add_edge(G, xs.size() * 2 + i, xs.size() * 2 + ys.size() + i, INF, 0);
      add_edge(G, xs.size() * 2 + i, xs.size() * 2 + ys.size() + i, 1, B);
    }
    for(int i = 0; i <N; i++) {
      int xi = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin();
      int yi = lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin();
      add_edge(G, xs.size() + xi, xs.size() * 2 + yi, 1, 1);
    }
    add_edge(G, src, dst, N, 0);
    cout << "Case #" << caze << ": " << N - (min_cost_flow(G, src, dst, N) - B * (xs.size() + ys.size())) << endl;
  }
}
