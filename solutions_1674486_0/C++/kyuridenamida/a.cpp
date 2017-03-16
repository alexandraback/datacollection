#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
#include <cstring>
#include <numeric>
#include <cassert>
using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SS stringstream
#define DBG1(a) rep(_X,sz(a)){printf("%d ",a[_X]);}puts("");
#define DBG2(a) rep(_X,sz(a)){rep(_Y,sz(a[_X]))printf("%d ",a[_X][_Y]);puts("");}
#define bitcount(b) __builtin_popcount(b)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

#define delete(a,n) a.erase(remove(all(a),n),a.end())
template<typename T, typename S> vector<T>& operator<<(vector<T>& a, S b) { a.push_back(b); return a; }
template<typename T> void operator>>(vector<T>& a, int b) {while(b--)if(!a.empty())a.pop_back();}
bool isprime(int n){ if(n<2)return false;  for(int i=2;i*i<=n;i++)if(n%i==0)return false;  return true;} 
ll b_pow(ll x,ll n){return n ? b_pow(x*x,n/2)*(n%2?x:1) : 1ll;}
string itos(int n){stringstream ss;ss << n;return ss.str();}

int output(int t,string s){
	printf("Case #%d: %s\n",t,s.c_str());
}
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
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

bool visit(const Graph &g, int v, vector<int> &order, vector<int> &color) {
  color[v] = 1;
  FOR(e, g[v]) {
    if (color[e->dst] == 2) continue;
    if (color[e->dst] == 1) return false;
    if (!visit(g, e->dst, order, color)) return false;
  }
  order.push_back(v); color[v] = 2;
  return true;
}
bool topologicalSort(const Graph &g, vector<int> &order) {
  int n = g.size();
  vector<int> color(n);
  REP(u, n) if (!color[u] && !visit(g, u, order, color))
    return false;
  reverse(ALL(order));
  return true;
}

int main(){
	//ios_base::sync_with_stdio(false);
	int T,t=0;
	cin >> T;
	while(T--){
		t++;
		int n;
		cin >> n;
		Graph g(n);
		for(int i = 0 ; i < n ; i++){
			int a;
			cin >> a;
			for(int j = 0 ; j < a ; j++){
				int b;
				cin >> b;
				b--;
				g[i].push_back(Edge(i,b,1));
			}
		}
		vector<int> order;
		topologicalSort(g,order);
		int ans = 0;
		//cout << order.size() << endl;
		for(int k = 0 ; k < n ; k++){
			int dp[1010] = {};
			dp[order[k]] = 1;
			for(int I = 0 ; I < n ; I++){
				int i = order[I];
				for(int j = 0 ; j < g[i].size() ; j++){
					dp[g[i][j].dst] += dp[i];
				}
			}
			for(int i = 0 ; i < n ; i++){
				if( dp[i] >= 2 ){
					ans |= 1;
				}
			}
		}
		output(t,ans?"Yes":"No");
		
	}
	
}