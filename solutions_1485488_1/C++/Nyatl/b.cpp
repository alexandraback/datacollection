#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(i=a; i<=b; i++)
#define fj(a, b) for(j=a; j<=b; j++)
#define fo(a, b) for(o=a; o<=b; o++)
#define fdi(a, b) for(i=a; i>=b; i--)
#define fdj(a, b) for(j=a; j>=b; j--)
#define fdo(a, b) for(o=a; o>=b; o--)
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long int64;

int testq;
int test;

#define MAX 150

#define INF 1000000000

int n, m, h0;

int c[MAX][MAX];
int f[MAX][MAX];

void Read() {
	int i, j;
	scanf("%d %d %d", &h0, &m, &n);
	fj(1, m) {
		fi(1, n) {
			scanf("%d", &c[j][i]);
		}
	}
	fj(1, m) {
		fi(1, n) {
			scanf("%d", &f[j][i]);
		}
	}
}

int d[MAX][MAX];
int color[MAX][MAX];

set <pair<int, pair<int, int> > > g;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

bool Field(int x, int y) {
	if (x < 1 || x > n) return false;
	if (y < 1 || y > m) return false;
	return true;
}

void Solve() {
	int x, y;
	int t;
	int i, j;
	int x2, y2;
	int h;
	int u;
	ZERO(color);		

	fj(1, m) {
		fi(1, n) {
			d[j][i] = INF;
		}
	}

	d[1][1] = 0;

	g.clear();

	fj(1, m) {
		fi(1, n) {
			if (d[j][i] != INF) {
				g.insert(mp(d[j][i], mp(i, j) ) );
			}			
		}
	}	

	while (!g.empty()) {
		t = g.begin()->first;
		x = g.begin()->second.first;
		y = g.begin()->second.second;
		g.erase(g.begin());
		if (color[y][x]) continue;
		color[y][x] = 1;
		fi(0, 3) {
			x2 = x + dx[i];
			y2 = y + dy[i];
			if (!Field(x2, y2)) continue;
			if (f[y][x] > c[y2][x2] - 50) continue;
			if (f[y2][x2] > c[y2][x2] - 50) continue;
			if (f[y2][x2] > c[y][x] - 50) continue;
			if (h0 > c[y2][x2] - 50) continue;			

			if (d[y2][x2] > d[y][x]) {
				d[y2][x2] = d[y][x];
				g.insert(mp(d[y2][x2], mp(x2, y2)));
			}
		}
	}

	ZERO(color);
	g.clear();

	fj(1, m) {
		fi(1, n) {
			if (d[j][i] != INF) {
				g.insert(mp(d[j][i], mp(i, j) ) );
			}			
		}
	}

	while (!g.empty()) {
		t = g.begin()->first;
		x = g.begin()->second.first;
		y = g.begin()->second.second;
		g.erase(g.begin());
		if (color[y][x]) continue;
		color[y][x] = 1;
		fi(0, 3) {
			x2 = x + dx[i];
			y2 = y + dy[i];
			if (!Field(x2, y2)) continue;
			if (f[y][x] > c[y2][x2] - 50) continue;
			if (f[y2][x2] > c[y2][x2] - 50) continue;
			if (f[y2][x2] > c[y][x] - 50) continue;
			h = h0 - t;
			u = 0;
			if (h > c[y2][x2] - 50) {
				u = h - (c[y2][x2] - 50);
				h -= u;
			}

			if (h - f[y][x] >= 20) {
				u += 10;
			} else {
				u += 100;
			}

			if (d[y2][x2] > d[y][x] + u) {
				d[y2][x2] = d[y][x] + u;
				g.insert(mp(d[y2][x2], mp(x2, y2)));
			}
		}
	}

	printf("%d.%d\n", d[m][n] / 10, d[m][n] % 10);
	
}

int main(int argc, char **argv) {
	if (argc == 1) {
		freopen("input.txt","r",stdin);
	} else {
		freopen(argv[1], "r",stdin);
	}
	freopen("output.txt","w",stdout);
	scanf("%d", &testq);
	for (test = 1; test <= testq; test++) {
		Read();
		printf("Case #%d: ", test);
		Solve();
		fflush(stdout);
	}
	return 0;
}