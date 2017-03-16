#include <stdio.h>
#define N 100
#define M 100

int n, m;
int pattern[N][M];
bool solved[N][M];

int main()
{
	int t;
	bool ans;
	scanf("%d", &t);
	for (int i=1;i<=t;++i)
	{
		ans = true;
		scanf("%d%d", &n, &m);
		for (int j=0;j<n;++j)
			for (int k=0;k<m;++k)
			{
				scanf("%d", &pattern[j][k]);
				solved[j][k] = false;
			}
		for (int j=0;j<n;++j)
		{
			int max = pattern[j][0];
			for (int k=1;k<m;++k)
				max = max>pattern[j][k]?max:pattern[j][k];
			for (int k=0;k<m;++k)
				if (pattern[j][k]==max)
					solved[j][k] = true;
		}
		for (int j=0;j<m;++j)
		{
			int max = pattern[0][j];
			for (int k=1;k<n;++k)
				max = max>pattern[k][j]?max:pattern[k][j];
			for (int k=0;k<n;++k)
				if (pattern[k][j]==max)
					solved[k][j] = true;
		}
		for (int j=0;j<n;++j)
			for (int k=0;k<m;++k)
				if (!solved[j][k])
					ans = false;
		printf("Case #%d: %s\n", i, ans?"YES":"NO");
	}
	return 0;;
}
