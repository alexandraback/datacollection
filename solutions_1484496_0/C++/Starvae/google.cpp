#include  <stdio.h>   
#include <iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

void FileIn()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("c.out","w",stdout);
}
int n;
int a[100];
int x[100],y[100];
bool dfs(int lx,int sumx,int ly,int sumy,int deep)
{

	if(lx > 0 && y > 0 && sumx == sumy)
	{
		printf("%d",x[0]);
		for(int i = 1 ; i < lx; i ++)
			printf(" %d",x[i]);	
		printf("\n");	
		printf("%d",y[0]);
		for(int i = 1 ; i < ly; i ++)
			printf(" %d",y[i]);	
		printf("\n");	
		return true;
	}
	if(deep == n) return false;
	//for(int i = deep; i < n; i ++)
	{
		int i = deep;
		
		if(dfs(lx,sumx,ly,sumy,deep+1))
			return true;
		x[lx] = a[i];
		if(dfs(lx+1,sumx+a[i],ly,sumy,deep+1))
			return true;
		y[ly] = a[i];
		if(dfs(lx,sumx,ly+1,sumy+a[i],deep+1))
			return true;

	}
	return false;
}
int main()
{
	FileIn();
	int T;
	int cas;

	scanf("%d",&T);
	cas = 1;
	while(T--)
	{
		scanf("%d",&n);
		
		for(int i = 0; i < n ; i ++)
		{
			scanf("%d",&a[i]);
		}
		
		printf("Case #%d:\n",cas++);
		if(!dfs(0,0,0,0,0))
			printf("Impossible\n");
	//	printf("\n");
	}
	return 0;
}
