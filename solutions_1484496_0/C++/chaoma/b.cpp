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
const int max_num = 20;
int n_num;
int num[max_num];

int sub_num[max_num];
int n_sub;
int sel[max_num];
int possible;
void input(void)
{
	int i, j, k;
	scanf("%d", &n_num);
	for (i = 0; i < n_num; i++)
		scanf("%d", num + i);
}

void output(int icase)
{
	int i, j, k;
	printf("Case #%d:\n", icase + 1);
	if (!possible) printf("Impossible\n");
	else {
		for (i = 0; i < n_sub; i++)
			if (sel[i]) printf("%d ", sub_num[i]);
		printf("\n");

		for (i = 0; i < n_sub; i++)
			if (!sel[i]) printf("%d ", sub_num[i]);
		printf("\n");
	}
	
}

int dfs(int sub_num_idx, int sub_s, int s, int n_sub)
{
	if (sub_num_idx == n_sub) return 0;
	if (sub_s == s) {
		return 1;
	}
	sel[sub_num_idx] = 1;
	if (dfs(sub_num_idx + 1, sub_s + sub_num[sub_num_idx], s, n_sub)) return 1;

	sel[sub_num_idx] = 0;
	if (dfs(sub_num_idx + 1, sub_s, s, n_sub)) return 1;
	return 0;
}

int calc(int idx, int n)
{
	int i, j, k;
	int s = 0;
	for (i = 0; i < n; i++)
		s += sub_num[i];
	if (s % 2 != 0) return 0;
	s /= 2;

	n_sub = n;
	if (dfs(0, 0, s, n)) return 1;
	return 0;
}

int sel_sub_num(int n_sub, int idx, int n)
{
	if (idx >= n_num) return 0;
	if (n_sub == n) {
		if (calc(0, n)) return 1;
		return 0;
	}

	sub_num[n_sub] = num[idx];
	if (sel_sub_num(n_sub + 1, idx + 1, n)) return 1;
	if (sel_sub_num(n_sub, idx + 1, n)) return 1;
	return 0;

}

void solve(void)
{
	int i, j, k;
	int n;
	for (n = 3; n <= n_num; n++) {
		if (sel_sub_num(0, 0, n)) break;
	}

	if (n <= n_num)
		possible = 1;
	else
		possible = 0;
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
