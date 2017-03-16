#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 1001;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int a[maxn][maxn];
int n, m, k;
int tcnt;

void init() {
	scanf("%d %d %d", &n, &m, &k);
}

bool inside(int x, int y) {
	return (x >= 1) && (x <= n) && (y >= 1) && (y <= m);
}

void dfs(int x, int y) {
	if (a[x][y] == -1) {
		return;
	}
	if (a[x][y] == 0) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (!inside(tx, ty)) {
			continue;
		}
		if (a[tx][ty] == -1) {
			continue;
		}
		if (a[tx][ty] == 1) {
			continue;
		}
		a[tx][ty] = -1;
		tcnt++;
	}
}

bool check(int cnt) {
	if ((n <= 2) || (m <= 2)) {
		return (cnt >= k);
	}
	if (cnt >= k) {
		return true;
	}
	int rem = k - cnt;
	for (int i = 1; i <= n - 2; i++) {
		tcnt = 0;
		memset(a, 0, sizeof(a));
		int done = 0;
		for (int x = 2; x <= 2 + i - 1; x++) {
			for (int y = 2; y <= m - 1; y++) {
				a[x][y] = 1;
				done++;
				if (done >= rem) {
					break;
				}
			}
			if (done >= rem) {
				break;
			}
		}
		if (done < rem) {
			continue;
		}
		bool good = true;
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <=n; y++) {
				dfs(x, y);
				if (tcnt > cnt) {
					good = false;
					break;
				}
			}
			if (!good) {
				break;
			}
		}
		if (good) {
			return true;
		}
	}
	for (int i = 1; i <= m - 2; i++) {
		tcnt = 0;
		memset(a, 0, sizeof(a));
		int done = 0;
		for (int y = 2; y <= 2 + i - 1; y++) {
			for (int x = 2; x <= n - 1; x++) {
				a[x][y] = 1;
				done++;
				if (done >= rem) {
					break;
				}
			}
			if (done >= rem) {
				break;
			}
		}
		if (done < rem) {
			continue;
		}
		bool good = true;
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <=n; y++) {
				dfs(x, y);
				if (tcnt > cnt) {
					good = false;
					break;
				}
			}
			if (!good) {
				break;
			}
		}
		if (good) {
			return true;
		}
	}
	return false;	
}

int calc() {
	for (int i = 1; i <= k; i++) {
		if (check(i)) {
			return i;
		}
	}
}

int main() {
	int tcase;
	scanf("%d", &tcase);
	for (int i = 1; i <= tcase; i++) {
		init();
		printf("Case #%d: %d\n", i, calc());
	}
	return 0;
}