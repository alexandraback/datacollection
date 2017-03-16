// Alex Fetisov

#include <cstdio>

void initf() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
}

#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <string>

using namespace std;

const string BAD = "Too Bad";

int n;
//set < pair < pair < int, int >, int > > q1, q2;
int a[21];
int b[11];

int dp[1<<10][1<<10];
int M;

int bc[1<<10];

int rec(int m1, int m2) {
	if (m1 == M && m2 == M) {
		return 0;
	}
	if (dp[m1][m2] != -1) {
		return dp[m1][m2];
	}
	int ret = 1000000;
	int numStars = bc[m1] + bc[m2];
	for (int i = 0; i < n; ++i) {
		if (a[i] <= numStars) {
			if (!(m1 & (1 << i))) {
				ret = min(ret, 1 + rec(m1 | (1 << i), m2));
			}	
		}
		if (b[i] <= numStars) {
			if (!(m2 & (1 << i))) {
				ret = min(ret, 1 + rec(m1 | (1 << i), m2 | (1 << i)));
			}
		}
	}
	dp[m1][m2] = ret;
	return ret;
}

void solve() {
	bc[0] = 0;
	for (int i = 1; i < (1 << 10); ++i) {
		bc[i] = bc[i>>1] + (i & 1);		
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = x;
		b[i] = y;
	}
	M = (1 << n) - 1;
	memset(dp, -1, sizeof dp);
	int ret = rec(0, 0);
	if (ret == -1 || ret >= 1000000) {
		cout << BAD << endl;
	} else {
		cout << ret << endl;
	}
}

int main() {
	initf();
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; ++test) {
		printf("Case #%d: ", test);
		solve();
	}
	return 0;
}