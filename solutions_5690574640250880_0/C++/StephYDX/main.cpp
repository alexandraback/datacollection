#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
//using namespace std;


void fill(int R, int C, char ans[][51], char ch) {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			ans[i][j] = ch;
		}
	}
}
bool solve(int R, int C, int M, int S, char ans[][51]) {
	if (M == 0) {
		fill(R, C, ans, '.');
		ans[0][0] = 'c';
		return true;
	}
	if (S == 1) {
		fill(R, C, ans, '*');
		ans[0][0] = 'c';
		return true;
	}
	if (R == 1) {
		fill(R, C, ans, '*');
		fill(R, S, ans, '.');
		ans[0][0] = 'c';
		return true;
	}
	if (S == 2 || S == 3 || S == 5 || S == 7) {
		return false;
	}
	if (R == 2) {
		if (S % 2 == 0) {
			fill(R, C, ans, '*');
			fill(R, S / 2, ans, '.');
			ans[0][0] = 'c';
			return true;
		}
		else {
			return false;
		}
	}
	fill(R, C, ans, '*');
	if (S < 2 * R) {
		fill(S / 2 - S % 2, 2, ans, '.');
		if (S % 2 == 1) {
			fill(3, 3, ans, '.');
		}
		ans[0][0] = 'c';
		return true;
	}
	if (S % R == 0) {
		fill(R, S / R, ans, '.');
		ans[0][0] = 'c';
		return true;
	}
	if (S % R > 1) {
		fill(R, S / R, ans, '.');
		fill(S % R, S / R + 1, ans, '.');
		ans[0][0] = 'c';
		return true;
	}
	if (S / R == 2) {
		fill(R - 1, 2, ans, '.');
		fill(3, 3, ans, '.');
		ans[0][0] = 'c';
		return true;
	}
	{
		fill(R, S / R, ans, '.');
		ans[R - 1][S / R - 1] = '*';
		ans[0][S / R] = '.';
		ans[1][S / R] = '.';
		ans[0][0] = 'c';
		return true;
	}
}
void transpose(int R, int C, char ans[][51]) {
	for (int i = 0; i < R || i < C; ++i) {
		for (int j = 0; j < i && j < R && j < C; ++j) {
			std::swap(ans[i][j], ans[j][i]);
		}
	}
}
int main(){
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		printf("Case #%d:", cas);
		int R, C, M;
		scanf("%d %d %d", &R, &C, &M);
		int S = R * C - M;
		bool swaped = false;
		if (R > C) {
			std::swap(R, C);
			swaped = true;
		}
		char ans[51][51];
		if (solve(R, C, M, S, ans)) {
			if (swaped) {
				transpose(R, C, ans);
				std::swap(R, C);
			}
			puts("");
			for (int i = 0;i < R; ++i) {
				ans[i][C] = 0;
				puts(ans[i]);
			}
		}
		else {
			printf("\nImpossible\n");
		}
	}
	return 0;
}
