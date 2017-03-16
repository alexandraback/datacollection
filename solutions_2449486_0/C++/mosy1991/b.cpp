#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <bitset>
#include <ctime>
using namespace std;

typedef long long LL;

#define MAXN 105
int a[MAXN][MAXN];
int row[MAXN];
int col[MAXN];
int n, m;

int main()
{
	int T, cases = 0;
	scanf("%d", &T);
	while (T--)
	{
		printf("Case #%d: ", ++cases);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &a[i][j]);
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				row[i] = max(row[i], a[i][j]);
				col[j] = max(col[j], a[i][j]);
			}
		bool flag = true;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j] != min(row[i], col[j]))
					flag = false;
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
