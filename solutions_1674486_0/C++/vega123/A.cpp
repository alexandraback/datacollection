#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> a[1005];
int visited[1005];
int dfs(int j,int color)
{
	visited[j]=color;
	int flag=0;
	for(int i=0;i<a[j].size();i++)
		if(visited[a[j][i]]==0)
		{
			 if(dfs(a[j][i],color))
				 flag=1;
		}
		else if(visited[a[j][i]]==color)
		{
			return 1;
		}
	if(flag==1)return 1;
	return 0;

}
int main()
{
	int t,n,x,m;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		scanf("%d",&n);
		
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&m);
			a[j].clear();
			visited[j]=0;
			while(m--){
				scanf("%d",&x);
				a[j].push_back(x);
			}
		}
		int flag=0;
		for(int j=1;j<=n;j++)
			//if(visited[j]==0)
			{
				memset(visited,0,sizeof(visited));
				flag=dfs(j,j);
				if(flag)break;
			}
			if(flag)printf("Yes\n");
			else printf("No\n");
	}
	return 0;
}