#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;
int casenum,T;
unsigned long long rr,tt;
bool check(unsigned long long x)
{
	return (2*x*rr+(2*x-1)*x<=tt);
}
unsigned long long solve(unsigned long long l,unsigned long long r)
{
	if (l==r) return l;
	if (l+1==r)
	{
		if (check(r)) return r;
		return l;
	}
	unsigned long long mid=(l+r)/2;
	if (check(mid)) return solve(mid,r);
	return solve(l,mid-1);
}
int main()
{
	freopen("gcj.in","r",stdin);
	freopen("gcj.out","w",stdout);

	cin>>T;
	for (casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<": ";
		cin>>rr>>tt;
		unsigned long long l=1;
		unsigned long long r=tt/2/rr;
		if (sqrt(tt/2)<r) r=sqrt(tt/2);
		cout<<solve(l,r)<<endl;
	}
	return 0;
}
