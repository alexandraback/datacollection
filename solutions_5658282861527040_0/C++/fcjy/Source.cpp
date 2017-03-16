#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int A, B, C;
long long dp[50][10];

long long dfs( int p, int st )
{
	if( p == -1 )
	{
		if( st == 7 )	return 1;
		return 0;
	}
	if( dp[p][st] != -1 )	return dp[p][st];

	long long res = 0;

	for( int a = 0; a < 2; ++a )
	{
		if( !(st&1) && !(A&(1<<p)) && a == 1 )	continue; 
		for( int b = 0; b < 2; ++b )
		{
			if( !(st&2) && !(B&(1<<p)) && b == 1 )	continue; 
			
			int c = (a&b);
			if( !(st&4) && !(C&(1<<p)) && c == 1 )	continue;

			int vst = st;
			if( (A&(1<<p)) && a == 0 )	vst |= 1;
			if( (B&(1<<p)) && b == 0 )	vst |= 2;
			if( (C&(1<<p)) && c == 0 )	vst |= 4;

			res += dfs(p-1, vst);
		}
	}

	return dp[p][st] = res;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	int T, cases = 1;

	scanf("%d", &T);
	while( T-- )
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d %d %d", &A, &B, &C);
		printf("Case #%d: %lld\n", cases++, dfs(31, 0));
	}

	return 0;
}