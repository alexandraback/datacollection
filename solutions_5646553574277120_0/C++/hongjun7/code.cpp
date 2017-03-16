#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define min(a, b) ((a)>(b)?(b):(a))
int a[133], v[133], C, D, V, c[133], b[133], n;
void go(int x, int s) {
	v[s] = 1;
	if (x == D + 1) {
		return;
	}
	go(x + 1, s);
	go(x + 1, s + a[x]);
}
int res, d[103][103];
void f(int x, int y) {
	if (x == V + 1) {
		if (res > y) res = y;
		return;
	}
	if (v[x] == 0) {
		int p = 0;
		for (int i = 1; i <= x; i++) {
			if (c[i] == 0 && v[x - i]) {
				c[i] = 1;
				for (int j = V; j >= 0; j--) {
					d[x][j] = v[j];
					if (j >= i) v[j] |= v[j - i];
				}
				f(x + 1, y + 1);
				c[i] = 0;
				for (int j = V; j >= 0; j--) v[j] = d[x][j];
			}
		}
	}
	else f(x + 1, y);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, runs = 1;
	for (scanf("%d", &T); T--;) {
		scanf("%d%d%d", &C, &D, &V);
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= D; i++) scanf("%d", &a[i]), c[a[i]] = 1;
		n = 0;
		for (int i = 1; i <= V; i++) if (c[i] == 0) b[++n] = i;
		memset(v, 0, sizeof(v));
		go(1, 0);
		res = V;
		f(1, 0);
		printf("Case #%d: %d\n", runs++, res);
	}
}