#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <cmath>

using namespace std;
typedef long long int ll;
const int inf = INT_MAX;
const int max_class = 1000;
int n_class;
int conn[max_class][max_class];
int yes;
int visit[max_class];
void input(void)
{
	int i, j, k;
	scanf("%d\n", &n_class);
	for (i = 0; i < n_class; i++)
		for (j = 0; j < n_class; j++)
			conn[i][j] = -1;

	for (i = 0; i < n_class; i++) {
		int n;
		scanf("%d", &n);
		if (!n) continue;
		for (j = 0; j < n; j++) {
			int c;
			scanf("%d", &c);
			c--;
			conn[i][c] = 1;
		}
	}

	// for (i = 0; i < n_class; i++) {
	// 	for (j = 0; j < n_class; j++)
	// 		printf("%d ", conn[i][j]);
	// 	printf("\n");
	// }
	// printf("\n");
}

void output(int icase)
{
	int i, j, k;
	printf("Case #%d: %s", icase + 1, yes == 1 ? "yes\n" : "no\n");
}

int dfs(int idx)
{
	int i;
	if (visit[idx])
		return 0;
	visit[idx] = 1;
	for (i = 0; i < n_class; i++)
		if (conn[idx][i])
			if (dfs(i) == 0)
				return 0;
	return 1;
}

void solve(void)
{
	int i, j, k;
	for (i = 0; i < n_class; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i) == 0) {
			yes = 0;
			return;
		}
	}
	yes = 1;
}

int main()
{
	int n_case;
	scanf("%d", &n_case);
	for (int i = 0; i < n_case; i++) {
		input();
		solve();
		output(i);
	}
	return 0;
}
