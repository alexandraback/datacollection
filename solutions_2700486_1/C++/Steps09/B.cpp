#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector <int> vi;

int sz[11002];

void prec_sizes() {
	sz[0] = 0;
	sz[1] = 1;
	int d = 5;
	for (int i = 2; i <= 11001; ++i) {
		sz[i] = sz[i - 1] + d;
		d += 4;
	}
}

double solve(int h, int n, int y) {
	if (h == 1)
		return 1.0;

	double p[2][30002];
	memset(p, 0, sizeof(p));

	int tt, tf;
	p[0][0] = 1;

	for (int i = 0; i < n; ++i) {
		tf = i & 1;
		tt = (i & 1) ^ 1;

		memset(p[tt], 0, sizeof(p[tt]));

		for (int j = 0; j <= h; ++j) {
			int l = j, r = i - j;
			if (l < h - 1 && r < h - 1) {
				p[tt][j] += p[tf][j] / 2.0;
				p[tt][j + 1] += p[tf][j] / 2.0;
			} else if (l == h - 1 && r == h - 1) {
				p[tt][h] += p[tf][j];
			} else if (l == h - 1) {
				p[tt][l] += p[tf][j];
			} else {
				p[tt][l + 1] += p[tf][j];
			}
		}

		/*for (int j = 0; j <= h; ++j)
			printf("%.2lf ", p[tt][j]);
		printf("\n");*/
	}

	double s = 0;
	for (int i = y + 1; i <= h; ++i)
		s += p[tt][i];

	return s;
}

int main() {
	prec_sizes();
	
	int T;
	scanf("%d", &T);
	for (int TT = 1; TT <= T; ++TT) {
		cerr << "Processing " << TT << endl;
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);

		int dd = (abs(x) + abs(y)) / 2;

		if (n >= sz[dd + 1]) {
			printf("Case #%d: 1.0\n", TT);
			continue;
		}

		n -= sz[dd];

		if (n > 0) {
			printf("Case #%d: %.7lf\n", TT, solve(dd * 2 + 1, n, y));
		} else {
			printf("Case #%d: 0.0\n", TT);
		}
	}
}