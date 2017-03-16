#include <stdio.h>
#include <stdlib.h>

int **graph, *len, visited, n;

void check(int x, int y)
{
	int i,j,k;
	if (x == y)
	{
		visited ++;
		return;
	}
	for (i = 1; i < len[x]; ++i)
	{
		check(graph[x][i],y);
	}
}

int main()
{
	int t,i,tt,m,j;
	scanf("%d",&t);
	tt = 0;
	while(t)
	{
		t--;
		tt++;
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		n++;
		graph = malloc(n * sizeof(int*));
		len = malloc (n * sizeof(int));
		for (i = 1; i < n;++i)
		{
			scanf("%d", &m);
			m++;
			graph[i] = malloc(m * sizeof(int));
			len[i] = m;
			for (j = 1; j < m; ++j)
				scanf("%d",&graph[i][j]);
		}
		for (i = 1; i < n; ++i)
		{
			for (j = 1; j < n; ++j)
			{
				visited = 0;
				if (i != j)
				{
					check(i,j);
					if (visited > 1)
					{
						i = 2*n;
						j = n;
						printf("Yes\n");
					}
				}
			}
		}
		if (i < 2*n)
			printf("No\n");
	}
	return 0;
}
