#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;

double dp[1500][1500];

double solve(int N, int X, int Y) {
	int s = 0;
	int t = 1;
	int u = 0;
	while (s+t <= N) {
		s += t;
		t += 4;
		u++;
	}
	//printf("u=%d\n", u);
	int yy = Y+abs(X);
	if (yy < u*2)
		return 1.0;
	if (yy > u*2)
		return 0.0;
	int n = N-s;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 0.0;
		}
	}
	dp[0][0] = 1.0;
	//printf("u=%d\n", u);
	//printf("n=%d\n", n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j < 2*u && i-j < 2*u) {
				dp[j+1][i-j] += dp[j][i-j]*0.5;
				dp[j][i-j+1] += dp[j][i-j]*0.5;
			} else if (j < 2*u) {
				dp[j+1][i-j] += dp[j][i-j];
			} else {
				dp[j][i-j+1] += dp[j][i-j];
			}
		}
	}
	double p = 0.0;
	//printf("i=%d\n", u*2+1-abs(X));
	//printf("N-s=%d\n", N-s);
	for (int i = u*2+1-abs(X), j = N-s-i; i <= u*2 && j >= 0; i++, j--) {
		//printf("i=%d j=%d\n", i,j );
		p += dp[i][j];
	}
	return p;
}

pair<ll, ll> rec(int i, bool mp_[50][50], int N, int X, int Y) {
	const int o = 25;
	if (i == N) {
		if (mp_[o+X][Y])
			return make_pair(1LL, 1LL);
		else
			return make_pair(0LL, 1LL);
	}
	bool mp[50][50];
	memcpy(mp, mp_, sizeof(mp));
	int x = 0;
	int y = 48;
	while (true) {
		if (y < 0)
			exit(1);
		if (y == 0) {
			mp[o+x][y] = true;
			return rec(i+1, mp, N, X, Y);
		}
		if (mp[o+x][y-2]) {
			if (mp[o+x-1][y-1] && mp[o+x+1][y-1]) {
				mp[o+x][y] = true;
				return rec(i+1, mp, N, X, Y);
			}
			if (mp[o+x-1][y-1]) {
				while (y > 0 && !mp[o+x+1][y-1]) {
					y--;
					x++;
				}
				mp[o+x][y] = true;
				return rec(i+1, mp, N, X, Y);
			} else if (mp[o+x+1][y-1]) {
				while (y > 0 && !mp[o+x-1][y-1]) {
					y--;
					x--;
				}
				mp[o+x][y] = true;
				return rec(i+1, mp, N, X, Y);
			} else {
				int tx = x;
				int ty = y;
				while (y > 0 && !mp[o+x-1][y-1]) {
					y--;
					x--;
				}
				mp[o+x][y] = true;
				pair<ll, ll> p1 = rec(i+1, mp, N, X, Y);
				mp[o+x][y] = false;
				x = tx;
				y = ty;
				while (y > 0 && !mp[o+x+1][y-1]) {
					y--;
					x++;
				}
				mp[o+x][y] = true;
				pair<ll, ll> p2 = rec(i+1, mp, N, X, Y);
				mp[o+x][y] = false;
				return make_pair(p1.first+p2.first, p1.second+p2.second);
			}
		} else {
			y -= 2;
		}
	}
}

double solve2(int N, int X, int Y) {
	if (abs(X) >= 25 || Y > 48)
		return 0.0;
	bool mp[50][50] = {};
	pair<ll, ll> p = rec(0, mp, N, X, Y);
	return (double)p.first/p.second;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, X, Y;
		cin >> N >> X >> Y;
		double ans = solve(N, X, Y);
		printf("Case #%d: %.12f\n", i+1, ans);
	}
}
