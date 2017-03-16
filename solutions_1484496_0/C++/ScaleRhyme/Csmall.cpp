
	#include <stdio.h>
	#include <cstdlib>
	#include <algorithm>

	using namespace std;

	int v[30];
	int sum[1048580];
	int ind[1048580]; 

	int cmp(int a, int b)
	{
		return (sum[a] < sum[b]);
	}

	void work()
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i ++)	scanf("%d", &v[i]);
		for (int i = 0; i < (1 << n); i ++)
		{
			sum[i] = 0;
			ind[i] = i;
			for (int j = i, k = 0; j != 0; j /= 2, k ++)
				if (j & 1 == 1)	sum[i] += v[k];
		}
		sort(ind, ind + (1 << n), cmp);
		for (int i = 0; i < (1 << n); i ++)
		{
			for (int j = i + 1; j < (1 << n) && sum[ind[i]] == sum[ind[j]]; j ++)
			{
				if ((ind[i] & ind[j]) == 0)
				{
					for (int k = ind[i], l = 0; k != 0; k /= 2, l ++)
						if (k & 1 == 1)
							printf("%d ", v[l]);
					printf("\n");
					for (int k = ind[j], l = 0; k != 0; k /= 2, l ++)
						if (k & 1 == 1)
							printf("%d ", v[l]);
					printf("\n");
					return;
				}
			}
		}
		printf("Impossible\n");
	}

	int main(int argc, char *argv[])
	{
		freopen("c.in", "r", stdin);
		freopen("c.out", "w", stdout);
		int t;
		scanf("%d", &t);
		for (int i = 0; i < t; i ++)
		{
			printf("Case #%d:\n", i + 1);
			work();
		}
		return 0;
	}
