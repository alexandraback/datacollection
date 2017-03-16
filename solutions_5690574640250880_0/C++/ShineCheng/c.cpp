#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int vis[60][60][3600];
char graph[60][60];

bool check(int c, int r, int m) {
	//printf("check(%d,%d,%d)\n", r, c, m);
	if (r <= 1 || c <= 1) return false;
	if (m < 0) return false;
	if (vis[min(r,c)][max(r,c)][m]) return false; 
	vis[min(r,c)][max(r,c)][m] = true; 

	if (m == 0) {
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				graph[i][j] = '.';
			}
		}
		//printf("check(%d,%d,%d)\n", r, c, m);
		//puts("m=0 true");
		return true;
	}

	if (check(c-1,r,m-r)) {
		for (int i = 1; i <= r; i++) {
			graph[i][c] = '*';
		}
		//printf("check(%d,%d,%d)\n", r, c, m);
		//puts("m-r true");
		return true;
	}
	if (check(c,r-1,m-c)) {
		for (int i = 1; i <= c; i++) {
			graph[r][i] = '*';
		}
		//printf("check(%d,%d,%d)\n", r, c, m);
		//puts("m-c true");
		return true;
	}
	if (r-2 > 0 && c-2 > 0) {
		if ((r-2)*(c-2) >= m) {
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					graph[i][j] = '.';
				}
			}
			for (int i = r; i > 2; i--) {
				for (int j = c; j > 2; j--) {
					if (m) {
						graph[i][j] = '*';
						m--;
					} else {
						graph[i][j] = '.';
					}
				}
			}
			//printf("check(%d,%d,%d)\n", r, c, m);
			//puts("buman true");
			return true;
		}
	}
	return false;
}

int main(){ 
	int t;
	scanf("%d", &t);
	int cas = 1;
	while (t--) {
		int r, c, m;
		scanf("%d%d%d", &r, &c, &m);
		//printf("===%d,%d,%d\n", r, c, m);
		printf("Case #%d:\n", cas++);
		if (r == 1) {
			for (int i = 0; i < c-1; i++) {
				if (m) {
					printf("*");
					m--;
				} else {
					printf(".");
				}
			}
			printf("c\n");
			continue;
		}

		if (c == 1) {
			for (int i = 0; i < r-1; i++) {
				if (m) {
					printf("*\n");
					m--;
				} else {
					printf(".\n");
				}
			}
			printf("c\n");
			continue;
		}
		if (m == r*c-1) {
			printf("c");
			for (int i = 2; i <= c; i++) printf("*");
			puts("");
			for (int i = 2; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					printf("*");
				}puts("");
			}
			continue;
		}

		memset(vis, 0, sizeof(vis));
		memset(graph, 0, sizeof(graph));

		if (!check(c,r,m)) puts("Impossible");
		else {
			graph[1][1] = 'c';
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					printf("%c", graph[i][j]);
				} puts("");
			}
		}
	}
	return 0;
}

