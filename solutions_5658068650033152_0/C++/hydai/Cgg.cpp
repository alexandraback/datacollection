#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
int ans = 1e9;
int n, m, k, T;
int temp[10];
void dfs(int lv, int h, int tot, int cost) {
	if (tot == k && cost < ans) {
		int real_cost = cost;
		if (lv != m + 1 && h > 2) {
			real_cost += h - 2;
		}
		ans = min(real_cost, ans);
		return;
	}
	else if (tot > n * m) {
		return;
	}
	else if (lv <= m) {
		int a = h - 2, b = h + 2;
		if (a < 0)
			a = 1;
		if (b > n)
			b = n;
		for (int i = a; i <= b; i++) {
			temp[lv] = i;
			dfs(lv + 1, i, tot + i, cost + (i == 1 ? 1 : (lv == m ? i : 2)));
		}
	}
}
int main() {
	cin >> T;
	for (int ctt = 1; ctt <= T; ctt++) {
		ans = 1e9;
		cin >> n >> m >> k;
		for (int i = 0; i <= n; i++) {
			temp[1] = i;
			dfs(2, i, i, i);
		}
		printf("Case #%d: %d\n", ctt, ans);
	}
	return 0;
}
