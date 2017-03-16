#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll INF = 1ULL<<60ULL;
const ll MAXN=2000+4;

struct edge {
	ll a, b, cap, flow;
};
/*
Set
dinic_numnodes: number of nodes
dinic_src: Source vertex
dinic_dest: Target vertex
Run dinic_edge.clear() and dinic_graph[i].clear() for each run
*/
ll dinic_numnodes, dinic_src, dinic_dest, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> dinic_edge;
vector<ll> dinic_graph[MAXN];
 
void add_edge (ll a, ll b, ll cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	dinic_graph[a].push_back ((ll) dinic_edge.size());
	dinic_edge.push_back (e1);
	dinic_graph[b].push_back ((ll) dinic_edge.size());
	dinic_edge.push_back (e2);
}

bool bfs() {
	ll qh=0, qt=0;
	q[qt++] = dinic_src;
	memset (d, -1, dinic_numnodes * sizeof d[0]);
	d[dinic_src] = 0;
	while (qh < qt && d[dinic_dest] == -1) {
		ll v = q[qh++];
		for (size_t i=0; i<dinic_graph[v].size(); ++i) {
			ll id = dinic_graph[v][i],
				to = dinic_edge[id].b;
			if (d[to] == -1 && dinic_edge[id].flow < dinic_edge[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[dinic_dest] != -1;
}
 
ll dfs (ll v, ll flow) {
	if (!flow)  return 0;
	if (v == dinic_dest)  return flow;
	for (; ptr[v]<(ll)dinic_graph[v].size(); ++ptr[v]) {
		ll id = dinic_graph[v][ptr[v]],
			to = dinic_edge[id].b;
		if (d[to] != d[v] + 1)  continue;
		ll pushed = dfs (to, min (flow, dinic_edge[id].cap - dinic_edge[id].flow));
		if (pushed) {
			dinic_edge[id].flow += pushed;
			dinic_edge[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
ll dinic() {
	ll flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, dinic_numnodes * sizeof ptr[0]);
		while (ll pushed = dfs (dinic_src, INF))
			flow += pushed;
	}
	return flow;
}



string as[MAXN],bs[MAXN];
ll a[MAXN],b[MAXN];
int main() {
	cout.precision(300);
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n; cin>>n;
		for (ll i=0;i<n;i++) {
			cin>>as[i]>>bs[i];
		}
		ll asz,bsz;
		{
			set<string> sta,stb;
			for (ll i=0;i<n;i++) {
				sta.insert(as[i]);
				stb.insert(bs[i]);
			}
			map<string,ll> ma,mb;
			ll idx=0;
			for (auto &w:sta) {
				ma[w]=idx; idx++;
			}
			idx=0;
			for (auto &w:stb) {
				mb[w]=idx; idx++;
			}
			for (ll i=0;i<n;i++) {
				a[i]=ma[as[i]];
				b[i]=mb[bs[i]];
			}
			asz=sta.size();
			bsz=stb.size();
		}

		ll src=asz+bsz;
		ll target=asz+bsz+1;
		dinic_numnodes=asz+bsz+2;
		dinic_src=dinic_numnodes-2;
		dinic_dest=dinic_numnodes-1;
		for (ll i=0;i<MAXN;i++) {
			dinic_graph[i].clear();
		}
		dinic_edge.clear();
		for (ll i=0;i<n;i++) {
			ll x=a[i];
			ll y=b[i]+asz;
			add_edge (x,y,1);
		}
		for (ll x=0;x<asz;x++) {
			add_edge (src,x,1);
		}
		for (ll y=asz;y<asz+bsz;y++) {
			add_edge (y,target,1);
		}
		ll flow=dinic();
		ll add=asz+bsz-2*flow;
		ll need=flow+add;
		ll final=n-need;
		cout << "Case #" << casenum << ": " << final << endl;
	}
}
