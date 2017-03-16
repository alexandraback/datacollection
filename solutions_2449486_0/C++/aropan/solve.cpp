#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	int _t;
	scanf("%d\n", &_t);
	for (int t = 1; t <= _t; t++)
	{
		printf("Case #%d: ", t);
		int n, m;
		scanf("%d %d", &n, &m);
		int r[n], c[m];
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		int a[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &a[i][j]);
				r[i] = max(r[i], a[i][j]);
				c[j] = max(c[j], a[i][j]);
			}
		bool flg = true;
		for (int i = 0; i < n && flg; i++)
			for (int j = 0; j < m && flg; j++)
				flg &= a[i][j] >= min(r[i], c[j]);
		puts(flg? "YES" : "NO");
	}

	return 0;
}
