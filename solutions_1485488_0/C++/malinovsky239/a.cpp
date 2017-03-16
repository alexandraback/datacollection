#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef long double LD;

#define pb push_back
#define mp make_pair
#define sz(A) (int)(A).size()

const int N = 105;
const double INF = 1e9, eps = 1e-12;
int c[N][N], f[N][N], h, m, n;
double d[N][N];
bool used[N][N];

bool correct(int val, int bound) {
	return (val && val <= bound);		
}

void dfs(int j, int k) {
	d[j][k] = 0;
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
			if (abs(dx) + abs(dy) == 1) 
				if (correct(j + dx, n) && correct(k + dy, m) && f[j + dx][k + dy] + 50 <= c[j][k] && max(f[j][k], f[j + dx][k + dy]) + 50 <= c[j + dx][k + dy] && h + 50 <= c[j + dx][k + dy])
					if (d[j + dx][k + dy] > INF / 2)
						dfs(j + dx, k + dy);		
}

int main() {
	int t;
	cin >> t;	

	for (int i = 0; i < t; i++) {	
		cout << "Case #" << i + 1 << ": ";
		cin >> h >> n >> m;

		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= m; k++)
				cin >> c[j][k];
		
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= m; k++) {
				cin >> f[j][k];
				d[j][k] = INF;
				used[j][k] = 0;
			}

		dfs(1, 1);		

		for (int it = 0; it < n * m; it++) {
			int ind_x, ind_y;
			double best = INF;

			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= m; k++) 
					if (!used[j][k] && d[j][k] < best) {
						best = d[j][k];
						ind_x = j, ind_y = k;
					}

			if (best == INF)
				break;	

			int j = ind_x, k = ind_y;

			used[j][k] = true;

			for (int dx = -1; dx <= 1; dx++)
				for (int dy = -1; dy <= 1; dy++)
					if (abs(dx) + abs(dy) == 1) {
						if (correct(j + dx, n) && correct(k + dy, m) && f[j + dx][k + dy] + 50 <= c[j][k] && max(f[j][k], f[j + dx][k + dy]) + 50 <= c[j + dx][k + dy]) {
							double dh = c[j + dx][k + dy] - max(0.0, (h - d[j][k] * 10));
							if (dh + eps > 50) {
								if (max(0.0, (h - d[j][k] * 10)) - f[j][k] + eps > 20) {
									d[j + dx][k + dy] = min(d[j + dx][k + dy], d[j][k] + 1);
								}
								else {
									d[j + dx][k + dy] = min(d[j + dx][k + dy], d[j][k] + 10);
								}																
							}
							else {							
								double timer = double(h - c[j + dx][k + dy] + 50) / 10;
								double water = max(h - timer * 10, 0.0);
								if (water - f[j][k] + eps > 20) {
									d[j + dx][k + dy] = min(d[j + dx][k + dy], d[j][k] + 1 + timer);
								}
								else {
									d[j + dx][k + dy] = min(d[j + dx][k + dy], d[j][k] + 10 + timer);
								}																
							}
						}
					}
		}

		cout.precision(6);
		cout << fixed << d[n][m] << endl;
	}

	return 0;
}
