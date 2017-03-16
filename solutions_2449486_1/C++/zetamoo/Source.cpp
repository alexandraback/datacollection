#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int n,N=0,x,y,map[103][103];
	cin>>n;
	bool check[103][103];
	while(++N<=n)
	{
		cin>>y>>x;
		for(int f=0;f<y;f++)
		{
			for(int f1=0;f1<x;f1++)
			{
				cin>>map[f][f1];
				check[f][f1]=false;
			}
		}
		int sum=0,max;
		for(int f=0;f<y;f++)
		{
			max=0;
			for(int f1=0;f1<x;f1++)
			{
				if(map[f][f1]>max)
					max=map[f][f1];
			}
			for(int f1=0;f1<x;f1++)
			{
				if(map[f][f1]==max)
					check[f][f1]=true;
			}
		}
		for(int f1=0;f1<x;f1++)
		{
			max=0;
			for(int f=0;f<y;f++)
			{
				if(map[f][f1]>max)
					max=map[f][f1];
			}
			for(int f=0;f<y;f++)
			{
				if(map[f][f1]==max)
					check[f][f1]=true;
			}
		}
		for(int f=0;f<y;f++)
		{
			for(int f1=0;f1<x;f1++)
			{
				sum+=check[f][f1];
			}
		}
		if(sum==x*y)
			printf("Case #%d: YES\n",N);
		else
			printf("Case #%d: NO\n",N);
	}
}