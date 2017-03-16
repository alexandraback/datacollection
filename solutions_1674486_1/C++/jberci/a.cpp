#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

int n;
int sosedi[1010][20],indeg[1010];
int mask[1010];

bool bfs(int start, int color)
{
	queue<int> q;
	int cur,i;

	q.push(start);
	while (!q.empty())
	{
		cur=q.front(); q.pop();
		for (i=0;i<sosedi[cur][0];i++)
		{
			if (mask[ sosedi[cur][i+1] ]==color) { return true; }
			mask[ sosedi[cur][i+1] ]=color;
			q.push(sosedi[cur][i+1]);
		}
	}
	return false;
}

int main()
{
	int t,tt;
	int i,j,color=1;
	bool result;

	memset(mask,0,sizeof(mask));

	scanf("%d",&tt);
	for (t=1;t<=tt;t++)
	{
		memset(indeg,0,sizeof(indeg));

		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d",&sosedi[i][0]);
			for (j=0;j<sosedi[i][0];j++)
			{
				scanf("%d",&sosedi[i][j+1]);
				sosedi[i][j+1]--;
				indeg[ sosedi[i][j+1] ]++;
			}
		}

		result=false;
		for (i=0;i<n && !result;i++)
		{
			if (indeg[i]>0) { continue; }
			result=(result || bfs(i,color++));
		}
		printf("Case #%d: %s\n",t,result?"Yes":"No");
	}

	return 0;
}

