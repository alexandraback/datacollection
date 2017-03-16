#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100
#define LARGEST 1000000

int v[MAX];
int n;
int dp[100][LARGEST + 1];

int f(int i, int c)
{
	if (i == n || c > LARGEST)
		return 0;
	else if (dp[i][c] != -1)
		return dp[i][c];
	else if (v[i] < c)
	{
		c += v[i];
		int res = f(i + 1, c);
		dp[i][c] = res;
		return res;
	}
	else
	{
		int res;
		if (c + c - 1 != c)
			res = 1 + min(f(i, c + c - 1), f(i + 1, c));
		else
			res = 1 + f(i + 1, c);
		dp[i][c] = res;
		return res;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int a;
		scanf("%d", &a);
			
		scanf("%d", &n);
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &v[j]);
		}
		
		sort(v, v + n);
		
		memset(dp, -1, sizeof(dp));
		
		printf("Case #%d: %d\n", i + 1, f(0, a));
	}
	
	return 0;
}
