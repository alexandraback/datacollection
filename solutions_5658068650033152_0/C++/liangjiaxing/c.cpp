#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int b[6][7];
int cnt;

int dx[] = {1, -1, 0, 0},
	dy[] = {0, 0, 1, -1};
	
bool valid(int x, int y){
	return x >= 0 && y >= 0 && x < 6 && y < 7;
}

void dfs(int x, int y) {
	if (b[x][y] == 0) {
		b[x][y] = 2;
		cnt++;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (valid(xx, yy)) {
				dfs(xx, yy);
			}
		}
	}
}

int main() {
	int T;
	freopen("x.txt", "r", stdin); freopen("w.txt", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		int N, M, K;
		scanf("%d%d%d", &N, &M, &K);
		if (N > M) {
			swap(N, M);
		}
		if (N <= 2) {
			printf("Case #%d: %d\n", cas, K);
			continue;
		}
		if (N == 3) {
			int ans = K;
			ans -= min((K - 2) / 3, M - 2);
			printf("Case #%d: %d\n", cas, ans);
			continue;
		}
		int ans = 100;
		for (int l = 0; l < (1 << (N * M)); l++) {
			memset(b, 0, sizeof(b));
			int num = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if ((1 << ((j - 1) * N + i - 1)) & l) {
						b[i][j] = 1;
						num++;
					}
				}
			}
			if (num >= ans) continue;
			cnt = 0;
			dfs(0, 0);
			if (42 - cnt >= K && num < ans) {
				ans = num;
				/*
				for (int i = 0; i <= 5; i++) {
					for (int j = 0; j <= 6; j++) {
						printf("%d", b[i][j]); 
					}
					puts("");
				}
				printf("%d\n", 42 - cnt);
				*/
			}
			
		}
		printf("Case #%d: %d\n", cas, ans);
	}
}
