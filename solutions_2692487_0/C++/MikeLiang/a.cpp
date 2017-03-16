#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 1000006;
int num[M], dp[M];

int main()
{
	int T, a, n;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d %d", &a, &n);
		for(int i=0; i<n; i++)
			scanf("%d", &num[i]);

		sort(num, num + n);
		printf("Case #%d: ", cas);
		if(a == 1)
			printf("%d\n", n);
		else
		{
			memset(dp, 0, sizeof(dp));
			for(int i=0; i<n; i++)
			{
				int tk = 0;
				while(a <= num[i])
				{
					a += a-1;
					tk ++;
				}
				a += num[i];
				if(a > num[n-1])
					a = num[n-1] + 1;
				dp[i] = tk;
			}

			int ans = 0, kk = 0;
			dp[n] = 0;
			for(int i=n-1; i>=0; i--)
			{
				dp[i] = min(dp[i] + dp[i+1], n - i);
			}
			printf("%d\n", dp[0]);
		}
	}
	return 0;
}

