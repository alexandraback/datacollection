#include <map>
#include <string>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
const int maxn = 2222;
const int maxm = 22222;
struct edge {
	int v, cap;
	edge() {}
	edge(int v, int c): v(v), cap(c) {}
}es[maxm];
vector<int> adj[maxn];
int S, T, R, N;
int dis[maxn], cur[maxn];
int addEdge(int u, int v, int c) {
	es[R] = edge(v, c);
	adj[u].push_back(R++);
	es[R] = edge(u, 0);
	adj[v].push_back(R++);
}
int dinicDFS(int u, int maxflow) {
	if (u == T) return maxflow;
	for (int i = cur[u]; i < adj[u].size(); ++i) {
		cur[u] = i;
		edge& e = es[adj[u][i]];
		if (e.cap < 1 || dis[e.v] != dis[u] + 1) continue;
		int flow = dinicDFS(e.v, min(maxflow, e.cap));
		if (flow) {
			e.cap -= flow;
			es[adj[u][i] ^ 1].cap += flow;
			return flow;
		}
	}
	return 0;
}
bool dinicBFS() {
	memset(dis, 0x3f, sizeof dis); dis[S] = 0;
	queue<int> q; q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); ++i) {
			edge& e = es[adj[u][i]];
			if (e.cap < 1 || dis[e.v] < oo) continue;
			dis[e.v] = dis[u] + 1;
			q.push(e.v);
		}
	}
	return dis[T] < oo;
}
int dinic() {
	int res = 0, flow;
	while (dinicBFS()) {
		memset(cur, 0, sizeof cur);
		while (flow = dinicDFS(S, oo))
			res += flow;
	}
	return res;
}
void solve() {
	int n, m = 0; cin >> n;
	map<string, int> h;
	int id = 0, deg[2005], tots = 0, tott = 0;
	for (int i = 0; i < 2222; ++i) adj[i].clear();
	memset(deg, 0, sizeof deg);
	vector<pair<int, int>> inp;
	for (int i = 0; i < n; ++i) {
		string s, t;
		cin >> s >> t;
		s += '1'; t += '2';
		if (h.find(s) == h.end()) {
			h[s] = id++;
			tots ++;
		}
		if (h.find(t) == h.end()) {
			h[t] = id++;
			tott ++;
		}
		addEdge(h[s], h[t], 1);
		deg[h[s]] --, deg[h[t]] ++;
	}
	int sp = id++;
	int tp = id++;
	for (int i = 0; i < id - 2; ++i) {
		if (deg[i] < 0) {
			addEdge(sp, i, 1);
		} else if (deg[i] > 0){
			addEdge(i, tp, 1);
		}
	}
	S = sp;
	T = tp;
	R = 0;
	// addEdge(S, sp, max(tots, tott));
	// addEdge(tp, T, max(tots, tott));
	printf("%d\n", n - dinic());
}
int main() {
	// freopen("in", "r", stdin);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}
