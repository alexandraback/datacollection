#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t;
	int x,y;
	bool b;
	cin>>t;
	for (int loop=1;loop<=t;loop++)
	{
		cin>>x>>y;
		cout<<"Case #"<<loop<<": ";
		if (x<0) b=1; else b=0;
		for (int i=0;i<2*abs(x);i++)
		{
			if (b==0) cout<<'W'; else cout<<'E';
			b=1-b;
		}
		if (y<0) b=1; else b=0;
		for (int i=0;i<2*abs(y);i++)
		{
			if (b==0) cout<<'S'; else cout<<'N';
			b=1-b;
		}
		cout<<endl;
	}
}