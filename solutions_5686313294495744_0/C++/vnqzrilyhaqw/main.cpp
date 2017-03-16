#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

static const int INF = numeric_limits<int>::max();
using pii = pair<int, int>;

struct Edge { 
	int to, cap, res, rev;
	int flow() { return cap - res; };
};

struct MaxFlowList {
	vector< vector<Edge> > adj;
	
	MaxFlowList(int n){
		adj.resize(n, vector<Edge>());
	}
	
	void reset() {
		for(vector<Edge>& ve : adj) 
			for(Edge& e: ve)
				e.res = e.cap;
	}
	
	void add_edge(int u, int v, int uv, int vu) {
		int usize = adj[u].size(), vsize = adj[v].size();
		adj[u].push_back(Edge{v, uv, uv, vsize});
		adj[v].push_back(Edge{u, vu, vu, usize});
	}
	
	int bfs(int s, int t, vector<int>& depth) {
		int n = adj.size();
		depth.assign(n, -1);
		depth[s] = 0;
		queue<int> q;
		q.push(s);
		while(!q.empty()) {
			int i = q.front(); q.pop();
			int d = depth[i];
			for(auto& e: adj[i]) {
				int j = e.to;
				if(depth[j]==-1 && e.res>0) {
					depth[j] = d + 1;
					q.push(j);
				}
			}
		}
		return (depth[t]!=-1);
	}
	
	int dfs(int i, int t, vector<int>& depth, vector<int>& path) {
		if(i==t) return INF;
		int d = depth[i];
		for(auto& e: adj[i]) {
			int j = e.to;
			if(depth[j]==d+1 && e.res>0) {
				path[j] = e.rev;
				int f = dfs(j, t, depth, path);
				if(f) { return min(e.res, f); }
				path[j] = -1;
			}
		}
		return 0;
	}
	
	int solve(int s, int t) {
		int n = adj.size();
		int flow = 0;
		vector<int> depth(n, -1);
		while( bfs(s, t, depth) ) {
			while(true) {
				vector<int> path(n, -1);
				int inc = dfs(s, t, depth, path);
				if(inc) {
					flow += inc;
					for(int i=t; i!=s; ) {
						Edge& e0 = adj[i][path[i]];
						Edge& e1 = adj[e0.to][e0.rev];
						e0.res += inc;
						e1.res -= inc;
						i = e0.to;
					}
				} else {
					break;
				}			
			}
		}
		return flow;
	}
};

int flow1(int n, int na, int nb, const map<pair<int, int>, int>& edges) {
	MaxFlowList mf(na + nb + 4);
	int s0 = na + nb;
	int s1 = s0 + 1;
	int t0 = s1 + 1;
	int t1 = t0 + 1;
	for(auto& pp : edges) {
		auto& p = pp.first;
		mf.add_edge(p.first, p.second, pp.second, pp.second);
	}
	for(int i=0; i<na; ++i) {
		mf.add_edge(s1, i, 5000, 5000);
	}
	for(int i=0; i<nb; ++i) {
		mf.add_edge(t1, i+na, 1, 1);
	}
	mf.add_edge(t1, t0, nb, nb);
	mf.add_edge(s0, s1, 0, 0);
	int left = 0;
	int right = n;
	while(right>left+1) {
		int mid = (right+left)/2;
		mf.adj[s0].pop_back();
		mf.adj[s1].pop_back();
		mf.add_edge(s0, s1, mid, mid);
		mf.reset();
		int f = mf.solve(s0, t0);
		if(f==nb) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return left;
}

int flow2(int n, int na, int nb, const map<pair<int, int>, int>& edges) {
	MaxFlowList mf(na + nb + 4);
	int s0 = na + nb;
	int s1 = s0 + 1;
	int t0 = s1 + 1;
	int t1 = t0 + 1;
	for(auto& pp : edges) {
		auto& p = pp.first;
		mf.add_edge(p.first, p.second, pp.second, pp.second);
	}
	for(int i=0; i<na; ++i) {
		mf.add_edge(s1, i, 1, 1);
	}
	for(int i=0; i<nb; ++i) {
		mf.add_edge(t1, i+na, 5000, 5000);
	}
	mf.add_edge(t1, t0, 0, 0);
	mf.add_edge(s0, s1, na, na);
	int left = 0;
	int right = n;
	while(right>left+1) {
		int mid = (right+left)/2;
		mf.adj[t0].pop_back();
		mf.adj[t1].pop_back();
		mf.add_edge(t0, t1, mid, mid);
		mf.reset();
		int f = mf.solve(s0, t0);
		if(f==na) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return left;
}

int single_test() {
	int n;
	cin >> n;
	vector<string> va, vb;
	map<string, int> a, b;
	for(int i=0; i<n; ++i) {
		string sa, sb;
		cin >> sa >> sb;
		va.push_back(sa);
		vb.push_back(sb);
		if(a.find(sa)==a.end()) {
			int na = a.size();
			a[sa] = na;
		}
		if(b.find(sb)==b.end()) {
			int nb = b.size();
			b[sb] = nb;
		}
	}
	int na = a.size();
	int nb = b.size();
	map<pair<int, int>, int> edges;
	for(int i=0; i<n; ++i) {
		int ia = a[va[i]];
		int ib = b[vb[i]] + na;
		edges[pii{ia,ib}] = edges[pii{ia,ib}] + 1;
	}
	int f1 = flow1(n, na, nb, edges);
	int f2 = flow2(n, na, nb, edges);
	int res = max(f1, f2);
	res = n-1 - res;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		int res = single_test();
		cout << "Case #" << i << ": " << res << endl;
	}
	return 0;
}
