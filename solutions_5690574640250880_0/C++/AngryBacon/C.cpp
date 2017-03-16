#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

const int N = 50 + 10;

int r, c, m;
char ret[N][N];
int cnt[N];

int dfs(int tot, int row, int last)
{
	if (tot > r * c - m) {
		return false;
	}
	if (tot == r * c - m) {
		return true;
	}
	if (row == r) {
		return false;
	}

	for(int i = last; i >= 2; -- i) {
		cnt[row] = i;
		if (dfs(tot + i, row + 1, i))
			return true;
	}
	return false;
}

void output()
{
	for(int i = 0; i < r; ++ i) {
		for(int j = 0; j < c; ++ j) {
			putchar(ret[i][j]);
		}
		puts("");
	}
}

void solve(int test)
{
	printf("Case #%d:\n", test);
	cin >> r >> c >> m;
	for(int i = 0; i < r; ++ i) {
		for(int j = 0; j < c; ++ j) {
			ret[i][j] = '.';
		}
	}
	ret[0][0] = 'c';

	if (m == r * c - 1) {
		for(int i = 0; i < r; ++ i) {
			for(int j = 0; j < c; ++ j) {
				ret[i][j] = '*';
			}
		}
		ret[0][0] = 'c';
		output();
		return;
	}

	if (r == 1) {
		for(int i = 0; i < m; ++ i) {
			ret[0][c - 1 - i] = '*';
		}
		output();
		return;
	}
	if (c == 1) {
		for(int j = 0; j < m; ++ j) {
			ret[r - 1 - j][0] = '*';
		}
		output();
		return;
	}

	for(int first = c; first >= 2; -- first) {
		memset(cnt, 0, sizeof cnt);
		cnt[0] = cnt[1] = first;
		if (dfs(first * 2, 2, first)) {
			for(int i = 0; i < r; ++ i) {
				for(int j = 0; j < c; ++ j) {
					if (j >= cnt[i])
						ret[i][j] = '*';
				}
			}
			output();
			return;
		}
	}
	cout << "Impossible" << endl;

}

int main()
{
	//freopen("C-small-attempt0.in", "r", stdin); freopen("C-small-attempt0.out", "w", stdout);
	freopen("C-small-attempt1.in", "r", stdin); freopen("C-small-attempt1.out", "w", stdout);
	//freopen("C-large.in", "r", stdin); freopen("C-large.out", "w", stdout);
	int testcase;
	scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) 
		solve(i);
	fclose(stdout);
	return 0;
}
