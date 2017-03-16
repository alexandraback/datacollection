#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;


int t,n,m;
int times[1005];
vector<int> edge[1005];
bool f()
{
	for(int i=1;i<=n;i++)
	{
		memset(times,0,sizeof(times));
		queue<int> q;
		q.push(i);
		while(!q.empty())
		{			
			int p=q.front();q.pop();
			times[p]++;
			if(times[p]==2)return true;
			for(int j=0;j<edge[p].size();j++)
				q.push(edge[p][j]);
		}
	}
	return false;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-out.txt","w",stdout);	
	scanf("%d",&t);

	int icase=1;
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
		if(f())printf("Case #%d: Yes\n",icase++);
		else printf("Case #%d: No\n",icase++);
	
	}	
	return 0;
}
