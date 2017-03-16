#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, teste;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		int n;
		int h[3000];
		for (int i = 0; i <= 2500; i++)
		{
			h[i] = 0;
		}
		scanf("%d\n", &n);
		for (int i = 0; i < 2 * n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int a;
				scanf("%d", &a);
				h[a]++;
			}
		}

		printf("Case #%d:", t + 1);
		for (int i = 0; i <= 2500; i++)
		{
			if (h[i] & 1)
			{
				printf(" %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
