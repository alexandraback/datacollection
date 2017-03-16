#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

#define INF (2000000000)

const int nmax = 1 << 7;
const double inf = 1e10;
const double eps = 1e-9;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int L[nmax][nmax];
int H[nmax][nmax];
double d[nmax][nmax];
int HH;
int n, m;

set< pair<double, pair<int, int> > > s;

double cost(int i1, int j1, int i2, int j2, double h) {

	if (min(H[i1][j1], H[i2][j2]) - max(L[i1][j1], L[i2][j2]) < 50) {
		return -1;
	}

	double w = max(HH - h * 10, L[i1][j1] + 0.0);

	double cst = 0.0;

	if ((H[i2][j2] - w) < 50) {
		cst = (50 - (H[i2][j2] - w)) / 10;
		w = H[i2][j2] - 50;
	}

	double diff = w - L[i1][j1];

	if (diff < eps) {
		return 0;
	}

	if (diff + eps > 20) {
		return 1.0 + cst;
	}

	return 10.0f + cst;
}

double cost1(int i1, int j1, int i2, int j2, double h) {

	if (min(H[i1][j1], H[i2][j2]) - max(max(L[i1][j1], L[i2][j2]), HH) < 50) {
		return -1;
	}

	return 0.0f;
}


void solveTest() {

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			d[i][j] = inf;
		}
	}

	s.clear();
	d[0][0] = 0;

	d[0][0] = 0;

	s.insert(make_pair(0.0, make_pair(0, 0)));

	while(!s.empty()) {

		pair<double, pair<int, int> > t = *s.begin();
		s.erase(s.begin());

		int x = t.second.first;
		int y = t.second.second;
		double h = t.first;

		for(int i = 0; i < 4; ++i) {

			int kx = x + dir[i][0];
			int ky = y + dir[i][1];

			if (kx >= 0 && kx < n &&
				ky >= 0 && ky < m) {

				double cst = cost1(x, y, kx, ky, h);

				if (cst < 0) {
					continue;
				}

				if (d[kx][ky] > d[x][y] + cst) {

					if (d[kx][ky] != inf) {
						s.erase(make_pair(d[kx][ky], make_pair(kx, ky)));
					}

					d[kx][ky] = d[x][y] + cst;
					s.insert(make_pair(d[kx][ky], make_pair(kx, ky)));
				}
			}
		}

	}


	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if (d[i][j] != inf) {
				s.insert(make_pair(d[i][j], make_pair(i, j)));
			}
		}
	}

	while(!s.empty()) {

		pair<double, pair<int, int> > t = *s.begin();
		s.erase(s.begin());

		int x = t.second.first;
		int y = t.second.second;
		double h = t.first;

		for(int i = 0; i < 4; ++i) {

			int kx = x + dir[i][0];
			int ky = y + dir[i][1];

			if (kx >= 0 && kx < n &&
				ky >= 0 && ky < m) {

				double cst = cost(x, y, kx, ky, h);

				if (cst < 0) {
					continue;
				}

				if (d[kx][ky] > d[x][y] + cst) {

					if (d[kx][ky] != inf) {
						s.erase(make_pair(d[kx][ky], make_pair(kx, ky)));
					}

					d[kx][ky] = d[x][y] + cst;
					s.insert(make_pair(d[kx][ky], make_pair(kx, ky)));
				}
			}
		}

	}

	printf("%.9lf", d[n - 1][m - 1]);

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in", "rt", stdin);
	freopen("B.out", "wt", stdout);
#endif
	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {

		scanf("%d%d%d", &HH, &n, &m);

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf("%d", &H[i][j]);
			}
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf("%d", &L[i][j]);
			}
		}

		printf("Case #%d: ", tt + 1);
		solveTest();
		puts("");
		cerr << "Case " << tt + 1 << " done\n";
	}
	return 0;
}