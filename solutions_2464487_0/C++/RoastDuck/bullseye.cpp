#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;
ll r0,t;

int main()
{
	freopen("bullseye.in","r",stdin);
	freopen("bullseye.out","w",stdout);
	int T;
	cin>>T;
	for (int tt=1;tt<=T;tt++)
	{
		cin>>r0>>t;
		ll l(0), r(min(t/(2*r0+1),2000000000ll)), mid, ans(-1);
		while (l<=r)
		{
			mid=((l+r)>>1);
			if (mid*(2*r0+1)+2*mid*(mid-1)<=t)
				l=mid+1, ans=max(ans,mid);
			else
				r=mid-1;
		}
		printf("Case #%d: %I64d\n",tt,ans);
	}
	return 0;
}

