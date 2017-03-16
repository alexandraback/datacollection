#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int t,T=0;
	cin>>t;
	while(T!=t)
	{
		T++;
		int x,y;
		cin>>x>>y;
		int p=1;
		int i;
		printf("Case #%d: ",T);
		if(x<0)
		{
			x*=-1;
			for(i=0;i<x;i++)
				cout<<"EW";
		}
		else
		{
			for(i=0;i<x;i++)
				cout<<"WE";
		}
		if(y<0)
		{
			y*=-1;
			for(i=0;i<y;i++)
				cout<<"NS";
		}
		else
		{
			for(i=0;i<y;i++)
				cout<<"SN";
		}
		cout<<'\n';
	}
}
