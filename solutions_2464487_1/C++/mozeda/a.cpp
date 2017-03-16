#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int T;
long long R, t;
int main()
{
	cin>>T;
	for (int I=1;I<=T;++I)
	{
		cin>>R>>t;
		long long l, r;
		l=0; r=t/R/2;
		if (r>1000000000) r=1000000000;
		while (l<r)
		{
			long long mid = (l+r+1)/2;
		//	cout<<mid<<' '<<(4)*mid*(mid+1)/2-3*mid+2*R*mid<<endl;
			if ((4)*mid*(mid+1)/2-3*mid+2*mid*R<=t)
				l=mid;
			else
				r=mid-1;
		//	cout<<l<<' '<<r<<endl;
		}
		cout<<"Case #"<<I<<": "<<l<<endl;
	}
}
