#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

int a[100][100];
int cur[100][100];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, i, j, k;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int n, m;
		cin >> n >> m;
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				cin >> a[i][j];

		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				cur[i][j] = 100;

		for(i = 0; i < n; i++)
		{
			int mx = 0;
			for(j = 0; j < m; j++)
				mx = max(mx, a[i][j]);
			for(j = 0; j < m; j++)
				cur[i][j] = min(cur[i][j], mx);
		}
		for(j = 0; j < m; j++)
		{
			int mx = 0;
			for(i = 0; i < n; i++)
				mx = max(mx, a[i][j]);
			for(i = 0; i < n; i++)
				cur[i][j] = min(cur[i][j], mx);
		}

		printf("Case #%d: ", t);
		bool yes = true;
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				if (cur[i][j] != a[i][j])
					yes = false;
		puts(yes ? "YES" : "NO");

	}

	return 0;
}