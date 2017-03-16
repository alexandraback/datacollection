#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
const int MAX = 1005;

typedef struct _node
{
	int num;
	int f[MAX];
}N;
N node[MAX];
bool visited[MAX];
bool Flag;

void dfs(int index)
{
	if(visited[index] == true)
		Flag = true;

	visited[index] = true;

	if(node[index].num == 0 || Flag == true)
	{
		return ;
	}
	for(int i = 1; i <= node[index].num; i++)
	{
		int father = node[index].f[i];
		dfs(father);
	}
}

bool check(int index)//由每个有两个以上的点开始
{
	memset(visited, false, sizeof(visited));
	Flag = false;
	for(int i = 1; i <= node[index].num; i++)
	{
		if(Flag == true)
			break;
		dfs(node[index].f[i]);
	}
	return Flag;
}

int main(void)
{
	freopen("A-small-attempt0.txt", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int cas, cas_c = 1;
	scanf("%d", &cas);
	while(cas--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &node[i].num);
			for(int j = 1; j <= node[i].num; j++)
				scanf("%d", &node[i].f[j]);
		}
		bool flag = false;
		for(int i = 1; i <= n; i++)
		{
			if(node[i].num >= 2)
			{
				if(check(i))
				{
					flag = true;
					break;
				}
			}
		}
		printf("Case #%d: ", cas_c++);
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}