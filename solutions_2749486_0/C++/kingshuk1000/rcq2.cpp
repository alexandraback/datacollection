#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	freopen("B-small-attempt2(1).in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	
	int ncase;
	//scanf("%d",&ncase);
	cin>>ncase;

	int t,i;
	
	for(t=0;t<ncase;t++)
	{
		int x,y;
		cin>>x>>y;
		cout<<"Case #"<<t+1<<": ";
		if(x>0)
		{
			int i;
			for(i=0;i<x;i++)
			{cout<<"WE";}
			
		}
		if(x<0)
		{
			int i;
			for(i=0;i<-x;i++)
			{cout<<"EW";}
			
		}
		if(y>0)
		{
			int i;
			for(i=0;i<y;i++)
			{cout<<"SN";}
			
		}
		if(y<0)
		{
			int i;
			for(i=0;i<-y;i++)
			{cout<<"NS";}
			
		}
		cout<<endl;

	}
}