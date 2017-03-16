#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long long LINT;

double xx[2000],tt[2000];
int aa[250];

void main()
{
	int t;
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		double d;
		int n,a;
		cin>>d>>n>>a;
		for(int i=0; i<n; i++)
			cin>>tt[i]>>xx[i];

		double tx;
		if(n==1)
			tx=0;
		else
			tx=(d-xx[0])/(xx[1]-xx[0])*tt[1];


		cout<<"Case #"<<ii+1<<":"<<endl;

		for(int i=0; i<a; i++)
		{
			double aa;
			cin>>aa;

			double ty=sqrt(2*d/aa);
			cout<<setprecision(6)<<setiosflags(ios::fixed | ios::showpoint)<<max(tx,ty)<<endl;
		}
	}
}