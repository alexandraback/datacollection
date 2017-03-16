#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int T;
	long long r,t,x;
	double d;
	cin>>T;
	freopen("T.txt", "w", stdout);
	int ca=1;
	{
		while(T--)
		{
			cin>>r>>t;
			d=sqrt((2*r-1)*(2*r-1)+8*t);
			x=(1-2*r+d)/4;
			printf("Case #%d: %lld\n",ca++,x);

		}
	}
	return 0;
}
