#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }

template<class FlowT>
class MaxFlow {
 public:
  MaxFlow(int n, int source, int sink):
    nvertices_(n), source_(source), sink_(sink), edges_(n), flow_(0), dist_(n), vis_(n) {
  }
  ~MaxFlow() {
    for (auto it : edges_) for (auto jt : it) delete jt;
  }

  void addEdge(int a,int b,FlowT c) {
    Edge *ab = new Edge;
    Edge *ba = new Edge;
    ab->a=a; ab->b=b; ab->cap=c; ab->flow=0; ab->rev=ba;
    ba->a=b; ba->b=a; ba->cap=0; ba->flow=0; ba->rev=ab;
    edges_[a].push_back(ab);
    edges_[b].push_back(ba);
  }

  FlowT calcFlow();

 private:
  struct Edge {
    int a,b;
    FlowT cap, flow;
    Edge *rev;
  };
  bool augmentFlow();
  void bfs();
  FlowT dfs(int x, FlowT cap);
  int nvertices_, source_, sink_;
  vector<vector<Edge*> > edges_;
  FlowT flow_;

  vector<int> dist_; // bfs output
  vector<char> vis_; // for dfs
};

template<class FlowT>
FlowT MaxFlow<FlowT>::calcFlow() {
  while(augmentFlow()) ;
  return flow_;
}

template<class FlowT>
bool MaxFlow<FlowT>::augmentFlow() {
  bfs();
  if(dist_[sink_] >= INF) return false;
  REP(i, nvertices_) vis_[i] = 0;
  vis_[source_] = 1;
  for (Edge *e : edges_[source_]) {
    if(!vis_[e->b] && dist_[e->b]==1 && e->cap > e->flow) {
      FlowT f = dfs(e->b, e->cap - e->flow);
      if (f) {
        e->flow += f;
        e->rev->flow -= f;
        flow_ += f;
        vis_[sink_] = 0;
      }
    }
  }
  return true;
}

template<class FlowT>
FlowT MaxFlow<FlowT>::dfs(int x, FlowT f) {
  vis_[x] = 1;
  if(x==sink_) return f;
  for (Edge *e : edges_[x]) {
    if(!vis_[e->b] && dist_[e->b] == dist_[x]+1 && e->cap > e->flow) {
      FlowT g = dfs(e->b, min(f, e->cap - e->flow));
      if(g) {
        e->flow += g;
        e->rev->flow -= g;
        return g;
      }
    }
  }
  return 0;
}

template<class FlowT>
void MaxFlow<FlowT>::bfs() {
  REP(i, nvertices_) dist_[i] = INF;
  vector<int> v,v2;
  v.push_back(source_);
  dist_[source_] = 0;
  while(!v.empty()) {
    while(!v.empty()) {
      int x = v.back(); v.pop_back();
      for (Edge *e : edges_[x]) {
        if(e->cap > e->flow && dist_[e->b] == INF) {
          dist_[e->b] = dist_[x]+1;
          v2.push_back(e->b);
        }
      }
    }
    v.swap(v2);
  }
}

int numA, numB;
vector<pair<int,int>> edges;

void ReadInput() {
  int n; cin >> n;
  edges.clear();
  map<string,int> dict[2];
  REP(i,n) {
    int val[2] = {};
    REP(j,2) {
      string s; cin >> s;
      if(!dict[j].count(s)) {
        int next = size(dict[j]);
        dict[j][s] = next;
      }
      val[j] = dict[j][s];
    }
    edges.push_back({val[0], val[1]});
  }
  numA = size(dict[0]);
  numB = size(dict[1]);
}

int Calc() {
  MaxFlow<int> mf(2+numA+numB, 0, 1);
  vector<int> cntA(numA, 0);
  vector<int> cntB(numB, 0);
  for (const auto &e : edges) {
    ++cntA[e.first];
    ++cntB[e.second];
    mf.addEdge(2 + e.first, 2 + numA + e.second, 1);
  }
  REP(i, numA) {
    assert(cntA[i]>0);
    mf.addEdge(0, 2 + i, cntA[i]-1);
  }
  REP(i, numB) {
    assert(cntB[i]>0);
    mf.addEdge(2+numA+i, 1, cntB[i]-1);
  }
  return mf.calcFlow();
}

int main(int argc, char **argv) {
  int ntc; cin >> ntc;
  FOR(tc,1,ntc) {
    ReadInput();
    if(argc==2 && tc!=atoi(argv[1])) continue;
    auto res = Calc();
    cout << "Case #" << tc << ": " << res << "\n";
  }
}

