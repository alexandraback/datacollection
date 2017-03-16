#include <stdio.h>

int a[55][55];
long long b[60];
int main()
{
	b[0] = 1;
	b[1] = 1;
	for(int i = 2; i < 60; i++)
		b[i] = b[i - 1] * 2LL;
	//for(int i = 0; i < 60; i ++)
	//	printf("b %d %lld\n", i,b[i]);
	int T;
	scanf("%d",&T);
	for(int cas = 1; cas <= T; cas++)
	{
		long long n,m;
		scanf("%lld%lld",&n,&m);
		if(n == 2)
		{

			printf("Case #%d:", cas);
			if(m > 1)
				puts(" IMPOSSIBLE");
			else
			{
				puts(" POSSIBLE");
				for(int i = 0; i <= n; i++)
					for(int j =0; j <= n; j++)
						a[i][j] = 0;
				if(m == 1)
					a[1][2] = 1;
				for(int i = 1; i <= n; i++)
				{
					for(int j = 1; j <= n; j++)
						printf("%d", a[i][j]);
					puts("");
				}
			}
			continue;
		}
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				a[i][j] = 0;
		if(m == 0)
		{
				for(int i = 1; i <= n; i++)
				{
					for(int j = 1; j <= n; j++)
						printf("%d", a[i][j]);
					puts("");
				}
			continue;
		}
		m--;
		int t = n;
		long long tot;
		tot = 0;
		int k = 0;
		for(int s = n - 2; s >= 1; s--)
		{
			k = 0;
			for(int j = s + 2; j <= n; j++)
			{
				tot = b[n - j];
				if(m - tot >= 0)
				{
					a[s][j] = 1;
					m -= tot;
					//printf("add %d %d %lld\n",s,j, tot);
				}
			}
		}
		for(int i = 1; i < n; i++)
			a[i][i + 1] = 1;
		printf("Case #%d:", cas);
		if(m > 0)
			puts(" IMPOSSIBLE");
		else
		{
			puts(" POSSIBLE");
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= n; j++)
					printf("%d", a[i][j]);
				puts("");
			}
		}
	}
}