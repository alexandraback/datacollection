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

int dp[55][55][2600];

void solve(int R, int C, int M) {
	memset(dp, -1, sizeof(dp));
	if (M == R*C-1) {
		char c;
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				if (x == 0 && y == 0)
					c = 'c';
				else
					c = '*';
				cout << c;
			}
			cout << endl;
		}
		return;
	}
	if (R == 1) {
		char c;
		for (int x = 0; x < C; x++) {
			if (x == 0)
				c = 'c';
			else if (x >= C-M)
				c = '*';
			else
				c = '.';
			cout << c;
		}
		cout << endl;
		return;
	}
	if (C == 1) {
		char c;
		for (int y = 0; y < R; y++) {
			if (y == 0)
				c = 'c';
			else if (y >= R-M)
				c = '*';
			else
				c = '.';
			cout << c << endl;
		}
		return;
	}
	if (M > R*C-4) {
		cout << "Impossible" << endl;
		return;
	}
	for (int y = 0; y <= R; y++) {
		dp[C][y][0] = y;
	}
	for (int x = 0; x < C; x++) {
		if (C > 1 && x == C-2)
			continue;
		for (int y = 0; y <= R; y++) {
			if (R > 1 && y == 1)
				continue;
			int m = R - y;
			if (C > 1 && x == C-1)
				m += R - y;
			for (int w = 0; w <= y; w++) {
				for (int z = 0; z <= (x+1)*R; z++) {
					if (z+m > M)
						break;
					int pr = (C > 1 && x == C-1 ? C-x+1 : C-x);
					if (dp[pr][w][z] >= 0) {
						dp[C-1-x][y][z+m] = w;//dp[pr][w][z];
						//printf("dp[%d][%d][%d]=%d\n", C-1-x, y, z+m, dp[C-1-x][y][z+m]);
					}
				}
			}
		}
	}
	for (int w = 0; w <= R; w++) {
		if (dp[0][w][M] < 0) {
			continue;
		}
		char c;
		for (int y = 0; y < R; y++) {
			int k = w;
			int m = M;
			for (int x = 0; x < C; x++) {
				if (x == 0 && y == 0)
					c = 'c';
				else if (y < k)
					c = '.';
				else
					c = '*';
				cout << c;
				if (x == 1) {
					int nk = dp[0][k][m];
					m -= (R-k)*2;
					k = nk;
				} else if (x > 1) {
					int nk = dp[x][k][m];
					m -= R-k;
					k = nk;
				}
			}
			cout << endl;
		}
		return;
	}
	cout << "Impossible" << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int R, C, M;
		cin >> R >> C >> M;
		cout << "Case #" << i+1 << ":" << endl;
		solve(R, C, M);
	}
}
