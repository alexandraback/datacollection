#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;


int t,n,m;
int times[1005];
vector<int> edge[1005];
bool run()
{
	for(int i=1;i<=n;i++)
	{
		memset(times,0,sizeof(times));
		queue<int> que;
		que.push(i);
		while(!que.empty())
		{			
			int p=que.front();que.pop();
			times[p]++;
			if(times[p]==2)return true;
			for(int j=0;j<edge[p].size();j++)
				que.push(edge[p][j]);
		}
	}
	return false;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);	
	scanf("%d",&t);
	int cas=0;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			edge[i].clear();
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				int b;
				scanf("%d",&b);
				edge[i].push_back(b);
			}
		}
		if(run())printf("Case #%d: Yes\n",++cas);
		else 
             printf("Case #%d: No\n",++cas);
	}	
	//system("pause");
	return 0;
}
