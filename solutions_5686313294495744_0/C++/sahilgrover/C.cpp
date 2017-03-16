// A C++ program to find maximal Bipartite matching.
#include <bits/stdc++.h>
using namespace std;

#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define X first
#define Y second
#define	mp make_pair
#define	pb push_back


// M is number of applicants and N is number of jobs
//Kuhn's algorithm
// A DFS based recursive function that returns true if a
// matching for vertex u is possible
typedef int LL;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
  LL rcap() { return cap - flow; }
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<vector<Edge *> > Lf;
  vector<int> layer;
  vector<int> Q;
  
  Dinic(int N) : N(N), G(N), Q(N) {}
  
  void AddEdge(int from, int to, int cap) {
    if (from == to) return;
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  LL BlockingFlow(int s, int t) {
    layer.clear(); layer.resize(N, -1);
    layer[s] = 0;
    Lf.clear(); Lf.resize(N);
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i]; if (e.rcap() <= 0) continue;
        if (layer[e.to] == -1) {
          layer[e.to] = layer[e.from] + 1;
          Q[tail++] = e.to;
        }
        if (layer[e.to] > layer[e.from]) {
          Lf[e.from].push_back(&e);
        }
      }
    }
    if (layer[t] == -1) return 0;

    LL totflow = 0;
    vector<Edge *> P;
    while (!Lf[s].empty()) {
      int curr = P.empty() ? s : P.back()->to;
      if (curr == t) { // Augment
        LL amt = P.front()->rcap();
        for (int i = 0; i < P.size(); ++i) {
          amt = min(amt, P[i]->rcap());
        }
        totflow += amt;
        for (int i = P.size() - 1; i >= 0; --i) {
          P[i]->flow += amt;
          G[P[i]->to][P[i]->index].flow -= amt;
          if (P[i]->rcap() <= 0) {
            Lf[P[i]->from].pop_back();
            P.resize(i);
          }
        }
      } else if (Lf[curr].empty()) { // Retreat
        P.pop_back();
        for (int i = 0; i < N; ++i)
          for (int j = 0; j < Lf[i].size(); ++j)
            if (Lf[i][j]->to == curr)
              Lf[i].erase(Lf[i].begin() + j);
      } else { // Advance
        P.push_back(Lf[curr].back());
      }
    }
    return totflow;
  }

  LL GetMaxFlow(int s, int t) {
    LL totflow = 0;
    while (LL flow = BlockingFlow(s, t))
      totflow += flow;
    // printf("%lld\n",totflow);
    // REP(i,n)  if(layer[i]!=-1)  printf("1 ");else printf("2 ");printf("\n");
    return totflow;
  }
};

vector < pair< int,int > > v;
map < string , int > M1, M2;

int main(){
	int t;scanf("%d",&t);
	REP(tt,t){
		M1.clear();
		M2.clear();
		v.clear();
		int in1=0 , in2 = 0;
		int n;scanf("%d",&n);
		REP(i,n){
			string s,r;
			cin>>s>>r;
			if(!M1.count(s))	M1[s]=in1++;
			if(!M2.count(r))	M2[r]=in2++;
			v.pb(mp(M1[s],M2[r]));
		}
		Dinic *dn = new Dinic(in1+in2+2);
		REP(i,in1)	dn->AddEdge(in1+in2,i,1);
		REP(i,in2)	dn->AddEdge(in1+i,in1+in2+1,1);
		REP(i,n){
			dn->AddEdge(v[i].X,v[i].Y+in1,1);
		}
		// printf("%d %d\n",in1,in2);
		int ans = in1+in2 - (dn->GetMaxFlow(in1+in2,in1+in2+1));
		ans = n-ans;
		printf("Case #%d: %d\n",tt+1,ans);
	}
	return 0;
}


// int main()
// {
//     // Let us create a bpGraph shown in the above example
//     bool bpGraph[M][N] = {  {0, 1, 1, 0, 0, 0},
//                         {1, 0, 0, 1, 0, 0},
//                         {0, 0, 1, 0, 0, 0},
//                         {0, 0, 1, 1, 0, 0},
//                         {0, 0, 0, 0, 0, 0},
//                         {0, 0, 0, 0, 0, 1}
//                       };

//     cout << "Maximum number of applicants that can get job is "
//          << maxBPM(bpGraph);

//     return 0;
