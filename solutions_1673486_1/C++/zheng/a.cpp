#include <iostream>
#include <cstdio>
using namespace std;

int t, a, b, d;
double p[200000], ans;

int main()
{
	p[0]=1.0;
	cin>>t;
	for(int i=1; i<=t; ++i)
	{
		cin>>a>>b;
		for(int j=1; j<=a; ++j)
			cin>>p[j];
		ans=b+2;
		double pp=b+1;
		for(int d=a; d>=0; --d)
		{
			pp=pp*p[a-d];
			double temp=2*d+2*b-a+2-pp;
			if(temp<ans) ans=temp;
		}
		printf("Case #%d: %.6lf\n", i, ans);
	}
	return 0;
}

