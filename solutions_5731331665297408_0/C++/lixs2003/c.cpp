#include<iostream>
#include<string.h>
#include<stdio.h>
#include<memory.h>
using namespace std;

int n,n1,i,i1,x,m,y;
string str[10],ok,strnow;
int g[10][10],tem[10][10],tem2[10][10],flag[10];

bool isOK()
{
	for(int i=1;i<=n;i++)
		if(flag[i]==0)
			return false;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(tem2[i][j]==1)
				return false;
	return true;
}


void dfs(int now,string strnow)
{
	bool gai=false;
	if(flag[now]==0)
	{
		flag[now]=1;
		strnow+=str[now];
		gai=true;
	}
	if(isOK())
	{
		if(ok==""||strnow<ok)
			ok=strnow;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(tem[now][i]==1&&flag[i]==0)
			{
				tem2[i][now]=1;
				dfs(i,strnow);
				tem2[i][now]=0;
			}
			if(tem2[now][i]==1)
			{
				tem2[now][i]=0;
				dfs(i,strnow);
				tem2[now][i]=1;
			}
		}
	}
	
	
	
	if(gai)
		flag[now]=0;	
}

int main()
{
		cin>>n1;
	
	for(i1=1;i1<=n1;i1++)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
			cin>>str[i];
		memset(g,0,sizeof(g));
		for(i=1;i<=m;i++)
		{
			cin>>x>>y;
			g[x][y]=1;
			g[y][x]=1;
		}
		ok="";strnow="";
		memset(flag,0,sizeof(flag));
		memset(tem2,0,sizeof(tem2));
		memcpy(tem,g,sizeof(g));
		for(i=1;i<=n;i++)
			dfs(i,"");
		cout<<"Case #"<<i1<<": "<<ok<<endl;
	}
	
	return 0;
} 
