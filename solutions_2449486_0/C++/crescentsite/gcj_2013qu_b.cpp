#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <cstdio>
#include <cmath>
using namespace std;
int T, n, m;
int g[105][105];
int main(){
	int i, j, k, p, ans;
	cin >> T;
	for (k = 1; k <= T; k++)
	{
		cin >> n >> m;
		ans = 1;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				cin >> g[i][j];
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				for (p = 0; p < m; p++)
					if (g[i][j] < g[i][p])
						break;
				if (p != m)
				{
					for (p = 0; p < n; p++)
						if (g[i][j] < g[p][j])
							break;
					if (p != n)
					{
						ans = 0;
						i = n;
						j = m;
					}
				}
			}
		if (ans == 1)
			printf("Case #%d: YES\n", k);
		else printf("Case #%d: NO\n", k);
	}
}
