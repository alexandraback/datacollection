#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int val[50];
vector<int> adj[50];
struct cmp {
	bool operator ()(const pair<int, int> &a, const pair<int, int> &b) {
		return val[a.second] > val[b.second];
	}
};

void dfs(int u, int vst[], int vst2[]) {
	vst2[u] = 1;
	if (vst[u] > 1) return;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!vst2[v]) dfs(v, vst, vst2);
	}
}
bool isconnected(int start, int vst[], int vst2[], int N) {
	dfs(start, vst, vst2);
	for (int i = 0; i < N; ++i) {
		if (!vst[i] && !vst2[i]) return false;
	}
	return true;
}

void solve(int start, int vst[], int N) {
	priority_queue<pair<int, int> , vector<pair<int, int> >, cmp> pq;
	int stack[50], top = 0;
	stack[top++] = start;
	for (int i = 0; i < adj[start].size(); ++i) {
		pq.push(make_pair(start, adj[start][i]));
	}
	vst[start] = 1;
	while (!pq.empty()) {
		pair<int, int> edge = pq.top();
		pq.pop();
		if (vst[edge.first] > 1 || vst[edge.second]) continue;
		while (stack[top - 1] != edge.first) {
			vst[stack[--top]] = 2;
			int vst2[50];
			memset(vst2, 0, sizeof(vst2));
			if(!isconnected(start, vst, vst2, N)) {
				for(int i = 0; i < N; ++i) {
					if (vst[i] || vst2[i]) vst2[i] = 2;
					else vst[i] = 2;
				}
				solve(stack[top], vst2, N);
			}
		}
		stack[top++] = edge.second;
		for (int i = 0; i < adj[edge.second].size(); ++i) {
			pq.push(make_pair(edge.second, adj[edge.second][i]));
		}
		vst[edge.second] = 1;
		printf("%d", val[edge.second]);
	}
	vst[start] = 2;
}
int main(){
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		printf("Case #%d:", cas);
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; ++i) {
			scanf("%d", val + i);
			adj[i].clear();
		}
		for (int i = 0; i < M; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			--u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int start = 0;
		for (int i = 1; i < N; ++i) {
			if (val[i] < val[start]) start = i;
		}
		int vst[50];
		memset(vst, 0, sizeof(vst));
		printf(" %d", val[start]);
		solve(start, vst, N);
		puts("");
	}
	return 0;
}
