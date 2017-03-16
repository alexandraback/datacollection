/**
Coded by:-   Rogue
**/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	int t,i,j,n,m, cases, mx;
	int a[110][110],b[110][110];
	bool flag;
	cin>>cases;
	for(t=0; t<cases; t++)
	{
		cin>>n>>m;
		flag=true;
		for(i=0; i<n; i++)
			for(j=0; j<m; j++)
				b[i][j]=0;
		for(i=0; i<n; i++)
			for(j=0; j<m; j++)
				cin>>a[i][j];
				
		for(i=0; i<n; i++)
		{
			mx=-1;
			for(j=0;j<m; j++)
				if(a[i][j]>mx || mx==-1)
					mx=a[i][j];
					
			for(j=0; j<m; j++)
				if(a[i][j]==mx)
					b[i][j]=1;
		}
		
		for(j=0; j<m; j++)
		{
			mx=-1;
			for(i=0; i<n; i++)
			{
				if(a[i][j]>mx || mx==-1)
					mx=a[i][j];
			}
			for(i=0; i<n; i++)
				if(a[i][j]==mx)
					b[i][j]=1;
		}
		
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(b[i][j]==0)
				{
					flag=false;
					break;
				}
			}
			if(!flag)
				break;
		}
		if(flag)
			cout<<"Case #"<<t+1<<": "<<"YES"<<endl;
		else
			cout<<"Case #"<<t+1<<": "<<"NO"<<endl;
	}
	return 0;
}

