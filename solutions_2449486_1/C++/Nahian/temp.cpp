
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<cstdlib>
#include<string>
#include<set>
using namespace std;

#define MAX 200

int grid[MAX][MAX];
int n,m;
int vis[MAX][MAX];

struct node
{
	int r,c,h;
	node(int x,int y,int z)
	{
		r=x;
		c=y;
		h=z;
	}
	bool operator<(node ob) const
	{
		return h<ob.h;
	}
};

int check(node ob)
{
	int i;
	for(i=0;i<n;i++)
		if(ob.h<grid[i][ob.c])
			break;
	if(i==n)
	{
		for(i=0;i<n;i++)
			vis[i][ob.c]=1;
		return 1;
	}
	for(i=0;i<m;i++)
		if(ob.h<grid[ob.r][i])
			break;
	if(i==m)
	{
		for(i=0;i<m;i++)
			vis[ob.r][i]=1;
		return 1;
	}
	return 0;
}

int main()
{
//	freopen("B-large.in","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	vector<node> vec;
	for(int cas=0;cas<t;cas++)
	{
		memset(vis,0,sizeof(vis));
		vec.clear();
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&grid[i][j]);
				vec.push_back(node(i,j,grid[i][j]));
			}
		}
		sort(vec.begin(),vec.end());
		int i;
		for(i=0;i<vec.size();i++)
		{
			if(!vis[vec[i].r][vec[i].c])
			{
				if(!check(vec[i]))
					break;
			}
		}
		if(i==vec.size())
			printf("Case #%d: YES\n",cas+1);
		else
			printf("Case #%d: NO\n",cas+1);
	}
    return 0;
}
