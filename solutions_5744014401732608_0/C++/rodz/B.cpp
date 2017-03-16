#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int T, tcnt = 0;
	scanf("%d", &T);
	while(T--)
	{
		int b;
		ll m, ways[55] = {0};
		int adj[55][55] = {0};

		scanf("%d %lld", &b, &m);
		for (int i = 2; i < b; i++)
		{
			ways[i] = 1LL;
			adj[1][i] = 1;
			for (int j = 2; j < i; j++)
			{
				adj[i][j] = 1;
				ways[j] *= 2LL;
			}
		}


		/*
		for (int i = 2; i < b; i++)
		{
			printf("ways[%d] = %lld\n", i, ways[i]);
		}
		*/

		for (int i = 2; i < b; i++)
		{
			if (m >= ways[i])
			{
				m -= ways[i];
				adj[i][b] = 1;
			}
		}
		if (m == 1)
		{
			ways[1] = 1;
			adj[1][b] = 1;
			m--;
		}
		printf("Case #%d: ", ++tcnt);
		if (m == 0)
		{
			printf("POSSIBLE\n");
			for (int i = 1; i <= b; i++)
			{
				for (int j = 1; j <= b; j++)
				{
					printf("%d", adj[i][j]);
				}
				printf("\n");
			}
		}
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
