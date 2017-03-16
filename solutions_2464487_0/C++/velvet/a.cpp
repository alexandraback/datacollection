#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

ll calc(ll r,ll t)
{
	ll p=1,q=1000000000000ll;
	ll ret=0;
	while (p<=q)
	{
		ll mid=(p+q)/2;
		double f=2.0*mid*mid-mid+2.0*mid*r;
		if (f<=t) ret=mid,p=mid+1;
		else q=mid-1;
	}
	return ret;
}
int main()
{
	int T;
	ll r,t;
	cin>>T;
	for (int run=1;run<=T;run++)
	{
		cin>>r>>t;
		printf("Case #%d: ",run);
		cout<<calc(r,t)<<endl;
	}
	return 0;
}
