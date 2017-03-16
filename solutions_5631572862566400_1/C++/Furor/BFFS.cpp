#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX 1005

using namespace std;

int adj[MAX], path[MAX];
bool seen[MAX], c2[MAX];

int cycle_find(int v, int s, int p, int len) {
	if (seen[v]) {
		if (v == s)
			return len;
		return -1;
	}
	seen[v] = true;
	if (adj[v] != p)
		path[v] = max(path[v], len);
	cycle_find(adj[v], s, v, len + 1);
}

int main() {
	int c, t, i, j, m, n, a, b;
	scanf("%d", &t);
	for (c = 1; c <= t; c++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			path[i] = 0;
			c2[i] = false;
		}
		for (i = 0; i < n; i++) {
			scanf("%d", &a);
			adj[i] = a - 1;
		}
		int ans = 0;
		for (i = 0; i < n; i++) {
			memset(seen, false, sizeof(seen));
			int size = cycle_find(i, i, -1, 0);
			ans = max(ans, size);
			if (size == 2)
				c2[i] = true;
		}
		int c2ans = 0;
		for (i = 0; i < n; i++)
			if (c2[i])
				c2ans += path[i] + 1;
		printf("Case #%d: %d\n", c, max(ans, c2ans));
	}
	return 0;
}