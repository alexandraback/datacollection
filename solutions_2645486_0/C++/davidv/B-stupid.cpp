#include <cstdio>
#include <algorithm>
using namespace std;

int dp[11][6];
int N, R, E;
int v[10];

void doCase()
{
	scanf("%d %d %d", &E, &R, &N);
	for (int i=0; i<N; i++)
		scanf("%d", &v[i]);
	
	for (int i=0; i<=E; i++)
	{
		dp[0][i] = 0;
	}
	
	for (int j=0; j<N; j++)
	{
		for (int i=0; i<=E; i++)
		{
			dp[j+1][i] = 0;
			for (int k=0; k<=i; k++)
			{
				dp[j+1][i] = max(dp[j+1][i], dp[j][min(E,i-k+R)]+k*v[N-j-1]);
			}
		}
	}
	
	printf("%d\n", dp[N][E]);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		printf("Case #%d: ", i);
		doCase();
	}
	return 0;
}
