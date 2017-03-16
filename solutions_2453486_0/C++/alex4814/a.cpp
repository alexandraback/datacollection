#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define EPS 1e-8
#define MAXN 10
#define PI acos(-1.0)

int T, blank;
char g[MAXN][MAXN];

int dia(char c)
{
	int f = 1;
	for (int i = 0; i < 4; ++i) {
		if (g[i][i] != c && g[i][i] != 'T') f = 0;
	}
	if (f) return f;
	f = 1;
	for (int i = 0; i < 4; ++i) {
		if (g[i][3 - i] != c && g[i][3 - i] != 'T') f = 0;
	}
	return f;
}

int row(int r, char c)
{
	for (int i = 0; i < 4; ++i) {
		if (g[r][i] != c && g[r][i] != 'T') return 0;
	}
	return 1;
}

int col(int r, char c)
{
	for (int i = 0; i < 4; ++i) {
		if (g[i][r] != c && g[i][r] != 'T') return 0;
	}
	return 1;
}

int win(char c)
{
	for (int i = 0; i < 4; ++i) {
		if (row(i, c)) return 1;
	}
	for (int i = 0; i < 4; ++i) {
		if (col(i, c)) return 1;
	}
	if (dia(c)) return 1;
	return 0;
}

int solve()
{
	if (win('X')) return 0;
	if (win('O')) return 1;
	if (blank) return 2;
	return 3;
}

int main()
{
	scanf("%d", &T);
	for (int n_case = 1; n_case <= T; ++n_case) {
		blank = 0;
		for (int i = 0; i < 4; ++i) {
			scanf("%s", g[i]);
			for (int j = 0; j < 4; ++j) {
				if (g[i][j] == '.') ++blank;
			}
		}
		printf("Case #%d: ", n_case);
		int ans_type = solve();
		if (ans_type == 0) {
			printf("X won\n");
		} else if (ans_type == 1) {
			printf("O won\n");
		} else if (ans_type == 2) {
			printf("Game has not completed\n");
		} else {
			printf("Draw\n");
		}
	}
	return 0;
}
