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

int N;
char	a[4005], dic[621196][21];
int	len[621196], f[4005][5];

int main()
{
	freopen("garbled_email_dictionary.txt", "r", stdin);
	for (int i = 1; i <= 521196; ++ i)
	{
		scanf("%s", dic[i]);
		len[i] = strlen(dic[i]);
	}
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif

	int T = read();
	for (int t = 1; t <= T; ++ t)
	{
		scanf("%s", a + 1);
		N = strlen(a + 1);
		memset(f, 66, sizeof(f));
		f[0][4] = 0;
		for (int i = 1; i <= N; ++ i)
		for (int d = 0; d <= 4; ++ d)	if (f[i - 1][d] < 1 << 30)
		{
			for (int j = 1; j <= 521196; ++ j)	if (i + len[j] - 1 <= N)
			{
				int last = - d - 1, cost = 0;
				bool	flag = 1;
				for (int k = 0; k < len[j]; ++ k)
					if (a[i + k] != dic[j][k])
					{
						if (k - last < 5)
						{
							flag = 0;
							break;
						}
						last = k;
						cost ++;
					}
				if (flag)	f[i + len[j] - 1][min(len[j] - last - 1, 4)] = min(f[i + len[j] - 1][min(len[j] - last - 1, 4)], f[i - 1][d] + cost);
			}
		}
		int ans = 1 << 30;
		for (int d = 0; d <= 4; ++ d)	ans = min(ans, f[N][d]);
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}

