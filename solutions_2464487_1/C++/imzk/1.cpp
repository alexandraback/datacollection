#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long r,t;
double f(double x)
{
	return 2*x*x+x*(2*r-1)-t;
}
int main()
{
	int T;
	double d;
	cin>>T;
	double left,right,mid;
freopen("T.txt", "w", stdout);
	int ca=1;
	{
		while(T--)
		{
			cin>>r>>t;
			left=1,right=100000000;
			while(right-left>0.00001)
			{
				mid=(left+right)/2;

				if(f(mid)<0)
				{
					left=mid;
				}
				else if(f(mid)>0)
				{
					right=mid;
				}
				else
				{
					left=right=mid;
					break;
				}
			
			}
			printf("Case #%d: %lld\n",ca++,(long long)((left+right)/2));

		}
	}
	return 0;
}
