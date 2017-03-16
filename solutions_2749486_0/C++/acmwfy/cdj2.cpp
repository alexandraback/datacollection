//============================================================================
// Name        : cdj2.cpp
// Author      : wfy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
string a="EW";
string b="WE";
string c="NS";
string d="SN";

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		printf("Case #%d: ",++cas);
		if(x>0)
		for(int i=0;i<x;i++)
			cout<<b;
		else
		for(int i=0;i<-x;i++)
			cout<<a;
		if(y>0)
			for(int i=0;i<y;i++)
			cout<<d;
		else
			for(int i=0;i<-y;i++)
				cout<<c;
		cout<<endl;
	}
}
