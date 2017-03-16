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
		int k, c, s;
		scanf("%d %d %d\n", &k, &c, &s);

		if (k > c * s)
		{
			printf("Case #%d: IMPOSSIBLE\n", t + 1);
			continue;
		}

		printf("Case #%d:", t + 1);
		for (int i = 0; i < k; i += c)
		{
			long long num = 0;
			for (int j = i; j < i + c && j < k; j++)
			{
				num = num * k + j;
			}
			printf(" %lld", num + 1);
		}
		printf("\n");
	}
	return 0;
}
