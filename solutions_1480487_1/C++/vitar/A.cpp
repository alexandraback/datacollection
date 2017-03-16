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
#define IT 70

int a[N];

int i, j, k, n, m, t, tt, T, it;
double x, y, z, l, r, c, s, mx;



int main() {
	freopen("large.in", "r", stdin);	freopen("large.out", "w", stdout);

	scanf("%d", &T);
	for (tt = 1; tt <= T; tt ++) {
		scanf("%d", &n);
		s = 0;
		mx = 0;
		for (i = 0; i < n; i ++) {
			scanf("%d", &a[i]);
			s += a[i];
		}

		printf("Case #%d:", tt);
		
		for (j = 0; j < n; j ++) {
			mx = 0;
			for (i = 0; i < n; i ++) {
				if (i == j) {
					continue;
				}
				if (a[i] > mx) {
					mx = a[i];
				}
			}
			l = 0;
			r = 1;
			for (it = 0; it < IT; it ++) {
				c = (l + r) / 2;
				x = a[j] + s*c;
				m = 0;
				z = 0;
				for (k = 0; k < n; k ++) {
					if (k == j) {
						continue;
					}
					if (a[k] < x) {
						m ++;
						z += a[k];
					}
				}
				y = (z + s*(1-c)) / m;
				if (x >= y) {
					r = c;
				} else {
					l = c;
				}
			}
			printf(" %.8lf", c*100);
		}
		printf("\n");
	}
	return 0;
}




