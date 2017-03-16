 //if you want,you can

#include<stdio.h>
#include<iostream>

using namespace std;
int n,m,t;
double zu[200000];


double f()
{
	double ret=10000000;

	double pp=1;

	for(int i=n;i>=0;i--)
	{
		double ran=m-n+i*2;
		ran++;
		if(i!=n)
		{
			pp*=zu[n-i-1];
		}
		ran+=(1-pp)*(m+1);
		ret=ret<ran?ret:ran;
	}
	return ret;
}


int main()
{
	freopen("a.out","w",stdout);
	cin>>t;

	for(int tt=0;tt<t;tt++)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>zu[i];
		}
		double ret=1+m+1;

		double ran=f();
		ret=ret<ran?ret:ran;
		cout<<"Case #"<<tt+1<<": "<<ret<<endl;
	}
}
