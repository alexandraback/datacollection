#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()


typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight=1) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}


typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool augment(const Graph& g, int u,
    vector<int>& matchTo, vector<bool>& visited) {
  if (u < 0) return true;
  FOR(e, g[u]) if (!visited[e->dst]) {
    visited[e->dst] = true;
    if (augment(g, matchTo[e->dst], matchTo, visited)) {
      matchTo[e->src] = e->dst;
      matchTo[e->dst] = e->src;
      return true;
    }
  }
  return false;
}
int bipartiteMatching(const Graph& g, int L, Edges& matching) {
  const int n = g.size();
  vector<int> matchTo(n, -1);
  int match = 0;
  REP(u, L) {
    vector<bool> visited(n);
    if (augment(g, u, matchTo, visited)) ++match;
  }
  REP(u, L) if (matchTo[u] >= 0) // make explicit matching
    matching.push_back( Edge(u, matchTo[u]) );
  return match;
}

int dp[1<<16];

vector< pair<string,string> > vs;
int dfs(int bit){
	if( dp[bit] != -1 ) return dp[bit];
	set<string> fr,bk;
	for(int i = 0 ; i < vs.size() ; i++){
		if( bit >> i & 1 ) fr.insert(vs[i].first),bk.insert(vs[i].second);
	}
	int ans = 0;
	for(int i = 0 ; i < vs.size() ; i++){
		if( !(bit>>i&1) ){
			ans = max( ans , (fr.count(vs[i].first) and bk.count(vs[i].second)) + dfs(bit|(1<<i)) );
		}
	}
	return dp[bit] = ans;
}

int flow(vector< pair<string,string> > vs){
	vector<string> u1,u2;
	for( auto s : vs ){
		u1.push_back(s.first);
		u2.push_back(s.second);
	}
	sort(u1.begin(),u1.end());
	sort(u2.begin(),u2.end());
	u1.erase(unique(u1.begin(),u1.end()),u1.end());
	u2.erase(unique(u2.begin(),u2.end()),u2.end());
	
	Graph g(u1.size()+u2.size());
	for( auto t : vs ){
		int a = lower_bound(u1.begin(),u1.end(),t.first) - u1.begin();
		int b = lower_bound(u2.begin(),u2.end(),t.second) - u2.begin() + u1.size();
		g[a].push_back(Edge(a,b));
		g[b].push_back(Edge(b,a));
	}
	Edges mat;
	bipartiteMatching(g,u1.size(),mat);
	set<string> fr,bk;
	set< pair<string,string> > usd;
	for( auto e : mat ){
		usd.insert({u1[e.src],u2[e.dst-u1.size()]});
		fr.insert(u1[e.src]);
		bk.insert(u2[e.dst-u1.size()]);
	}
	int ans = 0;
	for( auto s : vs ){
		if( !usd.count(s) ){
			if( fr.count(s.first) and bk.count(s.second) ){
				ans++;
			}
			fr.insert(s.first);
			bk.insert(s.second);
		}
	}
	return ans;
	//cout << bipartiteMatching(g,u1.size(),mat) << " " << vs.size() << " " << u1.size() << " " <<  u2.size() << "|" << dfs(0) << endl;
	
}
int solve(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin >> n;
	vs.clear();
	for(int i = 0 ; i < n ; i++){
		string a,b;
		cin >> a >> b;
		vs.push_back({a,b});
	}
	return flow(vs);
	//return dfs(0);
	
	
	
	
	
	
	
	
	
	
}
int main(){
	int T;
	cin >> T;
	int t = 1;
	while(T--){
		printf("Case #%d: ",t++);
		cout << solve() << endl;
	}
}