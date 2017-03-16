#include<iostream>
#include<cstdio>
#include<vector>
#include<memory.h>
using namespace std;

struct node
{
	int x,to;
};

vector<int>mymap[1100];

int in[1100],out[1100];

bool vis[1100];
int time;

bool dfs(int index)
{
	if(vis[index])
		{
			return true;
		}
	vis[index] = true;
	for(int i=0;i<mymap[index].size();i++)
	{
		int v = mymap[index][i];
	//	cout<<index<<" to "<<v<<endl;
		
		if(dfs(v))return true;
	}
	return false;
}

int main()
{
	int T,n;
	 freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
	scanf("%d",&T);
	int icas = 0;
	while(T--)
	{
		int a,b;
		icas++;
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
		{
			mymap[i].clear();
		}
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			int c;
			scanf("%d",&c);
			out[i+1] = c;
			for(int j=0;j<c;j++)
			{
				scanf("%d",&a);
				mymap[i+1].push_back(a);
				in[a]++; 
			}
		}
		bool ans = 0;
		for(int i=0;i<n;i++)
		{
			if(!in[i+1])
			{
				memset(vis,0,sizeof(vis));
				ans = dfs(i+1);

			}
			if(ans)break;
		}
//		for(int i=1;i<=n;i++)
//			cout<<i<<" "<<"in:"<<in[i]<<" out:"<<out[i]<<endl;
		printf("Case #%d: ",icas);
		if(ans)printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}
