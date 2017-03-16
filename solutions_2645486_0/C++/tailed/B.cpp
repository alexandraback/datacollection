#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <climits>
using namespace std;

#define REP(i, m, n) for(int i=(m); i<int(n); ++i)
#define rep(i, n) for(int i=0; i<int(n); ++i)
#define each(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back                                                                          
#define mp make_pair
#define def(a, x) __typeof(x) a = x
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> PI;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};



class MinCostFlow {
public:
	struct edge { int from, to, cost, cap, rev; };
	vector<vector<edge> > G;
	vector<int> D;
	int diff;
	MinCostFlow(size_t n) : G(n+2), D(n), diff(0) {}
	void add_demand(int v, int x) { D[v] += x; }
	void add_supply(int v, int x) { D[v] -= x; }
	void add_edge(int from, int to, int cost, int upper, int lower=0) {
		if (!(0 <= lower && lower <= upper)) cout << lower << " "<<upper << endl;
		assert(0 <= lower && lower <= upper);
		if (lower > 0) {
			diff += lower * cost;
			D[from] += lower;
			D[to] -= lower;
			upper -= lower;
		}
		if (cost < 0) {
			diff += cost * upper;
			D[from] += upper;
			D[to] -= upper;
			cost = -cost;
			swap(from, to);
		}
		G[from].push_back((edge){ from, to, cost, upper, (int)G[to].size() });
		G[to].push_back((edge){ to, from, -cost, 0, (int)G[from].size()-1 });
	}
	int run() {
		const int source = D.size(), sink = D.size()+1;
		const int V = G.size();
		int F = 0;
		rep(i, source) {
			if (D[i] < 0) add_edge(source, i, 0, -D[i]), F += -D[i];
			else if (D[i] > 0) add_edge(i, sink, 0, D[i]);
		}

		int res = 0;
		vector<int> h(V);
		while(F > 0) {
			priority_queue<PI> Q;
			vector<int> dist(V, INT_MAX);
			vector<edge*> prev(V);
			Q.push(PI(dist[source]=0, source));
			while(!Q.empty()) {
				int c = -Q.top().first, v = Q.top().second; Q.pop();
				if (c>dist[v]) continue;
				each(e, G[v]) {
					int w = e->to, d = dist[v] + e->cost + h[v] - h[w];
					if (e->cap > 0 && dist[w] > d) {
						Q.push(PI(-(dist[w]=d), w));
						prev[w] = &*e;
					}
				}
			}
			if (dist[sink] == INT_MAX) return INT_MAX;
			rep(i, V) h[i] += dist[i];

			int f = F;
			for(int v=sink; v!=source; v=prev[v]->from)
				f = min(f, prev[v]->cap);
			F -= f;
			res += f * h[sink];
			for(int v=sink; v!=source; v=prev[v]->from) {
				prev[v]->cap -= f;
				G[v][prev[v]->rev].cap += f;
			}
		}
		return res + diff;
	}
};

/* TODO use ll */
ll solve() {
	int E, R, N;
	int V[10010];
	cin >> E >> R >> N;
	if (E < R) R = E;
	rep(i, N) cin >> V[i];
	MinCostFlow mcf(N+1);
	mcf.add_supply(0, E + (N-1) * R);
	mcf.add_demand(N, E + (N-1) * R);
	mcf.add_edge(0, 1, -V[0], E, R);
	for(int i=1; i<N; i++) {
		mcf.add_edge(0, i, -V[i], E);
		mcf.add_edge(i, i+1, 0, E + i * R, (i+1) * R);
	}
	return -mcf.run();
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++)
		cout << "Case #" << t << ": " << solve() << endl;
}

