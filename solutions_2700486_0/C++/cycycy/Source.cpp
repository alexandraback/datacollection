#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


double c[2000][2000];

int main()
{
	string input="B-small-attempt3.in",output="1.out";
	ifstream infile("B-small-attempt4.in",ios::in);
	ofstream oufile("1.out",ios::out);
	int t;
	long long n,a,m,x,y;
	long long ans,k,an;
	infile>>t;
	c[0][0]=0;
	for (int i=1;i<2000;i++)
	{
		c[i][0]=0;
		c[i][i]=1;
		for (int j=1;j<i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])/2.0;
	}
	for (int loop=1;loop<=t;loop++)
	{
		infile>>n>>x>>y;
		for (int i=1;i*(2*i-1)<=n;i++)
			m=i;
		a=n-(m*(2*m-1));
		m++;
		if ((abs(x)+y)/2+1<m)
		{
			oufile<<"Case #"<<loop<<": "<<"1.0"<<"\n";
			continue;
		}
		if ((abs(x)+y)/2+1>m)
		{
			oufile<<"Case #"<<loop<<": "<<"0.0"<<"\n";
			continue;
		}
		m=2*m-2;
		if (y==m)
		{
			oufile<<"Case #"<<loop<<": "<<"0.0"<<"\n";
			continue;
		}
		if (a<=m)
		{
			if (y>=a)
				oufile<<"Case #"<<loop<<": "<<"0.0"<<"\n";
			else
				oufile<<"Case #"<<loop<<": "<<c[a+1][a-y]<<"\n";
		}
		else
		{
			if (y<a-m)
				oufile<<"Case #"<<loop<<": "<<"1.0"<<"\n";
			else
				oufile<<"Case #"<<loop<<": "<<c[a+1][a-y]<<"\n";
		}
	}
}