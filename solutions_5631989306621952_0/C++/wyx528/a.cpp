#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string work()
{
	string a,b;
	cin>>a;
	for (int i=0;i<a.length();i++)
	{
		string x=b+a[i],y=a[i]+b;
		if (x>y) b=x;
		else b=y;
	}
	return b;
}
int main()
{
	freopen ("small.in","r",stdin);
	freopen ("small.out","w",stdout);
	int T;
	cin>>T;
	for (int i=1;i<=T;i++)
	{
		cout<<"Case #"<<i<<": ";
		cout<<work()<<endl;
	}
	return 0;
}