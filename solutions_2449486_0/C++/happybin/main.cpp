#include <stdio.h>
#include <string.h>

int mp[105][105];
int h[105];
int v[105];

int main()
{
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int nt = 0;
	while(T--)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		memset(h, 0, sizeof(int)*105);
		memset(v, 0, sizeof(int)*105);

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				scanf("%d", &mp[i][j]);
				if (mp[i][j] > h[i])
					h[i] = mp[i][j];
				if (mp[i][j] > v[j])
					v[j] = mp[i][j];
			}
		
		bool ans = true;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				if ((h[i] > mp[i][j]) && (v[j] > mp[i][j]))
				{
					ans= false;
					break;
				}
			}
		if (ans == true)
			printf("Case #%d: YES\n", ++nt);
		else
			printf("Case #%d: NO\n", ++nt);
	}
}