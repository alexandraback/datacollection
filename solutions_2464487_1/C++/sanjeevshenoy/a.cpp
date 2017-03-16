#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<limits>
#include<cassert>
#include<sstream>
#include<cmath>

using namespace std;
typedef long long ll;

//const int max_n=100005;

int T;
ll r,t;
//int a[max_n];

ll f(ll n)
{
	if(LLONG_MAX/n<(2*r-3))
		return LLONG_MAX;
	return (2*r-3)*n+2*n*(n+1);
}

ll binsrc(ll l , ll r)	//[)
{
	if(r==l+1ll)
		return l;
	ll mid=(l+r)/2;
	if(f(mid)<=t)
		return binsrc(mid,r);
	else
		return binsrc(l,mid);
}

int main()
{
    scanf("%d",&T);
	for(int z=1; z<=T; z++)
	{
		cin>>r>>t;
		ll res=binsrc(0,(ll)sqrt(t)+1);
		
		printf("Case #%d: ",z);
		cout<<res<<"\n";
    }
	
    return 0;
}
