/********************************************
Author: Yinthewind
Sun May 12 17:50:17 CST 2013
********************************************/
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

int T,x,y;

int main()
{
	cin>>T;
	for(int ii=1;ii<=T;ii++)
	{
		cin>>x>>y;
		cout<<"Case #"<<ii<<": ";
		if(x>0) for(int i=0;i<x;i++) cout<<"WE";
		else for(int i=0;i<-x;i++) cout<<"EW";
		if(y>0) for(int i=0;i<y;i++) cout<<"SN";
		else for(int i=0;i<-y;i++) cout<<"NS";
		cout<<endl;
	}
	return 0;
}
