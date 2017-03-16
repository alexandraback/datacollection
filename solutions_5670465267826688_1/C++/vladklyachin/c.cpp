#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

#define NN 10010

int t, L, x;
long long X;
char c[NN];
int v[NN];

int m[5][8] = {
	{ 0, 0, 0, 0, 0},
	{ 0, 1, 2, 3, 4},
	{ 0, 2, -1, 4, -3},
	{ 0, 3, -4, -1, 2},
	{ 0, 4, 3, -2, -1},
};

int mul(int a, int b) {
	if (a == 0 || b == 0) return 0;
	if (a > 0 && b > 0) {
		return m[a][b];
	} else if (a > 0 && b < 0) {
		return -m[a][-b];
	} else if (a < 0 && b > 0) {
		return -m[-a][b];
	}
	return m[-a][-b];
}

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d%lld%s", &L, &X, c);
		x = X % 4;
		for (int i = 0; i < L; ++i) {
			v[i] = c[i] - 'i' + 2;
		}
		int p = 1;
		for (int i = 0; i < L; ++i) {
			p = mul (p, v[i]);
		}
		//printf ("p=%d\n", p);
		int q = 1;
		for (int j = 0; j < x; ++j) {
			q = mul (q, p);
		}
		//printf ("q=%d\n", q);
		if (q == -1) {
			int r = 1;
			int g = 2;
			for (long long Y = 0; Y < X && Y < 16; ++Y) {
				for (int i = 0; i < L; ++i) {
					r = mul (r, v[i]);
					if (r == g) {
						++g;
						r = 1;
						if (g == 4) goto yes;
					}
				}
			}
		}
		printf("Case #%d: NO\n", ti+1);
		continue;
yes:
		printf("Case #%d: YES\n", ti+1);
		continue;
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
