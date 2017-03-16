#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 1001
using namespace std;

vector<int> G[MAXN];
int in_deg[MAXN];
bool visited[MAXN];

bool BFS(int u) {
	queue<int> Q;
	fill(visited, visited + MAXN, false);
	visited[u] = true;
	Q.push(u);

	while(!Q.empty()) {
		int v = Q.front();
		Q.pop();

		for(int k = 0; k < G[v].size(); ++k) {
			if(visited[G[v][k]]) {
				return true;
			} else {
				visited[G[v][k]] = true;
				Q.push(G[v][k]);
			}
		}
	}
	
	return false;
}

void init() {
	fill(in_deg, in_deg + MAXN, 0);
	for(int i = 0; i < MAXN; ++i) {
		G[i].clear();
	}
}

int main() {
	int T;

	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		int N;
		bool sol = false;
		init();

		scanf("%d", &N);
		for(int i = 1; i <= N; ++i) {
			int M;
			scanf("%d", &M);
			for(int j = 0; j < M; ++j) {
				int m;
				scanf("%d", &m);
				G[i].push_back(m);
				in_deg[m]++;
			}
		}

		for(int i = 1; i <= N && !sol; ++i) {
			if(!in_deg[i]) {
				sol |= BFS(i);
			}
		}

		printf("Case #%d: %s\n", t, sol ? "Yes" : "No");
	}

	return 0;
}
