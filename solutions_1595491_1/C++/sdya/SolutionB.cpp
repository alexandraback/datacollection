#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxN = 110;
int a[maxN];
int d[maxN][maxN];

void solve(int test) {
	int n, s, p;
	scanf("%d%d%d", &n, &s, &p);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= s; ++j) {
			d[i][j] = d[i - 1][j];
			for (int x = 0; x <= 10; ++x) 
				for (int y = x; y <= 10 && y <= x + 2; ++y)
					for (int z = y; z <= 10 && z <= x + 2; ++z) 
						if (x + y + z == a[i]) {
							if (z < x + 2 && z >= p) {
								d[i][j] = max(d[i][j], d[i - 1][j] + 1);
							}
							if (z == x + 2 && z >= p && j > 0) {
								d[i][j] = max(d[i][j], d[i - 1][j - 1] + 1);
							}
						}
		}
	}
	printf("Case #%d: %d\n", test, d[n][s]);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
	}
	return 0;
}