#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;


double dp[5000][5000];


void ans(int t, double ans)
{
	printf("Case #%d: %.10lf\n", t, ans);
}


void solve(int t)
{
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	int cur = 1;
	int sum = 1;
	int cnt = 1;
	while(n > sum)
	{
		cur += 4;
		sum += cur;
		cnt++;
	}
	int onLast = cur - (sum - n);
//	printf("sum = %d, cur = %d, n = %d, onLast = %d\n", sum, cur, n, onLast);
	int lastLevel = cnt;
	if(x < 0)
		x = -x;
	int iny = y;
	while(y > 0)
	{
		y--;
		x++;
	}
	int ourLevel = x / 2 + 1;
	if(ourLevel < lastLevel)
	{
		ans(t, 1.);
		return;
	}
	if(ourLevel > lastLevel)
	{
		ans(t, 0.);
		return;
	}	         
	y = iny;
	n = 2 * lastLevel - 2;
	//printf("%d\n", n);
	if(y == n)
	{             
		if(onLast == cur)
			ans(t, 1.);
		else
			ans(t, 0.);
		return;	
	}
	if(onLast < y + 1)
	{
		ans(t, 0.);
		return;
	}
	double res = 0;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
//	printf("%d\n", onLast);
//	printf("%d %d\n", n, y);
	if(onLast == cur)
	{
		ans(t, 1.);
		return;
	}
	for(int i = 0; i <= n; i++)	
	{
		for(int j = 0; j <= n; j++)
		{
//			printf("%.4lf ", dp[i][j]);       
			if(i >= y + 1 && i + j == onLast)
			{
				res += dp[i][j];
//				printf("on %d %d\n", i, j);
			}

			if(i == n)
				dp[i][j + 1] += dp[i][j];
			else if(j == n)
				dp[i + 1][j] += dp[i][j];
			else
			{
				dp[i + 1][j] += dp[i][j] / 2;
				dp[i][j + 1] += dp[i][j] / 2;
			}
		}
//		printf("\n");
	}
	ans(t, res);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve(i + 1);
}