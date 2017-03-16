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
typedef pair<ll, ll> PI;
const ll dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const ll MAX = 1e17;
class MinCostFlow {
public:
	struct edge { ll from, to, cost, cap, rev; };
	vector<vector<edge> > G;
	vector<ll> D;
	ll diff;
	MinCostFlow(size_t n) : G(n+2), D(n), diff(0) {}
	void add_demand(ll v, ll x) { D[v] += x; }
	void add_supply(ll v, ll x) { D[v] -= x; }
	void add_edge(ll from, ll to, ll cost, ll upper, ll lower=0) {
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
		G[from].push_back((edge){ from, to, cost, upper, (ll)G[to].size() });
		G[to].push_back((edge){ to, from, -cost, 0, (ll)G[from].size()-1 });
	}
	ll run() {
		const ll source = D.size(), sink = D.size()+1;
		const ll V = G.size();
		ll F = 0;
		rep(i, source) {
			if (D[i] < 0) add_edge(source, i, 0, -D[i]), F += -D[i];
			else if (D[i] > 0) add_edge(i, sink, 0, D[i]);
		}

		ll res = 0;
		vector<ll> h(V);
		while(F > 0) {
			priority_queue<PI> Q;
			vector<ll> dist(V, MAX);
			vector<edge*> prev(V);
			Q.push(PI(dist[source]=0, source));
			while(!Q.empty()) {
				ll c = -Q.top().first, v = Q.top().second; Q.pop();
				if (c>dist[v]) continue;
				each(e, G[v]) {
					ll w = e->to, d = dist[v] + e->cost + h[v] - h[w];
					if (e->cap > 0 && dist[w] > d) {
						Q.push(PI(-(dist[w]=d), w));
						prev[w] = &*e;
					}
				}
			}
			if (dist[sink] == MAX) return MAX;
			rep(i, V) h[i] += dist[i];

			ll f = F;
			for(ll v=sink; v!=source; v=prev[v]->from)
				f = min(f, prev[v]->cap);
			F -= f;
			res += f * h[sink];
			for(ll v=sink; v!=source; v=prev[v]->from) {
				prev[v]->cap -= f;
				G[v][prev[v]->rev].cap += f;
			}
		}
		return res + diff;
	}
};

/* TODO use ll */
ll solve() {
	ll E, R, N;
	ll V[10010];
	cin >> E >> R >> N;
	if (E < R) R = E;
	rep(i, N) cin >> V[i];
	MinCostFlow mcf(N+1);
	mcf.add_supply(0, E + (N-1) * R);
	mcf.add_demand(N, E + (N-1) * R);
	mcf.add_edge(0, 1, -V[0], E, R);
	for(ll i=1; i<N; i++) {
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

