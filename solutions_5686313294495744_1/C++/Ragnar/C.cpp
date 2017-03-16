#define HEADER_H
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i,n)	for(auto i=decltype(n)(0); i<(n); ++i)
#define all(v)		begin(v), end(v)
using namespace std;		using ull= unsigned long long;
using ll = long long;		using ld = long double;
using vi = vector<ll>;		using vvi= vector<vi>;
using vb = vector<bool>;	using ii = pair<ll,ll>;
constexpr bool LOG = true;
void Log() { if(LOG) cerr << "\n"; }
template<class T, class... S> void Log(T t, S... s){
	if(LOG) cerr << t << "\t", Log(s...);
} /* ============== END OF HEADER ============== */


using F = ll; using W = ll; // types for flow and weight/cost
struct S{
	const int v;			// neighbour
	const int r;	// index of the reverse edge
	F f;			// current flow
	const F cap;	// capacity
	const W cost;	// unit cost
	S(int v, int ri, F c, W cost = 0) :
		v(v), r(ri), f(0), cap(c), cost(cost) {}
};
struct FlowGraph : vector<vector<S>> {
	FlowGraph(size_t n) : vector<vector<S>>(n) {}
	void add_edge(int u, int v, F c, W cost = 0){ auto &t = *this;
		t[u].emplace_back(v, t[v].size(), c, cost);
		t[v].emplace_back(u, t[u].size()-1, 0, -cost);
	}
};

struct Dinic{
	FlowGraph &edges; int V,s,t;
	vi l; vector<vector<S>::iterator> its; // levels and iterators
	Dinic(FlowGraph &edges, int s, int t) :
		edges(edges), V(edges.size()), s(s), t(t), l(V,-1), its(V) {}
	ll augment(int u, F c) { // we reuse the same iterators
		if (u == t) return c;
		for(auto &i = its[u]; i != edges[u].end(); i++){
			auto &e = *i;
			if (e.cap > e.f && l[u] < l[e.v]) {
				auto d = augment(e.v, min(c, e.cap - e.f));
				if (d > 0) { e.f += d; edges[e.v][e.r].f -= d; return d; }
			}	}
		return 0;
	}
	ll run() {
		ll flow = 0, f;
		while(true) {
			fill(l.begin(), l.end(),-1); l[s]=0; // recalculate the layers
			queue<int> q; q.push(s);
			while(!q.empty()){
				auto u = q.front(); q.pop();
				for(auto &&e : edges[u]) if(e.cap > e.f && l[e.v]<0)
					l[e.v] = l[u]+1, q.push(e.v);
			}
			if (l[t] < 0) return flow;
			for (int u = 0; u < V; ++u) its[u] = edges[u].begin();
			while ((f = augment(s, 100000000)) > 0) flow += f;
		}	}
};

ll i=0;
ll get(string &x, map<string,ll> &m){
	auto it = m.lower_bound(x);
	if(it!=m.end() && it->first == x){
		return it->second;
	}
	ll r = i++;
	m.insert(it,{x,r});
	return r;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	ll TC; cin >> TC;
	for(ll tc = 1; tc<=TC; ++tc){
		cout << "Case #"<<tc<<": ";
		ll n; cin >> n;

		map<string,ll> left;
		map<string,ll> right;

		ll s = i++;
		vector<ii> edges;
		for(ll j = 0; j<n; ++j){
			string x,y; cin >> x >> y;
			ll u = get(x,left), v = get(y,right);
			edges.push_back({u,v});
		}

		ll t = i++;
		FlowGraph g(i);

		vi deg(i);
		for(auto e : edges) ++deg[e.first], ++deg[e.second];

		for(auto x : left)
			g.add_edge(s,x.second,deg[x.second]-1);
		for(auto x : right)
			g.add_edge(x.second,t,deg[x.second]-1);

		for(auto e : edges)
			g.add_edge(e.first, e.second,1);

		cout << Dinic(g,s,t).run() << "\n";

	}
	return 0;
}


