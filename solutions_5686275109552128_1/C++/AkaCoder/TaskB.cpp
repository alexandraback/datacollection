#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>

using namespace std;
#define LL long long
#define FILES freopen("input.in" ,"r", stdin); freopen("input.out", "w", stdout);
#define FASTER ios::sync_with_stdio(0);



int cnt[1234][1234];

int f(int x, int y)
{
	if (y >= x) return 0;
	return x / y + (x % y != 0) - 1;
}
void precalc()
{
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			cnt[i][j] = f(i, j);
		}
	}
}

int main()
{
	FILES;
	FASTER;
	int T;
	cin >> T;

	precalc();


	for (int test = 1; test <= T; test++)
	{
		int d;
		cin >> d;
		vector <int> p(d);
		int minp, maxp;
		minp = 1001;
		maxp = -1;
		for (int i = 0; i < d; i++)
		{
			cin >> p[i];
			minp = min(minp, p[i]);
			maxp = max(maxp, p[i]);
		}
		int ans = 1e9;

		for (int i = 1; i <= maxp; i++)
		{
			int t = 0;

			for (int j = 0; j < p.size(); j++)
			{
				t += cnt[p[j]][i];
			}
			ans = min(ans, t + i);
		}
		cout << "Case #" << test << ": " << ans << '\n';
	}
}
