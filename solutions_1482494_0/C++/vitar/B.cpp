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

#define N 2005
int a[N], b[N];
int ua[N], ub[N];

struct st {
	int a;
	int c;
};

st c[N];
int pr(st a, st b) {
	if (a.a != b.a) {
		return a.a < b.a;
	}
	return a.c > b.c;
}

int i, j, k, n, m, x, y, z, t, T, tt, res, nm, mx;


int main() {
	freopen("small.in", "r", stdin);	freopen("small.out", "w", stdout);
	scanf("%d", &T);

	for (tt = 1; tt <= T; tt ++) {
		scanf("%d", &n);
		res = 0;
		memset(ua, 0, sizeof(ua));
		memset(ub, 0, sizeof(ub));
		for (i = 0; i < n+n; i += 2) {
			scanf("%d%d", &c[i].a, &c[i+1].a);
			c[i].c = 0;
			c[i+1].c = 1;
		}
		printf("Case #%d: ", tt);
		x = 0;
		n *= 2;
		sort(c, c + n, pr);
		x = 0;
		y = 0;
		res = 0;
		for (i = 0; i < n; i ++) {
			if (c[i].a > x) {
				printf("Too Bad\n");
				break;
			}
			res = max(res, c[i].a - (x - y));
			if (c[i].c == 0) {
				y ++;
			} else {
				y --;
			}
			x ++;
		}
		if (i >= n) {
			printf("%d\n", res + n/2);
		}

	}
	return 0;
}