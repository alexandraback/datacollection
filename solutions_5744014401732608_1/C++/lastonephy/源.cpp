#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int b;
long long m;
long long pow2[55];
char str[55][55];

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int t;
	scanf("%d", &t);
	pow2[0] = 1;
	for (int i = 1; i <= 51; i++)
	{
		pow2[i] = pow2[i - 1] * 2;
	}
	for (int ii = 1; ii <= t; ii++)
	{
		scanf("%d%lld", &b, &m);
		printf("Case #%d: ", ii);
		if (pow2[b - 2] < m)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		else
		{
			printf("POSSIBLE\n");
		}
		for (int i = 0; i < b - 1; i++)
		{
			for (int j = 0; j < b - 1; j++)
			{
				if (j <= i) str[i][j] = '0';
				else str[i][j] = '1';
			}
			str[i][b - 1] = '0';
			str[i][b] = '\0';
		}
		for (int i = 0; i < b; i++)
		{
			str[b - 1][i] = '0';
		}
		str[b - 1][b] = '\0';
		int x = 1;
		m--;
		str[0][b - 1] = '1';
		while (m && x < b - 1)
		{
			if (m & 1)
			{
				str[x][b - 1] = '1';
			}
			m >>= 1;
			x++;
		}
		for (int i = 0; i < b; i++)
		{
			printf("%s\n", str[i]);
		}
	}
	return 0;
}