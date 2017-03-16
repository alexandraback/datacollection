#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 105
int map[N][N];
int v1[N], v2[N];
int main()
{
	int tcase, n, m, icase = 1;
	int i, j, k;
	scanf("%d", &tcase);
	while(tcase--)
	{
		scanf("%d%d", &n, &m);
		memset(v1, 0, sizeof(v1));
		memset(v2, 0, sizeof(v2));
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
			{
				scanf("%d", &map[i][j]);
				if(map[i][j] > v1[i])
					v1[i] = map[i][j];
				if(map[i][j] > v2[j])
					v2[j] = map[i][j];
			}
		printf("Case #%d: ", icase++);
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				if(map[i][j] < v1[i] && map[i][j] < v2[j])
					break;
			}
			if(j != m)
				break;
		}
		if(i != n)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}
