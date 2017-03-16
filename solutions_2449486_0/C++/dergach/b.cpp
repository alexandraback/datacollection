#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;

int a[105][105], b[105][105];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				b[i][j] = 100;
		for(int i = 0; i < n; i++)
		{
			int maxv = -1;
			for(int j = 0; j < m; j++)
				maxv = max(maxv, a[i][j]);
			for(int j = 0; j < m; j++)
				b[i][j] = min(maxv, b[i][j]);
		}
		for(int j = 0; j < m; j++)
		{
			int maxv = -1;
			for(int i = 0; i < n; i++)
				maxv = max(maxv, a[i][j]);
			for(int i = 0; i < n; i++)
				b[i][j] = min(maxv, b[i][j]);
		}
		bool ok = true;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(b[i][j] != a[i][j])
					ok = false;
		if(ok)
			printf("Case #%d: YES\n", t);
		else
			printf("Case #%d: NO\n", t);
	}
	return 0;
}