#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

#define sz(x) ((int)(x.size()))
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl
#define forn(i, x) for (int i = 0; i < (int)(x); ++i)
#define all(x) x.begin(), x.end()
#define PATH "C:\\Users\\Malkav\\Desktop\\"

typedef long long ll;

const int N = 100;

int n, x, y;

long double solve() {
	if (x == 0 && y == 0) {
		return 1.0;
	}
	
	int lvl = 1;
	
	for (int cur_lvl = 2; ; ++cur_lvl) {
		int cur_side = cur_lvl * 2 - 1;
		int cur_total = cur_side * (cur_side + 1) / 2;
		if (cur_total > n) {
			lvl = cur_lvl - 1;
			break;
		}
	}
	
	int side = lvl * 2 - 1;
	int total = side * (side + 1) / 2;
	int left = n - total;
	
	int k = 2 * lvl;
	
	
	//y = k + x
	//y = k - x
	if (y < k + x && y < k - x) {
		return 1.0;
	}
	if (y > k + x || y > k - x) {
		return 0.0;
	}
	
	if (x == 0) {
		return 0.0;
	}
		
	int hole = side + 1;
	int need = y + 1;
		
	vector<vector<long double> > dp(hole + 1, vector<long double> (hole + 1, 0.0));
	dp[0][0] = 1.0;
	for (int i = 0; i <= left; ++i) {
		long double sum = 0.0;
		for (int L = 0; L <= min(i, hole); ++L) {
			int R = i - L;
			if (0 <= R && R <= hole) {
				sum += dp[L][R];
			}
		}
		for (int L = 0; L <= min(i, hole); ++L) {
			int R = i - L;
			if (0 <= R && R <= hole) {
				dp[L][R] /= sum;
			}
		}
		
		if (i == left) {
			break;
		}
		
		for (int L = 0; L <= min(i, hole); ++L) {
			int R = i - L;
			if (0 <= R && R <= hole) {
				if (L == hole) dp[L][R + 1] += dp[L][R];
				else if (R == hole) dp[L + 1][R] += dp[L][R];
				else {
					dp[L + 1][R] += dp[L][R] / 2;
					dp[L][R + 1] += dp[L][R] / 2;
				}
			}
		}
		
	}

	long double ans = 0.0;
	for (int L = need; L <= min(left, hole); ++L) {
		int R = left - L;
		if (0 <= R && R <= hole) {
			ans += dp[L][R];
		}
	}
	return ans;
}

int main() {
	freopen(PATH"b.in", "r", stdin);
	freopen(PATH"out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d %d %d", &n, &x, &y);
		printf("Case #%d: %.16lf\n", t, (double) solve());
	}
	return 0;
}