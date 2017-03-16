#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T, deltaX, deltaY;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>deltaX>>deltaY;
		cout<<"Case #"<<t+1<<": ";
		if(deltaX>0)
		{
			for(int i=0;i<deltaX;i++)
				cout<<"WE";
		}
		else
		{
			deltaX = -deltaX;
			for(int i=0;i<deltaX;i++)
				cout<<"EW";
		}
		if(deltaY>0)
		{
			for(int i=0;i<deltaY;i++)
				cout<<"SN";
		}
		else
		{
			deltaY = -deltaY;
			for(int i=0;i<deltaY;i++)
				cout<<"NS";
		}
		cout<<endl;
	}
}
