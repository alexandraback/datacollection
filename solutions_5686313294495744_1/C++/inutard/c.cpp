#include <bits/stdtr1c++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ld> pt;

// make the pairs nodes, and we want a partition.
// there are red edges and blue edges.
// we want a red edge and a blue edge out of every node
// that connects to 2 other nodes of opposite colour

// perhaps words are vertices, and *directed* edges between then are pairs...
// then an edge (a, b) can be in the set if a->c and d->b exist. i.e. if
// outdeg(a) > 0 and indeg(b) > 0

// then we want to prune as many edges as we can while keeping indeg and outdeg > 0

const int N = 2005, M = 2005, INF = 0x3f3f3f3f;
// data structures and helper functions common to all flow routines
int par[N], first[N], nxt[2*M], ep[2*M], m;
ll flo[2*M], cap[2*M], cost[2*M];
void init() { m = 0; memset(first,-1,sizeof first); memset(flo,0,sizeof flo); }
void add_edge(int a, int b, ll c=1, ll p=0) { //a,b - nodes, c, p - cap, price
  nxt[m] = first[ep[m]=a], first[ep[m]] = m, cap[m] = c, cost[m] =  p, ++m;
  nxt[m] = first[ep[m]=b], first[ep[m]] = m, cap[m] = 0, cost[m] = -p, ++m; }

// Max flow without costs, USAGE: 1) init(); 2) add edges, 3) ll flow=0; and 4)
// for (ll del=INF; del; del/=2) while (ll df=mf_update(s, t, del)) flow+=df;
// Then if you want to extract a min cut: for (int e = 0; e < m; ++e)
// if (par[ep[e]] != -1 && par[ep[e^1]] == -1) cut.push_back(e);
// If you want to recover flow paths: get set of edges with flo[e] > 0.
// E^2logC in general, E*flow on integer capacity graphs
ll mf_update(int s, int t, ll del=1) {
  ll df[N]; memset(df, 0, sizeof df); memset(par, -1, sizeof par);
  queue<int> q; q.push(s); par[s] = -2; df[s] = INF;
  while (!q.empty()) { ll cf; int u = q.front(); q.pop();
    for (int v, e = first[u]; e != -1; e = nxt[e])
      if (par[v=ep[e^1]] == -1 && (cf = cap[e]-flo[e]) >= del)
        q.push(v), par[v] = e, df[v] = min(df[u], cf); }
  if (par[t] == -1) return 0;
  for (int e, i = t; i != s; i = ep[e])
    e = par[i], flo[e] += df[t], flo[e^1] -= df[t];
  return df[t]; }
  
int ideg[N], odeg[N];
int main() {
    ios::sync_with_stdio(0);
    int T; cin >> T;
    for (int ca = 1; ca <= T; ca++) {
		int n; cin >> n;
		
		memset(ideg, 0, sizeof ideg);
		memset(odeg, 0, sizeof odeg);
		
		init();
		int c = 0;
		map<string, int> m;
		for (int i = 0; i < n; i++) {
			string x, y; cin >> x >> y;
			if (!m.count(x)) {
				//cerr << x << " " << c << endl;
				m[x] = c++;
			}
			if (!m.count(y)) {
				//cerr << y << " " << c << endl;
				m[y] = c++;
			}
			
			add_edge(m[x], m[y]);
			ideg[m[y]]++;
			odeg[m[x]]++;
		}
		
		int s = c, t = c+1;
		for (int i = 0; i < c; i++) {
			if (odeg[i]-1 > 0) {
				//cerr << s << " to " << i << " " << odeg[i]-1 << endl;
				add_edge(s, i, odeg[i]-1);
			}
			if (ideg[i]-1 > 0) {
				//cerr << i << " to " << t << " " << ideg[i]-1 << endl;
				add_edge(i, t, ideg[i]-1);
			}
		}
		
        cout << "Case #" << ca << ": ";
		
		ll flow = 0;
		for (ll del=INF; del; del/=2) while (ll df=mf_update(s, t, del)) flow+=df;
		cout << flow << endl;
    }
	return 0;
}