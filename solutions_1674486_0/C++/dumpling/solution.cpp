#include <iostream>
#include <queue>
using namespace std;

int T, n;
bool f[1024][1024];

bool floyd()
{
	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(i != j && j != k && i != j)
				{
					if(f[i][k] && f[k][j])
					{
						if(f[i][j])
							return true;
						f[i][j] = true;
					}
				}
	return false;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		memset(f, 0, sizeof(f));
		int m;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			int dst;
			scanf("%d", &m);
			for(int j = 0; j < m; ++j)
			{
				scanf("%d", &dst);
				f[i][dst - 1] = true;
			}
		}
		printf("Case #%d: %s\n", t, floyd() ? "Yes" : "No");
	}
	return 0;
}