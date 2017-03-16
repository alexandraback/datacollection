#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

void solve() {
	int n, x, y, cx = 0, cy = 0;
	cin >> n >> x >> y;
	//cout << n << " " << x << " " << y << endl;
	//return;
	while (abs(x) + y != cx + cy) {
		if (n > 2 * cy + 1) {
			n -= 2 * cy + 1;
			cy += 2;
		} else {
			printf("%.10lf", 0.0);
			return;
		}
	}
	if (n >= 2 * cy + 1) {
		printf("%.10lf", 1.0);
		return;
	}
	double ans = 0;
	int a1 = y, a2 = cy;
	if (a1 + a2 < n) {
		printf("%.10lf", 1.0);
		return;
	}
	vector<vector<double> > d(cy + 1, vector<double>(cy + 1, 0));
	d[0][0] = 1;
	for (int k = 0; k < n; k++) {
		for (int i = max(0, k - cy); i <= min(cy, k); i++) {
			int j = k - i;
			if (i == cy) {
				d[i][j + 1] += d[i][j];
			} else if (j == cy) {
				d[i + 1][j] += d[i][j];
			} else {
				d[i][j + 1] += d[i][j] / 2;
				d[i + 1][j] += d[i][j] / 2;
			}
		}
	}
	for (int i = 0; i <= cy; i++)
		for (int j = 0; j <= cy; j++)
			if (i + j == n && i > y)
				ans += d[i][j];
	printf("%.10lf", ans);
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int tests;
	cin >> tests;
	//cout << tests << endl;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
		solve();
		cout << endl;
	}
	return 0;
}