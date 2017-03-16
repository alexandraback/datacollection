#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define y0 isdnfviu
#define y1 asinhiv
#define fst first
#define snd second
#define count sdifnsugh

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	for (int g = 1; g <= t; g++)
	{
		cout << "Case #" << g << ": ";
		int n, m, k;
		cin >> n >> m >> k;
		if (min(n, m) <= 2)
		{
			cout << k << endl;
			continue;
		}
		int maxim = 0;
		int ans2 = k;
		for (int i = 1; i <= n - 2; i++)
			for (int j = 1; j <= m - 2; j++)
			{
				if ((i + 2) * (j + 2) - 4 <= k)
				{
					maxim = max(maxim, i * j);
				}
			}
		for (int i = 1; i <= n - 2; i++)
			for (int j = 1; j <= m - 2; j++)
			{
				if ((i + 2) * (j + 2) - 4 >= k)
				{
					ans2 = min(ans2, 2 * (i + j));
					int c = 2;
					if (min(i, j) > 1)
						c = 4;
					for (int h = 1; h <= c; h++)
						if ((i + 2) * (j + 2) - 4 >= k + 2 * h)
							ans2 = min(ans2, 2 * (i + j) - h);
				}
			}
		//cout << n << " " << m << " " << k << " " << min(k - maxim, ans2) << endl;
		cout << min(k - maxim, ans2) << endl;
	}
	return 0;
}
