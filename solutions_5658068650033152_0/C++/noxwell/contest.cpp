#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <sstream>
#include <algorithm>

#define INF 2e9
#define mp make_pair
#define pb push_back

using namespace std;

int nn, mm;

int f[30][30][1000];

int brute(int p, int k, int en)
{
	if (p == mm)
	{
		if(k == 2) return en + k;
		else return 0;
	}
	if (f[p][k][en] != -1) return f[p][k][en];
	en += k;
	int res = brute(p + 1, k, en);
	if (k > 1) res = max(res, brute(p + 1, k - 1, en));
	if (k > 2) res = max(res, brute(p + 1, k - 2, en));
	if (k < nn) res = max(res, brute(p + 1, k + 1, en));
	if (k < nn - 1) res = max(res, brute(p + 1, k + 2, en));
	return f[p][k][en] = res;
}

int get_ans(int n, int m, int k)
{
	if (n == 1 || m == 1 || k == 1 || k == 2 || k == 3)
	{
		return k;
	}
	nn = n;
	for (int i = 2; i <= m; i++)
	{
		mm = i;
		for (int j = 2; j < n; j++)
		{
			memset(f, -1, sizeof f);
			int br = brute(1, j, 0);
			if ((k % 2) && br == (k - 1))
			{
				return 2 * i + 1;
			}
			if (br >= k)
				return 2 * i;
		}
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	int n, m, k;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cout << "Case #" << tt + 1 << ": ";
		cin >> n >> m >> k;
		cout << get_ans(n + 1, m + 1, k);
		cout << endl;
	}
	return 0;
}