#pragma comment (linker, "/STACK:268435456")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <functional>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>

using namespace std;
template <class T> T sqr(T a) { return a * a; }
const int maxn = 20;
const int maxm = 20;

int e, r;
int n;
int v[maxn];
int dp[maxn][maxm];

int solve()
{
	memset(dp, 0, sizeof dp);
	int result = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= e; j++)
			for (int k = 0; k <= j; k++)
			{
				int p = dp[i + 1][min(e, j - k + r)] = max(dp[i + 1][min(e, j - k + r)], dp[i][j] + k * v[i]);
				result = max(result, p);
			}
	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tn;
	cin >> tn;
	for (int tc = 0; tc < tn; tc++)
	{
		cin >> e >> r >> n;
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << "Case #" << tc + 1 << ": " << solve();
		cout << endl;
	}
	return 0;
}