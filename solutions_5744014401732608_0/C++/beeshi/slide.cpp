#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define D(x...) fprintf(stderr,x) 
#else
#define D(x...) 
#endif 
long long T, N, ans;
int main()
{
	freopen("infile.txt", "r", stdin);
	freopen("outfile.txt", "w", stdout);
	scanf("%d", &T);
	for(long long t=1; t<=T; t++)
	{
		long long M;
		long long ways[50];
		long long adj[55][55];
		for(int n=0; n<=50; n++)
		{
			for(int m=0; m<=50; m++)
			{
				adj[n][m] =0;
			}
		}
		scanf("%lld %lld", &N, &M);
		if(M> (long long)1<<(N-2))
		{
			printf("Case #%d: IMPOSSIBLE\n", t);
			continue;
		}
		printf("Case #%d: POSSIBLE\n", t);
		ways[1]=1;
		for(long long n=2; n<=N; n++)
		{
			ways[n]= (long long)1<<(n-2);
		}
		for(long long n=1; n<N; n++)
		{
			for(long long a=n+1; a<N; a++)
			{
				adj[n][a] = 1;
			}
		}
		for(long long n=N-1; n>0; n--)
		{
			if(M-ways[n] >=0)
			{
				M-= ways[n];
				adj[n][N]=1;
			}
		}
		for(long long a=1; a<=N; a++)
		{
			for(long long b=1; b<=N; b++)
			{
				printf("%d", adj[a][b]);
			}
			printf("\n");
		}
	}
}