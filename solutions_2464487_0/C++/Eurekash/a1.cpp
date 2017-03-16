#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;++i)
	{
		LL r,t;
		cin>>r>>t;
		LL lo=1,hi=1000000000LL,mid;
		while(lo<hi)
		{
			mid=(lo+hi+1)/2LL;
			if((2*r-1+2*mid)<=t*1.0/mid)  lo=mid;
			else  hi=mid-1;
		}
		cout<<"Case #"<<i<<": "<<lo<<endl;
	}
	return 0;
}
