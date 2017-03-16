#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
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
#include <cstring>
#include <ctime>

using namespace std;

const int u[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int c[100][100], f[100][100];
double mint[100][100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test ++) {
		int h, n, m;
		scanf("%d%d%d", &h, &n, &m);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++) scanf("%d", &c[i][j]);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++) scanf("%d", &f[i][j]);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++) mint[i][j] = 1e100;
		mint[0][0] = 0;
		while (true) {
			bool flag = false;
			for (int i = 0; i < n; i ++)
				for (int j = 0; j < m; j ++) {
					if (mint[i][j] == 1e100) continue;
					double nowh = max(0.0, h - 10 * mint[i][j]);
					for (int k = 0; k < 4; k ++) {
						int t1 = i + u[k][0], t2 = j + u[k][1];
						if (0 > t1 || t1 >= n || 0 > t2 || t2 >= m) continue;
						if (c[t1][t2] - f[t1][t2] < 50) continue;
						if (c[i][j] - f[t1][t2] < 50) continue;
						if (c[t1][t2] - f[i][j] < 50) continue;
						double need = mint[i][j];
						if (c[t1][t2] - nowh < 50) need += (50 - (c[t1][t2] - nowh)) / 10;
						if (need > 0)
							if (max(0.0, h - 10 * need - f[i][j]) >= 20) need += 1; else need += 10;
						if (need < mint[t1][t2]) {
							mint[t1][t2] = need;
							flag = true;
						}
					}
				}
			if (! flag) break;
		}
		printf("Case #%d: %.10lf\n", test + 1, mint[n-1][m-1]);
	}
	
	return 0;
}
