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
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 256;

int n, m;
int64 hgt0;
int64 low[SIZE][SIZE], high[SIZE][SIZE];

inline bool good(int x, int y) {
	return x>=0 && x<n && y>=0 && y<m;
}

const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

bool used[SIZE][SIZE];
int64 dist[SIZE][SIZE];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%I64d%d%d", &hgt0, &n, &m);
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				scanf("%I64d", &high[i][j]);
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				scanf("%I64d", &low[i][j]);

		memset(used, 0, sizeof(used));
		memset(dist, 63, sizeof(dist));
		dist[0][0] = -1000000000LL;

		while (1) {
			int64 mind = 1000000000000000000LL;
			int bi = -1, bj = -1;
			for (int i = 0; i<n; i++)
				for (int j = 0; j<m; j++) if (!used[i][j])
					if (mind > dist[i][j]) {
						mind = dist[i][j];
						bi = i;
						bj = j;
					}
			if (bi < 0) break;
			used[bi][bj] = true;
			for (int d = 0; d<4; d++) {
				int ni = bi + dir[d][0];
				int nj = bj + dir[d][1];
				if (!good(ni, nj)) continue;

				if (high[ni][nj] - low[ni][nj] < 50) continue;
				if (high[ni][nj] - low[bi][bj] < 50) continue;
				if (high[bi][bj] - low[ni][nj] < 50) continue;

				int64 nowt = dist[bi][bj];
				int64 wlvl = hgt0 - max(nowt, 0LL);
				int64 needtime = 50 - (high[ni][nj] - wlvl);
				if (needtime < 0) needtime = 0;
				if (needtime > 0 && nowt < 0) needtime += -nowt;

				nowt += needtime;
				wlvl = hgt0 - max(nowt, 0LL);
				int add = 0;
				if (wlvl - low[bi][bj] >= 20) add = 1;
				else add = 10;
				nowt += add * 10;

				if (dist[ni][nj] > nowt)
					dist[ni][nj] = nowt;
			}
		}

		int64 ans = dist[n-1][m-1];
		Eo(ans);
		if (ans < 0) ans = 0;
		printf("Case #%d: %0.1lf\n", tt, double(ans * 0.1));
		fflush(stdout);
	}
	return 0;
}
