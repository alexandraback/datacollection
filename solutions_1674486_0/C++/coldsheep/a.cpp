#include<queue>
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;


int t,n,m;
int ci[1005];
vector<int> bian[1005];
bool b()
{
	for(int i=1;i<=n;i++)
	{
		memset(ci,0,sizeof(ci));
		queue<int> que;
		que.push(i);
		while(!que.empty())
		{			
			int p=que.front();que.pop();
			ci[p]++;
			if(ci[p]==2)return true;
			for(int j=0;j<bian[p].size();j++)
				que.push(bian[p][j]);
		}
	}
	return false;
}

int main()
{
	freopen("A-small-attempt0 (1).in","r",stdin);
	freopen("A-large.out","w",stdout);	
	scanf("%d",&t);
	int ccase=0;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			bian[i].clear();
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				int b;
				scanf("%d",&b);
				bian[i].push_back(b);
			}
		}
		if(b())printf("Case #%d: Yes\n",++ccase);
		else 
             printf("Case #%d: No\n",++ccase);
	}	
	//system("pause");
	return 0;
}
