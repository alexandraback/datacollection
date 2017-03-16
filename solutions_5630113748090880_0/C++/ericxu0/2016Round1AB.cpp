#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <complex>
#include <random>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int MAXN = 55;
int T, N;
int A[2 * MAXN][MAXN];
int grid[MAXN][MAXN];
bool used[2 * MAXN];
int ans[MAXN];

bool correct_row(int idx, int i)
{
	for (int j = 0; j < i; j++)
		if (grid[i][j] != A[idx][j])
			return false;
	return true;
}

bool correct_col(int idx, int i)
{
	for (int j = 0; j < i; j++)
		if (grid[j][i] != A[idx][j])
			return false;
	return true;
}

void go()
{
	int missing = -1, type = -1;
	for (int i = 0; i < N; i++)
	{
		int idx1 = -1, idx2 = -1;
		for (int j = 0; j < 2 * N - 1; j++)
		{
			if (used[j])
				continue;
			if (idx1 == -1 || A[j][i] < A[idx1][i])
			{
				idx1 = j;
				idx2 = -1;
			}
			else if (A[j][i] == A[idx1][i])
				idx2 = j;
		}

		used[idx1] = true;
		bool b1 = correct_row(idx1, i), b2 = correct_col(idx1, i);
		if (b1 && (!b2 || type == 0))
		{
			for (int j = 0; j < N; j++)
				grid[i][j] = A[idx1][j];
			if (idx2 == -1)
			{
				type = 1; //col
				missing = i;
			}
			else
			{
				used[idx2] = true;
				for (int j = 0; j < N; j++)
					grid[j][i] = A[idx2][j];
			}
		}
		else
		{
			for (int j = 0; j < N; j++)
				grid[j][i] = A[idx1][j];
			if (idx2 == -1)
			{
				type = 0; //row
				missing = i;
			}
			else
			{
				used[idx2] = true;
				for (int j = 0; j < N; j++)
					grid[i][j] = A[idx2][j];
			}
		}
	}

	if (type == 0)
	{
		for (int i = 0; i < N; i++)
			ans[i] = grid[missing][i];
	}
	else
	{
		for (int i = 0; i < N; i++)
			ans[i] = grid[i][missing];
	}
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	ios::sync_with_stdio(0);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int i = 0; i < 2 * N - 1; i++)
			for (int j = 0; j < N; j++)
				cin >> A[i][j];
		memset(grid, 0, sizeof(grid));
		memset(used, 0, sizeof(used));
		memset(ans, 0, sizeof(ans));

		go();
		cout << "Case #" << t << ":";
		for (int i = 0; i < N; i++)
			cout << " " << ans[i];
		cout << "\n";
	}

	return 0;
}