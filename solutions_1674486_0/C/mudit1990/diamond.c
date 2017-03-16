#include<stdio.h>
#include<string.h>

int mat[1010][1010];
int check[1010];

int dfs(int vertex, int num)
{
	int i,ret;
	check[vertex] = 1;
	for(i=1;i<=num;i++)
	{
		if(mat[vertex][i] == 1)
		{
			if(check[i] == 1)
			{
				return 1;
			}
			ret = dfs(i,num);
			if(ret == 1)
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int t,n,v2,i,j,k,m,flag;
	scanf("%d",&t);

	k = 1;

	while(t--)
	{
		scanf("%d",&n);

		memset(mat,0,sizeof(mat));

		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);

			for(j=0;j<m;j++)
			{
				scanf("%d",&v2);
				mat[i][v2] = 1;
			}
		}

		flag = 0;

		for(i=1;i<=n;i++)
		{
			memset(check,0,sizeof(check));
			if(dfs(i,n) == 1)
			{
				printf("Case #%d: Yes\n",k++);
				flag = 1;
				break;
			}
		}

		if(flag == 0)
		{
			printf("Case #%d: No\n",k++);
		}
	}
}
