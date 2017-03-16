

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
//#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>
#define eps 1e-12
#define MAX 1000000000
using namespace std;

int a[300];
int n;
bool ff;
int mark[300];

void gao(int x,int sum,int tot)
{
	int i;
	if(ff)return;
	if(sum>tot)
	return;
	if(sum==tot)
	{
		ff=true;
		bool f=false;
		for(i=0;i<n;i++)
		{
			
		if(mark[i]==1)
		{
			if(!f)
				f=true;
			else cout<<" ";
		cout<<a[i];
		}
		}
		cout<<endl;
		
		
		f=false;
		for(i=0;i<n;i++)
		{
			
		if(mark[i]==2)
		{
			if(!f)
				f=true;
			else cout<<" ";
		cout<<a[i];
		}
		}
		cout<<endl;
		
	}
	if(x==n)
	{
		return;
	}
	
	if(mark[x]==1)
	gao(x+1,sum,tot);
	else
	{
		mark[x]=2;
		gao(x+1,sum+a[x],tot);
		mark[x]=0;
		gao(x+1,sum,tot);
	}
	
	
}

void dfs(int x,int sum)
{
	if(ff)
	return;
	if(x==n)
	{
		gao(0,0,sum);
		return ;
	}
	mark[x]=1;
	dfs(x+1,sum+a[x]);
	mark[x]=0;
	dfs(x+1,sum);
}

int main()
{
	freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);


	int cases=1;
	int i,re;
	cin>>re;
	while(re--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
			
			cout<<"Case #"<<cases++<<":"<<endl;
			ff=false;
		dfs(0,0);
	}
	
}