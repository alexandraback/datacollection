#include<iostream>
#include<fstream>
#include<stdio.h>
#include <iomanip>
using namespace std;
double a[1000000];
int main()
{
	int t,ii,i,j,n,m;
	double g1,t1,t2,tx,tg;
	ifstream ifile;
	ifile.open("A-small-attempt0.in");
	ofstream ofile;
	ofile.open("2.txt");

	ifile>>t;
	for(ii=1;ii<=t;ii++)
	{
		ifile>>n>>m;
		g1=1;
		for(i=1;i<=n;i++)
		{
		  ifile>>a[i];
		  g1=g1*a[i];
		}
		t1=g1*(m-n+1)+(1-g1)*(2*m-n+2);
		if (n==m)
		{
			t2=g1+(1-g1)*(m+2);
		}
		else
		{
			t2=(m+2);
		}
		if (t1>t2) t1=t2;
		tg=1;
		for(j=n;j>=1;j--)
		{
			tx=(m-n+2*j+1)*tg+(2*m-n+2*j+2)*(1-tg);
			if (tx<t1) t1=tx;
			tg=tg*a[n-j+1];
		}
		
		//cout<<setprecision(4)<<t1<<endl;
		//fprintf("2.txt","%.7lf",t1);
		printf("Case #%d: %.7lf\n",ii,t1);
		//ofile<<"Case #"<<ii<<": "<<t1<<endl;
	}
	ifile.close();
	ofile.close();
	return 0;
}

