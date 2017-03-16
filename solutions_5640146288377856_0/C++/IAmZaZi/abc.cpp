#include<iostream>
using namespace std;
void solve(int c,int w)
{
	if(w==c)
	{
		cout<<w;
		return;
	}
	else
	{
		int x=c/w;
		int a1=w-1;
		int a2=c-x*w;
		if(a2>1)
			a2=1;
		cout<<x+(a2+a1);
	}	
}
int main()
{
	int test,r,c,w;
	cin>>test;
	for(int i=1;i<=test;i++)
	{
		cin>>r>>c>>w;
		cout<<"Case #"<<i<<": ";
		solve(c,w);
		cout<<endl;
	}
}
