#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int A[100][100], n, m;

int cnt(long long x) {
	return x == 0 ? 0 : cnt(x / 2) + (x % 2);
}

int c[1 << 20], form[1 << 20];

const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

inline bool legal(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m; 
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	for (int i = 0; i < (1 << 20); ++ i)
		c[i] = cnt(i); 

	int _; cin >> _;
	for (int __ = 1; __ <= _; ++ __) {
		printf("Case #%d: ", __);
		int k;

		cin >> n >> m >> k; 

		int ans = 2 * (n + m); 
		for (int i = 0; i < (1 << (n * m)); ++ i) {
			if (c[i] >= k) {
				int tmp = 0; 
				memset(A, 0, sizeof A);
				for (int a = 0; a < n; ++ a)
					for (int b = 0; b < m; ++ b)
						A[a][b] = ((i >> (a * m + b)) & 1);

				for (int a = 0; a < n; ++ a)
					for (int b = 0; b < m; ++ b)
						if (A[a][b]) {
							for (int k = 0; k < 4; ++ k)
								if (! legal(a + dir[k][0], b + dir[k][1]) || ! A[a + dir[k][0]][b + dir[k][1]]) {
									++ tmp; 
									break; 
								}
						}

				if (tmp < ans) {
					ans = tmp;
//					for (int a = 0; a < n; ++ a) {
//						for (int b = 0; b < m; ++ b)
//							printf("%d", A[a][b]);
//						puts("");
//					}
				} 
			}
		}

		printf("%d\n", ans); 

	}

	return 0; 
}