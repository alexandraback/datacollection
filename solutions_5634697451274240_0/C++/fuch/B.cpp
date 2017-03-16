#define _SCL_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 

#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX_N = 1 << 7;

char str[MAX_N];

int solve()
{
	int n = strlen(str);
	int f[MAX_N][2];
	for (int i = 0; i <= n; ++i)
	{
		f[i][0] = f[i][1] = MAX_N * 3;
	}
	f[0][0] = f[0][1] = 0;
	int d[MAX_N];
	for (int i = 0; i < n; ++i)
	{
		d[i] = (str[i] == '+') ? 1 : 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int k = 0; k < 2; ++k)
		{
			for (int j = i - 1; j >= 0 && d[j] == k; --j)
			{
				f[i][k] = std::min(f[i][k], f[j][1 - k] + (j == 0 ? 0 : 1));
			}
		}
		f[i][1 - d[i - 1]] = std::min(f[i][1 - d[i - 1]], f[i][d[i - 1]] + 1);
	}
	return f[n][1];
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		scanf("%s", str);
		int ans = solve();
		printf("Case #%d: %d\n", cs, ans);
	}
	return 0;
}