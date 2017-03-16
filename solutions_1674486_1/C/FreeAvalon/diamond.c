#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXV 1005

char edge[MAXV][MAXV];
char color[MAXV];
char visited[MAXV];

int dfs(int s, int nV) {
	int u, v;
	u = s;
	color[u] = 1;
	//printf("s = %d\n", s);
	for (v = 1; v <= nV; v++) {
		if (edge[u][v] && color[v] == 1) return 1;
		if (edge[u][v] && color[v] == 0) {
			if (dfs(v, nV)) return 1;
		}
	}
	visited[u] = 1;
	return 0;
}

int containCir(int nV) {
	int u, v;
	for (u = 1; u <= nV; u++) {
		visited[u] = 0;
		color[u] = 0;
	}

	for (u = 1; u <= nV; u++) {
		if (!visited[u]) {
			for (v = 1; v <= nV; v++) color[v] = 0;
			if (dfs(u, nV)) return 1;
		}
	}

	return 0;
}

int main() {
	int T, M, N;
	int u, v;
	int iCase;
	int i, j, k;

	scanf("%d", &T);
	for (iCase = 1; iCase <= T; iCase++) {
		scanf("%d", &N);
		for (u = 1; u <= N; u++) {
			for (v = 1; v <= N; v++) {
				edge[u][v] = 0;
			}
		}
		for (u = 1; u <= N; u++) {
			scanf("%d", &M);
			for (i = 0; i < M; i++) {
				scanf("%d", &v);
				edge[u][v] = 1;
			}
		}

		printf("Case #%d: ", iCase);
		if (containCir(N)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}
