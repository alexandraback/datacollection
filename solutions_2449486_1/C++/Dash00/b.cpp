#include<iostream>
#include<cstdio>
using namespace std;

int map[110][110];
int n,m;

bool cut(int x,int y)
{
	int f = 0;
	int i;
	for(i=0;i<m;i++)
	{
		if(map[x][i] > map[x][y]) 
		{
			f++;
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		if(map[i][y] > map[x][y])
		{
			f++;
			break;
		}
	}
	//cout<<f<<endl;
	if(f<2)
		return true;
	return false;
}

int main()
{
	int t;
	int cas = 1;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		bool f = true;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(!cut(i,j))
				{
					f = false;
					break;
				}
			}
			if(f == false)
				break;
		}
		if(f)
		{
			printf("Case #%d: YES\n",cas++);
		}else
		{
			printf("Case #%d: NO\n",cas++);
		}
	}
	return 0;
}
