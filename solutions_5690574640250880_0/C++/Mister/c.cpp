#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <cassert>
#include <climits>
using namespace std;
char ans[55][55];
int M, lef;
bool solve(int r, int c) {
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			ans[i][j] = '.';
	if (r == 1) {
		for (int i = 0; i < M; ++i) ans[0][i] = '*';
		return true;
	}
	if (lef == 1) {
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				ans[i][j] = '*';
		ans[r - 1][c - 1] = '.';
		return true;
	}
	if (r == 2) {
		if (M & 1) return false;
		if (lef == 2) return false;
		for (int j = 0; j < M / 2; ++j)
			ans[0][j] = ans[1][j] = '*';
		return true;
	}
	if (lef <= 8) {
		if (lef == 2 || lef == 3 || lef == 5 || lef == 7) return false;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				ans[i][j] = '*';
		ans[r - 1][c - 1] = ans[r - 1][c - 2] = ans[r - 2][c - 1] = ans[r - 2][c - 2] = '.';
		if (lef == 4) return true;
		ans[r - 1][c - 3] = ans[r - 2][c - 3] = '.';
		if (lef == 6) return true;
		ans[r - 3][c - 1] = ans[r - 3][c - 2] = '.';
		return true;
	}
	int rem = M, lastrow;
	for (int i = 0; i < r - 2; ++i)
		for (int j = 0; j < c; ++j) {
			if (!rem) continue;
			ans[i][j] = '*';
			lastrow = i;
			--rem;
		}
	if (!rem) {
		if (M % c == c - 1) {
			ans[lastrow][c - 2] = '.';
			ans[lastrow + 1][0] = '*';
			if (lastrow == r - 3) {
				ans[lastrow][c - 3] = '.';
				ans[lastrow + 2][0] = '*';
			}
		}
		return true;
	}
	if (rem & 1) {
		ans[lastrow][c - 1] = ans[lastrow][c - 2] = ans[lastrow][c - 3] = '.';
		rem += 3;
	}
	for (int j = 0; j < rem / 2; ++j)
		ans[lastrow + 1][j] = ans[lastrow + 2][j] = '*';
	return true;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int R, C;
		scanf("%d%d%d", &R, &C, &M);
		lef = R * C - M;
		bool flipped = false;
		if (R > C) {
			swap(R, C);
			flipped = true;
		}
		bool can = solve(R, C);
		printf("Case #%d:\n", cn);
		if (!can) printf("Impossible\n");
		else {
			ans[R - 1][C - 1] = 'c';
			if (!flipped) {
				for (int i = 0; i < R; ++i) {
					for (int j = 0; j < C; ++j)
						printf("%c", ans[i][j]);
					printf("\n");
				}
			} else {
				for (int i = 0; i < C; ++i) {
					for (int j = 0; j < R; ++j)
						printf("%c", ans[j][i]);
					printf("\n");
				}
			}
		}
	}
}

