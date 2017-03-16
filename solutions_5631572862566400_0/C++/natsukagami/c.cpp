#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;

int N;
int nxt[1001];
int d[1001], low[1001], f[1001], top[1001], Time = 0;

stack<int> S;
vector<int> Cyc[1001];
void dfs(int v) {
	d[v] = low[v] = top[v] = ++Time;
	int u = nxt[v]; S.push(v);
	if (!d[u]) { dfs(u); low[v] = min(low[v], low[u]); }
	else if (!f[u]) low[v] = min(low[v], d[u]);
	if (low[v] == d[v]) {
		while (!f[v]) { Cyc[v].push_back(S.top()); f[S.top()] = 1; top[S.top()] = v; S.pop(); }
	}
}

vector<int> chainOf[1001];
vector<int> get_chain(int st) {
	vector<int> ans; 
	while (Cyc[top[st]].size() == 1) { ans.push_back(st); st = nxt[st]; }
	ans.push_back(st); return ans;
}

int main() {
	int T; cin >> T;
	for (int Tc = 1; Tc <= T; ++Tc) {
		cin >> N;
		for (int i = 1; i <= N; ++i) cin >> nxt[i], d[i] = low[i] = f[i] = top[i] = 0, Cyc[i].clear(), chainOf[i].clear();
		Time = 0; for (int i = 1; i <= N; ++i) if (!d[i]) dfs(i);
		for (int i = 1; i <= N; ++i) {
			vector<int> F = get_chain(i);
			if (chainOf[F.back()].size() < F.size()) chainOf[F.back()] = F;
		}
		vector<int> ans;
		for (int i = 1; i <= N; ++i) if (Cyc[i].size() > ans.size()) ans = Cyc[i];
		vector<int> build;
		for (int p = 1; p <= N; ++p) if (Cyc[p].size() == 2) {
			int u = Cyc[p][0], v = Cyc[p][1];
			for (int i = 0; i < (int)chainOf[u].size(); ++i) build.push_back(chainOf[u][i]);
			for (int i = (int)chainOf[v].size() - 1; i >= 0; --i) build.push_back(chainOf[v][i]);
		}
		if (build.size() > ans.size()) ans = build;
		printf("Case #%d: %d\n", Tc, (int)ans.size());
	} 
}