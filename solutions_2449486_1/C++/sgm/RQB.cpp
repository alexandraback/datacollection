#include <stdio.h>

int T;
int N, M;
int a[105][105];

bool check(int x, int y) {
	bool good_i = true;
	for(int i = 0; i < N; i++) {
		if(a[i][y] > a[x][y]) {
			good_i = false;
			break;
		}
	}
	bool good_j = true;
	for(int j = 0; j < M; j++) {
		if(a[x][j] > a[x][y]) {
			good_j = false;
			break;
		}
	}
	return good_i || good_j;
}

bool solve() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(check(i, j) == false) {
				return false;
			}
		}
	}
	return true;
}

int main(void) {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		printf("Case #%d: %s\n", t, solve() ? "YES" : "NO");
	}
	return 0;
}
