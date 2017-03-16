#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 30;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m, k, p;
int board[MAXN][MAXN];
int lowN[MAXN], highN[MAXN];
int lowM[MAXN], highM[MAXN];

void build_board(int mask) {
	memset(board, 0, sizeof(board));

	memset(lowN, -1, sizeof(lowN));
	memset(lowM, -1, sizeof(lowM));
	memset(highN, -1, sizeof(highN));
	memset(highM, -1, sizeof(highM));

	p = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (mask & (1 << (i * m + j))) {
				board[i][j] = 1;
				p++;
				
				if (lowN[i] == -1) lowN[i] = j; else lowN[i] = min(lowN[i], j);
				if (lowM[j] == -1) lowM[j] = i; else lowM[j] = min(lowM[j], i);
				if (highN[i] == -1) highN[i] = j; else highN[i] = max(highN[i], j);
				if (highM[j] == -1) highM[j] = i; else highM[j] = max(highM[j], i);
			}
		}
}

int num_enclose() {
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 1) {
				res++;
				continue;
			}
			if (lowN[i] <= j && j <= highN[i] && lowM[j] <= i && i <= highM[j])
				res++;
		}
	return res;
}

void solve(int test_id) {
	cout << "Case #" << test_id << ": ";
	cin >> n >> m >> k;

	int res = k;
	for (int mask = 1; mask < (1 << (n * m)); ++mask) {
		build_board(mask);
		if (num_enclose() >= k) {
			res = min(res, p);
		}
	}

	cout << res << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int test_id = 1; test_id <= t; ++test_id)
		solve(test_id);
	return 0;
}
