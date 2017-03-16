/* g++-4.8 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;
const int INF = 1 << 28;
int used;
int was[1 << 20];
int dp[1 << 20];

bool hit(int mask, int C, int W) {
	int cnt = 0;
	for (int i = 0; i < C; i++) {
		if (mask & (1 << i)) {
			if (cnt >= W) return false;
			cnt = 0;
		} else {
			cnt++;
		}
	}
	return cnt < W;
}

void free_space(int mask, int C, int opos, int& pos, int& length) {
	int lf, rg;
	for (lf = opos; lf >= 0 && !(mask & (1 << lf)); lf--);
	for (rg = opos; rg < C && !(mask & (1 << rg)); rg++);
	lf++;
	pos = opos - lf;
	length = rg - lf;
}

int dp_small[21][21][21][21];

bool valid(int length, int lf, int rg, int W) {
	return length >= W;
}

int f_small(int length, int lf, int rg, int W) {
	assert(rg - lf + 1 <= W);
	assert(lf < length);
	assert(rg < length);
	assert(W <= length);
	if (rg - lf + 1 == W) {
		return 0;
	}
	int &res = dp_small[length][lf][rg][W];
	if (res != -1) return res;
	res = INF;
	for (int i = 0; i < lf; i++) {
		if (rg - i + 1 > W) {
			res = min(res, f_small(length - i - 1, lf - i - 1, rg - i - 1, W) + 1);
		} else {
			if (valid(length - i - 1, lf - i - 1, rg - i - 1, W)) {
				res = min(res,
					max(
						f_small(length, i, rg, W) + (lf - i),
						f_small(length - i - 1, lf - i - 1, rg - i - 1, W) + 1
					)
				);
			} else {
				res = min(res, f_small(length, i, rg, W) + lf - i);
			}
		}
	}

	for (int j = rg + 1; j < length; j++) {
		if (j - lf + 1 > W) {
			res = min(res, f_small(j, lf, rg, W) + 1);
		} else {
			if (valid(j, lf, rg, W)) {
				res = min(res,
					max(
						f_small(length, lf, j, W) + j - rg,
						f_small(j, lf, rg, W) + 1
					)
				);
			} else {
				res = min(res, f_small(length, lf, j, W) + j - rg);
			}
		}
	}
	assert(res != INF);
	// cerr << "length " << length << " lf " << lf << " rg " << rg << " w " << W << " res = " << res << "\n";
	return res;
}

int f(int mask, int C, int W) {
	int &res = dp[mask];
	if (was[mask] == used) return res;
	res = INF;
	for (int i = 0; i < C; i++) {
		if (!(mask & (1 << i))) {
			if (hit(mask | (1 << i), C, W)) {
				int pos, length;
				free_space(mask, C, i, pos, length);
				res = min(res, f_small(length, pos, pos, W) + 1);
			} else {
				res = min(res, f(mask | (1 << i), C, W) + 1);
			}
		}
	}
	assert(res != INF);
	// cerr << "mask " << mask << " C " << C << " W " << W << " res " << res << "\n";
	return res;
}

int solve(int C, int W) {
	used++;
	return f(0, C, W);
}

int main() {
	memset(dp_small, -1, sizeof(dp_small));
	int T, tn = 0, R, C, W;
	cin >> T;
	while (T --> 0) {
		tn++;
		cin >> R >> C >> W;
		cerr << "Case #" << tn << "\n";
		int result = R * solve(C, W);
		cout << "Case #" << tn << ": " << result << "\n";
	}
}