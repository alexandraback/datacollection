#include <bits/stdc++.h>
using namespace std;

struct MaxFlow {
	struct edge { int next, rev; long long cap; };
	vector<int> dist, ptr;
	vector<vector<edge>> g;
	MaxFlow(int n) : g(n), dist(n), ptr(n) {}
	void add(int u, int v, long long c) {
		int i = g[u].size(), j = g[v].size();
		g[u].push_back({ v, j, c });
		g[v].push_back({ u, i, 0 });
	}
	long long operator()(int s, int t) {
		long long ret = 0;
		while (bfs(s, t)) while (long long f = dfs(s, t, 1e18)) ret += f;
		return ret;
	}
	bool bfs(int s, int t) {
		fill(ptr.begin(), ptr.end(), 0);
		fill(dist.begin(), dist.end(), -1);
		dist[s] = 0;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int curr = q.front(); q.pop();
			for (edge e : g[curr]) if (e.cap > 0 && dist[e.next] == -1) {
				dist[e.next] = dist[curr] + 1;
				q.push(e.next);
			}
		}
		return dist[t] >= 0;
	}
	long long dfs(int curr, int sink, long long f) {
		if (curr == sink) return f;
		while (ptr[curr] < g[curr].size()) {
			edge &e = g[curr][ptr[curr]++];
			if (e.cap > 0 && dist[curr] < dist[e.next]) {
				if (long long d = dfs(e.next, sink, min(f, e.cap))) {
					e.cap -= d;
					g[e.next][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
};

int solveSmall(int n, vector<int> u, vector<int> v) {
	n = u.size();
	int ans = 0;
	for (int i = 0; i < 1 << n; i++) {
		set<int> first, second;
		for (int j = 0; j < n; j++) if (i & 1 << j) {
			first.insert(u[j]);
			second.insert(v[j]);
		}
		bool ok = true;
		for (int j = 0; j < n; j++) if (~i & 1 << j) {
			if (first.count(u[j]) == 0 || second.count(v[j]) == 0) ok = false;
		}
		if (ok) ans = max(ans, n - __builtin_popcount(i));
	}
	return ans;
}

int solveLarge(int n, vector<int> u, vector<int> v) {
	MaxFlow mf(n * 2 + 2);
	int source = n * 2;
	int sink = n * 2 + 1;

	set<int> used;
	for (int i = 0; i < u.size(); i++) {
		used.insert(u[i]);
		used.insert(v[i] + n);
		mf.add(u[i], v[i] + n, 1);
	}
	for (int i = 0; i < n; i++) {
		mf.add(source, i, 1);
		mf.add(i + n, sink, 1);
	}

	int m = mf(source, sink);
	int ans = (int)u.size() - ((int)used.size() - m);
	return ans;
}

void solve() {
	int n;
	cin >> n;

	vector<string> us(n), vs(n);
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> us[i] >> vs[i];
		mp[us[i]] = 0;
		mp[vs[i]] = 0;
	}

	int rank = 0;
	for (auto &kv : mp) kv.second = rank++;

	vector<int> u(n), v(n);
	for (int i = 0; i < n; i++) {
		u[i] = mp[us[i]];
		v[i] = mp[vs[i]];
	}

	// int small = solveSmall(mp.size(), u, v);
	int large = solveLarge(mp.size(), u, v);
	cout << large << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		solve();
	}
}