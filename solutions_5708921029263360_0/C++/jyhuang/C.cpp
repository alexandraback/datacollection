// Problem C. Fashion Police
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int maxflow(const vector<vector<int> > &g, int s, int t)
{
	int i, j, u, v, n = g.size();
	vector<int> parent, visited;
	vector<vector<int> > flow = g;
	queue<int> q;

	for ( ; ; ) {
		// Use BFS to find an augmenting path
		parent.assign(n, -1);
		visited.assign(n, 0);

		q.push(s);
		visited[s] = 1;
		while (q.size() > 0) {
			u = q.front();
			q.pop();
			for (v = 0; v < n; v++)
				if (!visited[v] && flow[u][v] > 0) {
					q.push(v);
					visited[v] = 1;
					parent[v] = u;
				}
		}

		if (parent[t] < 0) break;

		// Find the flow of the found augmenting path
		int f = -1;
		for (v = t, u = parent[v]; u >= 0; v = u, u = parent[v])
			if (f < 0 || flow[u][v] < f)
				f = flow[u][v];

		for (v = t, u = parent[v]; u >= 0; v = u, u = parent[v]) {
			flow[u][v] -= f;
			flow[v][u] += f;
		}
	}

	int volume = 0;
	for (i = 0; i < n; i++)
		volume += g[s][i] - flow[s][i];

	return volume;
}

struct foo {
	int j, p, s;
};

int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		int J, P, S, K;
		scanf("%d %d %d %d", &J, &P, &S, &K);

		int total = J + P + S, m = J * P * S;
		vector<vector<int> > g(total + 2, vector<int>(total + 2, 0));
		for (int i = 0; i < J; i++) {
			g[total][i] = m;
			for (int j = 0; j < P; j++) {
				g[i][J + j] = K;
				for (int k = 0; k < S; k++)
					g[J + j][J + P + k] = K;
			}
		}
		for (int i = 0; i < S; i++)
			g[J + P + i][total + 1] = m;

		int ans = maxflow(g, total, total + 1);
		printf("Case #%d: %d\n", ti, ans);

		vector<foo> a(ans);
		for (int i = 0; i < ans; i++) {
			a[i].j = (i % J) + 1;
			a[i].p = (i % P) + 1;
			a[i].s = (i % S) + 1;
		}

		for (int i = 0; i < a.size(); i++)
			printf("%d %d %d\n", a[i].j, a[i].p, a[i].s);
	}

	return 0;
}
