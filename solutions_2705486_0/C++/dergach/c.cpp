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
#include <iostream>
using namespace std;

char a[600005][55];
int len[600005];
char s[4005];
int dp[55][55];
int n;

int solve(int i, int j)
{
	if(dp[i][j] != -1) return dp[i][j];
	if(i == n) return 0;
	int L = j;
	if(L == 53)
		L = -20;
	int res = 123456;
	for(int k = 0; k < 521196; k++)
	{
		if((a[k][0] != s[i] && i - L < 5) || i + len[k] > n)
			continue;
		int L2 = L;
		int cnt = 0;
		int m;
		for(m = 0; m < len[k]; m++)
		{
			if(s[i+m] != a[k][m])
			{
				if(i + m - L2 < 5)
					break;
				cnt++;
				L2 = i + m;
			}
		}
		if(m == len[k])
		{
			if(L2 >= 0)
				res = min(res, cnt + solve(i + len[k], L2));
			else
				res = min(res, cnt + solve(i + len[k], 53));
		}
	}
	return dp[i][j] = res;
}

int main()
{
	freopen("garbled_email_dictionary.txt", "r", stdin);
	for(int i = 0; i < 521196; i++)
	{
		gets(a[i]);
		len[i] = strlen(a[i]);
	}

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	gets(s);
	for(int t = 1; t <= T; t++)
	{
		gets(s);
		n = strlen(s);
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: %d\n", t, solve(0, 53));
	}
	return 0;
}