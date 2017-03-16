#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main()
{
	cin>>N;
	int k=1;
	while(k<=N)
	{
		int x, y;
		cin>>x>>y;
		cout<<"Case #"<<k<<": ";
		if(y>0)
		{
			for(int i=0; i<y; i++)
				cout<<"SN";
		}
		else
		{
			for(int i=0; i<(-1)*y; i++)
				cout<<"NS";
		}
		if(x>0)
		{
			for(int i=0; i<x; i++)
				cout<<"WE";
		}
		else
		{
			for(int i=0; i<(-1)*x; i++)
				cout<<"EW";
		}
		cout<<"\n";
		k++;
	}
	return 0;
}
