/*
* Problem: 
* Author: Leo Yu
* Time: 
* State: SOLVED
* Memo: 
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link

double	C[5005][5005], f[5005][5005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif

/*	C[0][0] = 1;
	for (int i = 1; i <= 5000; ++ i)
	{
		C[i][0] = C[i - 1][0] / 2;
		for (int j = 1; j <= 5000; ++ j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) / 2;
	}
*/	int T = read();
	for (int t = 1; t <= T; ++ t)
	{
		printf("Case #%d: ", t);
		int N = read(), X = read(), Y = read();
		X = abs(X), Y = abs(Y);
		int S = (X + Y) / 2;
		for (int i = 0; i < S; ++ i)
			N -= i * 4 + 1;
		if (N < Y + 1)
		{
			printf("0.0\n");
			continue;
		}
		
		if (N >= S * 2 + Y + 1)
		{
			printf("1.0\n");
			continue;
		}
		if (Y == S * 2)
		{
			if (N >= S * 4 + 1)	printf("1.0\n");
			else	printf("0.0\n");
			continue;
		}
		//cout << N << endl;
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int i = 0; i < N; ++ i)
			for (int j = 0; j <= i; ++ j)	if (f[i][j])
			{
				if (j < 2 * S && (i - j) < 2 * S)
				{
					f[i + 1][j] += f[i][j] / 2;
					f[i + 1][j + 1] += f[i][j] / 2;
				}
				else	if (j < 2 * S)
				{
					f[i + 1][j + 1] += f[i][j];
				}
				else	if ((i - j) < 2 * S)
				{
					f[i + 1][j] += f[i][j];
				}
				else	f[i + 1][j + 1] += f[i][j];
			}
		double ans = 0;
		for (int i = Y + 1; i <= S * 2 + 1; ++ i)	ans += f[N][i];
		printf("%.10lf\n", ans);
	}

	return 0;
}

