#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int v[15];
int best[15];

long long GetLCD(int k) {
	long long ret = 1;
	for (int i = 0; i < k; ++i) {
		int gcd = __gcd(ret, (long long)v[i]);
		ret /= gcd;
		ret *= v[i];
	}
	return ret;
}

void DFS(long long v, int pos, int n, int m) {
	if (pos == n) {
		if (v != 1) {
			return;
		}
		for (int i = 0; i < n; ++i) {
			best[i] = ::v[i];
		}
		return;
	}
	for (int i = m; i > 1; --i) {
		if (v % i == 0) {
			::v[pos] = i;
			DFS(v / i, pos + 1, n, i);
		}
	}
}

void solve(int n, int m, int k) {
	long long lcd = GetLCD(k);
	for (int i = 0; i < n; ++i) {
		best[i] = 2;
	}
	DFS(lcd, 0, n, m);
}


int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int I = 0; I < T; ++I) {
		printf("Case #%d:\n", I + 1);
		int n, m, r, k;
		scanf("%d%d%d%d", &r, &n, &m, &k);
		for (int j = 0; j < r; ++j) {
			for (int i = 0; i < k; ++i) {
				scanf("%d", &v[i]);
			}
			solve(n, m, k);
			for (int i = 0; i < n; ++i) {
				printf("%d", best[i]);
			}
			puts("");
		}
	}
	return 0;
}