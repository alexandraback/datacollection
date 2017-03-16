#include <iostream>
using namespace std;

int n;
int J[1000];
double X;
int m;

void init()
{
	cin>>n;
	X=0;
	for(int i=0;i<n;++i)
	{
		cin>>J[i];		
		X+=J[i];
	}
}

void solve()
{
	double avr=X*2/n;
	m=0;
	double newX=2*X;
	for(int i=0;i<n;++i)
	{
		if(J[i]>=avr)
		{
			newX-=J[i];
			m++;
		}
	}
	for(int i=0;i<n;++i)
	{
		if(J[i]>=avr)
			cout<<"0 ";
		else
			cout<<(newX/(n-m)-J[i])/X*100<<" ";
	}
	cout<<endl;
}

int main()
{
	int T;
	cin>>T;
	for(int ii=1;ii<=T;++ii)
	{
		cout<<"Case #"<<ii<<": ";
		init();
		solve();
	}
}