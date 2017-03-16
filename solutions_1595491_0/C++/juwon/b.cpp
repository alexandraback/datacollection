#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int p;

int a[101];
int d[101][101];

int solve(int n, int s) {
	if (d[n][s] != -2) return d[n][s];
	if (s < 0) return -1;
	if (s > n) return d[n][s] = -1;
	// n >= s
	if (n == 0) return d[n][s] = 0;
	
	d[n][s] = -1;
	int k;
	// non susprising
	k = solve(n - 1, s);
	if (k >= 0) {
		d[n][s] = k + ((a[n] % 3 == 0 ? a[n] / 3 : a[n] / 3 + 1) >= p ? 1 : 0);
	}

	// suprising
	k = solve(n - 1, s - 1);
	if (s > 0 && k >= 0 && a[n] >= 2) {
		d[n][s] = max(d[n][s], k + ((a[n] % 3 == 2 ? a[n] / 3 + 2 : a[n] / 3 + 1) >= p ? 1 : 0));
	}
	return d[n][s];
}

int main() {
	freopen("input.txt", "r", stdin);
	int r, cs = 0;
	scanf("%d", &r);
	while (r--) {
	int n, s;
		scanf("%d %d %d", &n, &s, &p);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		fill(d[0], d[n + 1], -2);
		printf("Case #%d: %d\n", ++cs, solve(n, s));
	}
	return 0;
}
