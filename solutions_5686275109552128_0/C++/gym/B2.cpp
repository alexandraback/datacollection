#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
const int MAXN = 1111;

int n, d[MAXN];

int down(int x, int y) {
	if (x <= y) return 0;
	int h1, h2;
	if (x & 1) {
		h1 = x / 2;
		h2 = h1 + 1;
	} else {
		h1 = h2 = x / 2;
	}
	return min((x - 1) / y, (1 + down(h1, y) + down(h2, y)));
}

void solve(int c) {
	cin >> n;
	int tmax = 0;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		tmax = max(d[i], tmax);
	}
	int ans = tmax;
	for (int i = tmax; i > 0; i--) {
		int delta = 0;
		for (int j = 0; j < n; j++) {
			int tmp = down(d[j], i);
			delta += tmp;
		}
		ans = min(ans, delta + i);
	}
	cout << "Case #" << c << ": " << ans << endl;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve(i + 1);
	return 0;
}
