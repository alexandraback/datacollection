#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

//#include <bits/stdc++.h>

using namespace std;

long long rev(long long N)
{
	long long x = 0;
	
	while(N)
	{
		x = x*10 + N%10;
		N/= 10;
	}
	
	return x;
}

long long dp[1000006];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output1.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	dp[1] = 1;
	
	for(int i=2; i<=1000000; i++)
	{
		dp[i] = dp[i-1] + 1;
		
		if(i%10!=0 && rev(i)<i)
			dp[i] = min(dp[i], dp[rev(i)] + 1);
	}
	
	for(int test = 1; test<=T; test++)
	{
		printf("Case #%d: ", test);
		
		long long N;
		scanf("%lld", &N);
		
		printf("%lld\n", dp[N]);
	}

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
