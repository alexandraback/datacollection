#pragma	comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-9

int n;
string a[1005], b[1005];
int dp[65555];

int solve(int mask)
{
	if(mask == (1 << n) - 1)
		return 0;
	if(dp[mask] != -1)
		return dp[mask];
	int res = -1;
	for(int i = 0; i < n; i++)
		if((mask & (1 << i)) == 0)
		{
			int ok1 = 0, ok2 = 0;
			for(int j = 0; j < n; j++)
				if((mask & (1 << j)) != 0)
				{
					if(a[i] == a[j] && b[i] != b[j])
						ok1 = 1;
					if(a[i] != a[j] && b[i] == b[j])
						ok2 = 1;
				}
			res = max(res, ok1 * ok2 + solve((mask | (1 << i))));
		}
	return dp[mask] = res;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: %d\n", t, solve(0));
	}
	return 0;
}
