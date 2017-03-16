#include <iostream>
using namespace std;

int main()
{
	int t,l=1;
	cin>>t;
	while(t--)
	{
		int r,c,w;
		cin>>r>>c>>w;
		int x=c/w;
		int y=c%w;
		x=x*r;
		x--;
		x+=w;
		if(y!=0)
		x++;
		cout<<"Case #"<<l<<": "<<x<<endl;
		l++;
	}
}
