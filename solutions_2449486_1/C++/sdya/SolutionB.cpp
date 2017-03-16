#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
int a[maxN][maxN], n, m;
bool used[maxN][maxN];

void solve(int test) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	memset(used, 0, sizeof(used));

	for (int h = 1; h <= 100; ++h) {
		vector < int > rows(n, false);
		vector < int > cols(m, false);
		for (int i = 0; i < n; ++i) {
			int total = 0;
			for (int j = 0; j < m; ++j) {
				total += (a[i][j] == h);
			}
			if (total == m) {
				rows[i] = true;
			}
		}
		for (int i = 0; i < m; ++i) {
			int total = 0;
			for (int j = 0; j < n; ++j) {
				total += (a[j][i] == h);
			}
			if (total == n) {
				cols[i] = true;
			}
		}

		for (int i = 0; i < n; ++i) {
			if (rows[i]) {
				for (int j = 0; j < m; ++j) {
					a[i][j] = h + 1;
				}
			}
		}

		for (int i = 0; i < m; ++i) {
			if (cols[i]) {
				for (int j = 0; j < n; ++j) {
					a[j][i] = h + 1;
				}
			}
		}
	}

	int total = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			total += (a[i][j] == 101);
		}
	}

	if (total == n * m) {
		printf("Case #%d: YES\n", test);
	} else {
		printf("Case #%d: NO\n", test);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d\n", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
	}
	return 0;
}