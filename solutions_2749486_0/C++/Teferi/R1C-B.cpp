#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long LINT;

int tbl[1000][1000];

void main()
{
	int t;
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		int x,y;
		cin>>x>>y;

		cout<<"Case #"<<ii+1<<": ";
		if(x>0)
			for(int i=0; i<x; i++)
				cout<<"WE";
		else
			for(int i=0; i<-x; i++)
				cout<<"EW";

		if(y>0)
			for(int i=0; i<y; i++)
				cout<<"SN";
		else
			for(int i=0; i<-y; i++)
				cout<<"NS";

		cout<<endl;
	}
}