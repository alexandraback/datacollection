#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

#pragma comment(linker,"/STACK:100000000")

int N;

int dp[4050][10];
char dict[530000][20];
int len[530000];
char s[4050];

void solve(int T)
{
	int i, j, u;
	scanf("%s", s + 1);
	int l = strlen(s + 1) + 1;
	memset(dp, 0x3f, sizeof(dp));
	for (i = 0; i < 5; ++i)
		dp[0][i] = 0;
	for (i = 1; i < l; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (i - len[j] < 0)
				continue;
			int prv = -5;
			int fst = (int)1e9;
			int cnt = 0;
			for (u = 0; u < len[j]; ++u)
				if (dict[j][u] != s[i - len[j] + u + 1])
				{
					if (u - prv < 5)
						break;
					if (prv < 0)
						fst = u;
					prv = u;
					cnt++;
				}
			if (u < len[j])
				continue;
			int ii = min(i - prv, 4);
//			printf("%s %d\n", dict[j], cnt);
			dp[i][ii] = min(dp[i][ii], dp[i - len[j]][max(4 - fst, 0)] + cnt);
//			printf("%d\n", dp[i][ii]);
		}
		for (j = 3; j >= 0; --j)
			dp[i][j] = min(dp[i][j], dp[i][j + 1]);
//		cerr << i << endl;
	}
	printf("Case #%d: %d\n", T, dp[l - 1][0]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
#endif
	int i, T;
	i = 0;
	freopen("dict.txt", "r", stdin);
	while (gets(dict[i]))
	{
		len[i] = strlen(dict[i]);
		if (len[i] > 15)
			throw 42;
		i++;
	}
	N = i;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (i = 0; i < T; ++i)
		solve(i + 1);
	return 0;
}