#define _USE_MATH_DEFINES

#ifdef ONLINE_JUDGE
#define FINPUT(file) 0
#define FOUTPUT(file) 0
#else
#define FINPUT(file) freopen(file,"r",stdin)
#define FOUTPUT(file) freopen(file,"w",stdout)
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

typedef long long ll;
static const int M = 110;
static const int N = 4;
static const int LEN = 51;
static const int MAX = 0x7fffffff;
static const int MIN = ~MAX;
static const double EPS = 1e-8;

int pos[8][2] = {
	{ 1, 0 },
	{ -1, 0 },
	{ 1, 1 },
	{ 0, 1 },
	{ -1, 1 },
	{ 1, -1 },
	{ 0, -1 },
	{ -1, -1 }
};

bool find = false;
int arr[LEN][LEN];

void dfs(int remain, int m, int start_x, int start_y, int x, int y, int limit_r, int limit_c, int ncase)
{
	if (find)
		return;
	arr[y][x] = 1;

	std::vector<int> prev_passed;
	bool ret = false;
	for (int i = 0; i < 8; i++) {
		int dir_x = pos[i][0];
		int dir_y = pos[i][1];
		if (x + dir_x < limit_c && x + dir_x >= 0
			&& y + dir_y < limit_r && y + dir_y >= 0) {
			if (arr[y + dir_y][x + dir_x] == 0) {
				remain--;
				prev_passed.push_back(i);
				arr[y + dir_y][x + dir_x] = 2;
			}
		}
	}

	if (remain < m) {
		ret = true;
	}
	else if (remain == m) {
		printf("Case #%d:\n", ncase);
		for (int i = 0; i < limit_r; i++) {
			for (int j = 0; j < limit_c; j++) {
				if (i == start_y && j == start_x) {
					printf("c");
				}
				else if (arr[i][j] == 0) {
					printf("*");
				}
				else {
					printf(".");
				}
			}
			printf("\n");
		}
		find = true;
		ret = true;
	}

	if (!ret) {
		for (int i = 0; i < 8; i++) {
			int dir_x = pos[i][0];
			int dir_y = pos[i][1];
			if (x + dir_x < limit_c && x + dir_x >= 0
				&& y + dir_y < limit_r && y + dir_y >= 0) {
				if (arr[y + dir_y][x + dir_x] != 1) {
					dfs(remain, m, start_x, start_y, dir_x + x, dir_y + y, limit_r, limit_c, ncase);
					if (find) {
						break;
					}
				}
			}
		}
	}

	arr[y][x] = 2;
	for (int i = 0; i < prev_passed.size(); i++) {
		int tmp = prev_passed[i];
		int dir_x = pos[tmp][0];
		int dir_y = pos[tmp][1];
		arr[y + dir_y][x + dir_x] = 0;
	}
	return;
}
void solve(int ncase)
{
	int r, c, m;
	scanf("%d %d %d", &r, &c, &m);

	bool impossible = false;

	if (r * c - m == 1) {

	}
	else if (r > 1 && c > 1) {
		if (r * c - 4 < m) {
			impossible = true;
		}
	}
	else {
		if (r * c - 2 < m) {
			impossible = true;
		}
	}

	if (impossible)
		printf("Case #%d:\nImpossible\n", ncase);
	else {
		if (r * c - m == 1) {
			printf("Case #%d:\n", ncase);
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (i == 0 && j == 0) {
						printf("c");
					}
					else {
						printf("*");
					}
				}
				printf("\n");
			}
		}
		else if (r == 1) {
			printf("Case #%d:\n", ncase);
			printf("c");
			for (int i = 1; i < c; i++) {
				if (i < c - m)
					printf(".");
				else
					printf("*");
			}
			printf("\n");
		}
		else if (c == 1){
			printf("Case #%d:\n", ncase);
			printf("c\n");
			for (int i = 1; i < r; i++) {
				if (i < r - m)
					printf(".\n");
				else
					printf("*\n");
			}
		}
		else {
			find = false;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					memset(arr, 0, sizeof(arr));
					dfs(r*c - 1, m, j, i, j, i, r, c, ncase);
					if (find) {
						break;
					}
				}
			}

			if (!find) {
				printf("Case #%d:\nImpossible\n", ncase);
			}
		}
	}
}

int main()
{
	FINPUT("in.txt");
	FOUTPUT("out.txt");

	int c, ncase = 1;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		solve(ncase++);
	}
	return 0;
}