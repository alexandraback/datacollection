#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <set>
#include <map>
using namespace std;

#define N 1005


int i, j, k, n, m, l, tt, T;
double x, y, z, t, r, res, p;


int main() {
	freopen("large.in", "r", stdin);
	freopen("large.out", "w", stdout);
	scanf("%d", &T);
	for (tt = 1; tt <= T; tt ++) {
		scanf("%d%d", &n, &m);
		res = m + 2;
		p = 1;
		for (i = 0; i < n; i ++) {
			t = (p) * (n - i + m - i + 1) + (1.0 - p) * (n - i + m - i + 1 + m + 1);
			if (t < res) {
				res = t;
			}
			scanf("%lf", &x);
			p *= x;
		}
		t = (p) * (n - i + m - i + 1) + (1.0 - p) * (n - i + m - i + 1 + m + 1);
		if (t < res) {
			res = t;
		}
		printf("Case #%d: %.8lf\n", tt, res);
	}
	return 0;
}



