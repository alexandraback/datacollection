#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <conio.h>
#include <functional>
#include <math.h>
#include <algorithm>
#include <time.h>
using namespace std;
int n, a[1005], res, c[1005], d[1005], cycle[1005], cn, son[1005], Res;
vector <int> v[1005], r[1005];
int chk[11], A[11];
bool ok(int x) {
	for (int i = 1; i <= x; i++) {
		int R = (i + 1);
		int L = (i - 1);
		if (R == x + 1) R = 1;
		if (L == 0) L = x;
		if (a[A[i]] == A[R] || a[A[i]] == A[L]) continue;
		else return 0;
	}
	return 1;
}
void go(int x) {
	if (ok(x-1)) {
		if (Res < x - 1)
			Res = x - 1;
	}
	for (int i = 1; i <= n; i++) {
		if (chk[i] == 0) {
			A[x] = i;
			chk[i] = 1;
			go(x + 1);
			chk[i] = 0;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int runs = 1;
	int T; for (scanf("%d", &T); T--;) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) v[i].clear(), r[i].clear();
		cn = res = 0; Res = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			v[i].push_back(a[i]);
			d[i] = c[i] = cycle[i] = son[i] = 0;
		}
		go(1);
		for (int i = 1; i <= n; i++) {
			if (cycle[i]) continue;
			if (d[i]) continue;
			vector <int> x;
			x.push_back(0);
			int p = i; x.push_back(i);
			c[p] = i; d[p] = 1;
			while (c[a[p]] != i) {
				d[a[p]] = d[p] + 1;
				p = a[p];
				c[p] = i;
				x.push_back(p);
			}
			if (son[x[d[a[p]]]] < d[a[p]] - 1) son[x[d[a[p]]]] = d[a[p]] - 1;
			if (cycle[x[d[a[p]]]]) continue;
			cn++;
			for (int j = d[a[p]]; j <= d[p]; j++) {
				cycle[x[j]] = cn;
				r[cn].push_back(x[j]);
			}
		}
		int res2 = 0, m1 = 0, m2 = 0;
		for (int i = 1; i <= cn; i++) {
			int m = r[i].size();
			if (res2 < m) res2 = m;
			if (m == 2) {
				res += 2;
				for (int j = 0; j < m; j++) {
					int x = r[i][j];
					int cost = son[x];
					if (m1 < cost) m2 = m1, m1 = cost;
					else if (m2 < cost) m2 = cost;
				}
			}
		}
		res += m1 + m2;
		if (res < res2) res = res2;
		printf("Case #%d: %d\n", runs++, Res);
	}
	return 0;
}