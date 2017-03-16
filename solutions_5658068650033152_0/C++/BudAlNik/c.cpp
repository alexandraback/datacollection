#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;
const int MAXN = 25;

int t, n, m, k, ans;
bool grid[MAXN][MAXN];
bool used[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int x, int y) {
	//cout << "dfs " << x << " " << y << endl;
	used[x + 1][y + 1] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (-1 <= nx && nx < MAXN - 1 && -1 <= ny && ny < MAXN - 1 && (nx < 0 || ny < 0 || !grid[nx][ny]) && !used[nx + 1][ny + 1]) {
			dfs(nx, ny);
		}
	}
	return 0;
}

int rec(int x, int y, int nums) {
	//cout << x << " " << y << endl;
	if (x == 0 && y == m) {
		memset(used, 0, sizeof used);
		dfs(-1, -1);
		int numo = 0;
		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				if (!used[i][j]) {
					++numo;
					//cout << i << " " << j << endl;
				}
			}
		}
		//cout << n << " " << m << " " << numo << endl;
		//assert(false);
		if (numo >= k) {
			ans = min(ans, nums);
		}
		return 0;
	}
	grid[x][y] = true;
	if (x == n - 1) {
		rec(0, y + 1, nums + 1);
	} else {
		rec(x + 1, y, nums + 1);
	}
	grid[x][y] = false;
	if (x == n - 1) {
		rec(0, y + 1, nums);
	} else {
		rec(x + 1, y, nums);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	
	for (int i = 0; i < t; ++i) {
		cin >> n >> m >> k;
		//cout << n << " " << m << endl;
		ans = n * m + 100500;
		//rec(0, 0, 0);
		int bsb = 1 << (n * m);
		//cout << bsb << " bsb" << endl;
		for (int i2 = 0; i2 < bsb; ++i2) {
			/*
			if (i2 % 100000 == 0) {
				cout << i2 << endl;
			}*/
			int temp = i2;
			int nums = 0;
			memset(grid, 0, sizeof grid);
			for (int j = 0; j < (n * m); ++j) {
				if (temp % 2) {
					++nums;
				}
				grid[j % n][j / n] = temp % 2;
				temp /= 2;
			}
			if (nums >= ans) {
				continue;
			}
			memset(used, 0, sizeof used);
			dfs(-1, -1);
			int numo = 0;
			for (int i = 0; i < MAXN; ++i) {
				for (int j = 0; j < MAXN; ++j) {
					if (!used[i][j]) {
						++numo;
						//cout << i << " " << j << endl;
					}
				}
			}
			
			if (numo >= k) {
				if (nums == 0) {
					cout << n << " " << m << " " << numo << endl;
					for (int i = 0; i < MAXN; ++i) {
						for (int j = 0; j < MAXN; ++j) {
							if (!used[i][j]) {
								//++numo;
								cout << i << " " << j << " " << grid[i][j] << endl;
							}
						}
					}
					assert(false);
				}
				ans = min(ans, nums);
			}	
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	
	return 0;
}
