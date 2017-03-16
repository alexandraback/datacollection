#include<string>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int T;
int n, x, y;
double a[4000][4000];

void init() {
	cin >>  n >> x >> y;
}

int calc(int n) {
	int ret = 0;
	int x = 5, tot = 1;
	while (n >= x + tot) {
		ret += 1;
		tot += x;
		x += 4;
	}
	return ret;
}

bool check_in(int x, int y, int h) {
	return abs(x) + abs(y) <= h + h;
}

double work() {
	int h = calc(n);
	if (check_in(x, y, h))
		return 1.0;
	if (!check_in(x, y, h + 1))
		return 0;

	int c = 1;
	while (n >= c) {
		n -= c;
		c += 4;
	}

	memset(a, 0, sizeof(a));
	a[0][0] = 1;
	for (int i=0; i<n; i++)
		for (int j=0; j<= 2*(h + 1); j++) {
			int l = i - j, r = j;
			if (l < 0 || r < 0)
				break;
			if (l + 1 <= 2*(h + 1) && r + 1 <= 2*(h + 1))
				a[l + 1][r] += a[l][r] * 0.5;
			else if (l + 1 <= 2*(h + 1))
				a[l + 1][r] += a[l][r];
			if (r + 1 <= 2*(h + 1) && l + 1 <= 2*(h + 1))
				a[l][r + 1] += a[l][r] * 0.5;
			else if (r + 1 <= 2*(h + 1))
				a[l][r + 1] += a[l][r];
		}
	double ans = 0;
	for (int l = y + 1; l <= 2*(h + 1); ++l)
		ans += a[l][n-l];
	return ans;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	for (int i=1; i<=T; i++) {
		init();
		printf("Case #%d: %.6lf\n", i, work());
	}
	return 0;
}