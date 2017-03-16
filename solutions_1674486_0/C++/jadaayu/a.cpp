
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

//#define DEBUG
#ifdef DEBUG
#define dprintf(fmt,...)  printf(fmt,__VA_ARGS__)
#else
#define dprintf(fmt,...)
#endif

using namespace std;

int graph[1001][1001];
int size[1001], visited[1001];
int status;

void custom_dfs(int current,int destination);

int main(void)
{
	int tc;
	scanf("%d",&tc);
	for(int t=0;t<tc;t++)
	{
		int N;
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
		{
			int M;
			scanf("%d",&M);
			size[i]=M;
			for(int j=0;j<M;j++)
			{
				int data;
				scanf("%d",&data);
				graph[i][j] = data;
			}
		}
		printf("Case #%d: ",t+1);

		for(int i=1;i<=(N-1);i++)
		{
			for(int j=i+1;j<=N;j++)
			{
				status = 0;
				dprintf("Path %d-%d: ",i,j);
				custom_dfs(i,j);
				if(status == 0)
				{
					dprintf("Path %d-%d: ",j,i);
					custom_dfs(j,i);
					if(status >= 2)
					{ 
						printf("Yes\n"); 
					    goto end; 
					}
				}
				else if(status >= 2)
				{ 
					printf("Yes\n"); 
					goto end; 
				}
			}
		}
		printf("No\n");
end:	continue;
	}
	return 0;
}
					
					



void custom_dfs(int current,int destination)
{
  int i;
  // I have visited it
  visited[current] = 1;
  dprintf("Debug: %d\n",current);
  
  if(current == destination)
  {
	status++;
  }
  else
  {
    for(i=0;i<size[current];i++)
    {
      if(!visited[graph[current][i]])
      {
        custom_dfs(graph[current][i],destination);
      }
    }
  }
  visited[current] = 0;
  return;
}
  