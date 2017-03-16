#include<bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
const int MOD = 1000000007;
typedef long long Int;
#define FOR(i,a,b) for(int i=(a); i<=(b);++i)
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())

template<int maxFlowSize>
class MaxFlow {
public:
 class Edge {
 public:
 int from, to, upper, flow;
 Edge(int _from, int _to,int _upper) {
 from = _from;
 to = _to;
 upper = _upper;
 flow = 0;
 }
 };

 vector<int> g[maxFlowSize];
 vector<Edge> e;

 void Clear() {
 e.clear();
 // vector<Edge> tmp; tmp.swap(e); // ONLY IF NEEDED
 for(int i=0; i<maxFlowSize; ++i)g[i].clear();
 }

 void addEdge(int from,int to,int upper) {
 Edge e1 = Edge(from, to, upper);
 Edge e2 = Edge(to, from, 0);
 g[from].push_back(e.size());e.push_back(e1);
 g[to].push_back(e.size());e.push_back(e2);
 }

 int source, sink; // be sure you set up these values

 int d[maxFlowSize];
 int q[maxFlowSize];
private: bool bfs() {
  memset(d,63,sizeof(d));
  int qh=0,qt=0;
  d[source]=0;
  q[qt++]=source;
  while(qh<qt) {
  int v=q[qh++];
  for(int i=0;i<g[v].size();++i) {
  int eid = g[v][i];
  if(e[eid].flow<e[eid].upper) {
  int to = e[eid].to;
  if(d[to]>d[v]+1) {
  d[to]=d[v]+1;
  q[qt++]=to;
  }
  }
  }
  }
  return d[sink]<maxFlowSize+1;
  }


private:
 int ptr[maxFlowSize];
 int dfs(int v,int cur) {
 if(cur==0 || v==sink)return cur;
 for(;ptr[v]<g[v].size();++ptr[v]) {
 int eid = g[v][ptr[v]];
 int to = e[eid].to;
 if(d[to]!=d[v]+1)continue;
 int add = dfs(to, min(cur, e[eid].upper-e[eid].flow));
 if(add) {
 e[eid].flow+=add;
 e[eid^1].flow-=add;
 return add;
 }
 }
 return 0;
 }
public: int getMaxFlow() {
 int ans=0;
 for(;;) {
 if(!bfs())break;
 memset(ptr,0,sizeof(ptr));
 for(;;) {
 int cur = dfs(source, 1000000000);
 ans+=cur;
 if(!cur)break;
 }
 }
 return ans;
 }
};

string s1[2222], s2[2222];
MaxFlow<4444> net;
int solve() {
    int n;cin>>n;
    map<string,int> m1, m2;
    FOR(i,0,n-1) {
        cin>>s1[i]>>s2[i];
        if(!m1.count(s1[i])) {
            int t = sz(m1);
            m1[s1[i]] = t;
        }

        if(!m2.count(s2[i])) {
            int t = sz(m2);
            m2[s2[i]] = t;
        }
    }


    net.Clear();
    net.source = 0;
    net.sink = sz(m1)+sz(m2)+1;
    FOR(i,1,sz(m1)) net.addEdge(net.source, i, 1);
    FOR(i,sz(m1)+1,sz(m1)+sz(m2)) net.addEdge(i, net.sink, 1);
    FOR(i,0,n-1) {
        net.addEdge(m1[s1[i]]+1, m2[s2[i]]+sz(m1)+1, 1);
    }

    int f = net.getMaxFlow();

    int good = f+(sz(m1)-f)+(sz(m2)-f);
    return n-good;
}


int main() {
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int tests;
    scanf("%d\n",&tests);
    FOR(idtest, 1, tests) {
        int ans = solve();
        cout<<"Case #"<<idtest<<": ";
        cout<<ans<<endl;
    }
}
