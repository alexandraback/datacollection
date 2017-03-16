#include <cstdio>
#include <iostream> 
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n, m;
int mas[105][105];
int maxi[105];
int maxj[105];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for(int tt = 0; tt < t; ++tt)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf("%d", &mas[i][j]);

		memset(maxi, 0, sizeof(maxi));
		memset(maxj, 0, sizeof(maxj));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				maxi[i] = max(maxi[i], mas[i][j]);
		for(int j = 0; j < m; ++j)
			for(int i = 0; i < n; ++i)
				maxj[j] = max(maxj[j], mas[i][j]);

		bool ok = 1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(min(maxi[i], maxj[j]) != mas[i][j])
					ok = 0;
		printf("Case #%d: %s\n", tt+1, ok ? "YES" : "NO");
	}

	return 0;
}