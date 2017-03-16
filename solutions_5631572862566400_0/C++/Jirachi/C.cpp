#include <bits/stdc++.h>

const int MAXN = 100001;
const int MAXM = 200001;

struct Edge{
	int node, next;
}e[MAXM];

int T, n, t, p[MAXN], h[MAXN], deg[MAXN], q[MAXN];

void addEdge(int x, int y) {
	t++; e[t] = (Edge){y, h[x]}; h[x] = t;
}

int dfs(int x, const int &rt) {
	int ret = 0;
	for (int i = h[x]; i; i = e[i].next) {
		if (e[i].node == rt) continue;
		ret = std::max(ret, dfs(e[i].node, rt));
	}
	return ret + 1;
}

int main() {
	freopen("C.in", "r", stdin);
	std::cin >> T;
	for (int cs = 1; cs <= T; cs++) {
		scanf("%d", &n);
		printf("Case #%d: ", cs);
		std::fill(h + 1, h + n + 1, t = 0);
		std::fill(deg + 1, deg + n + 1, 0);
		for (int i = 1; i <= n; i++) {
			scanf("%d", p + i);
			deg[p[i]]++;
			addEdge(p[i], i);
		}
		int left = 0, right = 0;
		for (int i = 1; i <= n; i++) {
			if (!deg[i]) {
				q[++right] = i;
			}
		}
		int answer = 0;
		while (left < right) {
			left++;
			if (!--deg[p[q[left]]]) {
				q[++right] = p[q[left]];
			}
		}
		for (int i = 1; i <= n; i++) {
			if (p[p[i]] == i) {
				answer += dfs(i, p[i]);
				//answer += dfs(p[i], i);
				deg[i] = 0;
				deg[p[i]] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (deg[i] > 0) {
				int tmp = 1;
				for (int j = p[i]; j != i; j = p[j]) {
					tmp++;
					deg[j] = 0;
				}
				answer = std::max(answer, tmp);
			}
		}
		printf("%d\n", answer);
	}
	return 0;
}
