#include <cstdio>
#include <algorithm>

using namespace std;

int N,ans,used[1000],table[1000][1000];

void DFS(int now)
{
	for(int i=0;ans==0&&i<N;i++)
		if(table[now][i]==1)
		{
			if(used[i]==1)
				ans=1;
			else
			{
				used[i]=1;
				DFS(i);
			}
		}
}

int main()
{
	int T,M,a;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				table[i][j]=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&M);
			for(int j=0;j<M;j++)
			{
				scanf("%d",&a);
				table[i][a-1]=1;
			}
		}
		ans=0;
		for(int i=0;ans==0&&i<N;i++)
		{
			for(int j=0;j<N;j++)
				used[j]=0;
			DFS(i);
		}
		if(ans==1)
			printf("Case #%d: Yes\n",t+1);
		else
			printf("Case #%d: No\n",t+1);
	}
	return 0;
}
