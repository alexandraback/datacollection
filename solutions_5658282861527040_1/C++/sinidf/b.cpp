#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
typedef long long ll;

int A, B, K;
ll dp[30][2][2];

ll work()
{
	ll ans = 0;
	dp[29][1][1] = 1;
	dp[29][0][0] = 0;
	dp[29][0][1] = 0;
	dp[29][1][0] = 0;
	for (int i = 28; i >= 0; i--)
	{
		dp[i][0][0] = 0;
		dp[i][0][1] = 0;
		dp[i][1][0] = 0;
		dp[i][1][1] = 0;
		if (A & B & (1 << i))
		{
			if (K & (1 << i))
			{
				dp[i][1][1] += dp[i + 1][1][1];
			}
			else
			{
				dp[i][1][0] += dp[i + 1][1][1];
				dp[i][0][1] += dp[i + 1][1][1];
				dp[i][0][0] += dp[i + 1][1][1];
				ans += dp[i + 1][1][1] * ((A ^ (1 << i)) + 1) * ((B ^ (1 << i)) + 1);
			}
		}
		else if (A & (1 << i))
		{
			if (K & (1 << i))
			{
			}
			else
			{
				dp[i][0][1] += dp[i + 1][1][1];
				dp[i][1][1] += dp[i + 1][1][1];
			}
		}
		else if (B & (1 << i))
		{
			if (K & (1 << i))
			{
			}
			else
			{
				dp[i][1][0] += dp[i + 1][1][1];
				dp[i][1][1] += dp[i + 1][1][1];
			}
		}
		else
		{
			if (K & (1 << i))
			{
			}
			else
			{
				dp[i][1][1] += dp[i + 1][1][1];
			}
		}
		if (A & (1 << i))
		{
			if (K & (1 << i))
			{
				dp[i][1][0] += dp[i + 1][1][0];
			}
			else
			{
				dp[i][0][0] += dp[i + 1][1][0] * 2;
				dp[i][1][0] += dp[i + 1][1][0];
				ans += dp[i + 1][1][0] * ((A ^ (1 << i)) + 1) * (1 << i);
			}
		}
		else
		{
			if (K & (1 << i))
			{
			}
			else
			{
				dp[i][1][0] += dp[i + 1][1][0] * 2;
			}
		}
		if (B & (1 << i))
		{
			if (K & (1 << i))
			{
				dp[i][0][1] += dp[i + 1][0][1];
			}
			else
			{
				dp[i][0][0] += dp[i + 1][0][1] * 2;
				dp[i][0][1] += dp[i + 1][0][1];
				ans += dp[i + 1][0][1] * (1 << i) * ((B ^ (1 << i)) + 1);
			}
		}
		else
		{
			if (K & (1 << i))
			{
			}
			else
			{
				dp[i][0][1] += dp[i + 1][0][1] * 2;
			}
		}
		if (K & (1 << i))
		{
			dp[i][0][0] += dp[i + 1][0][0];
		}
		else
		{
			dp[i][0][0] += dp[i + 1][0][0] * 3;
			ans += dp[i + 1][0][0] * (1 << i) * (1 << i);
		}

		if (A & (1 << i))
		{
			A ^= 1 << i;
		}
		if (B & (1 << i))
		{
			B ^= 1 << i;
		}
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++)
	{
		scanf("%d%d%d", &A, &B, &K);
		A--, B--, K--;
		printf("Case #%d: %lld\n", ca, (ll)(A + 1) * (B + 1) - work());
	}
	return 0;
}
