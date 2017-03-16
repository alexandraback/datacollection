#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char map[1010][1010];
int visited[1010];
int count[1010];
int n;
int done;
int start;
void try(int node)
{
	int j;
	if(start != node)
	{
		count[node]++;
	}
	if(visited[node])
	{
		return;
	}
	visited[node] = 1;
	
	for(j = 1; j <= n; ++j)
	{
		if(map[node][j])
		{
			try(j);
		}
	}
	return;
}

int main()
{
	int i, j, k;
	int t, m, temp;
	
	scanf("%d", &t);
	for(i = 0; i < t; ++i)
	{
		memset(map, 0, 1010*1010*sizeof(char));
		scanf("%d", &n);
		for(j = 1; j <= n; ++j)
		{
			scanf("%d", &m);
			for(k = 0; k < m; ++k)
			{
				scanf("%d", &temp);
				map[j][temp] = 1;
			}
		}
		done = 0;
		for(j = 1; j <= n; ++j)
		{
			memset(count, 0, 1010*sizeof(char));
			memset(visited, 0, 1010*sizeof(char));
			start = j;
			try(j);
			for(k = 1; k <= n; ++k)
			{
				if(count[k] > 1)
				{
					done = 1;
					break;
				}
			}
			if(done  == 1)
			{
				break;
			}
		}
		if(done)
		{
			printf("Case #%d: Yes\n", i+1);	
		}
		else
		{
			printf("Case #%d: No\n", i+1);	
		}
	}
	
	return 0;
}