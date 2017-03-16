#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <cstring>//memset需要
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <deque>
#include <stack>
typedef long long ll;
using namespace std;
//请在此填方案全局部分
ll rr;
ll f(ll n,ll r){
	ll t=1;
	t<<=63;
	t--;
	if (t/n<=(2*r+2*n-1))
	{
		return -1;
	}
	return n*(2*r+1)+2*n*(n-1);
}
ll find(ll t){
	ll l=1,r=1,mid;
	r<<=31;
	while (l<r)
	{
		mid=(l+r)/2;
		ll ans=f(mid,rr);
		if (ans>t||ans==-1)
		{
			r=mid;
		}else l=mid+1;
	}
	return l;
}
////////////////
int main(){
	int tt,cas=1;
	scanf("%d",&tt);
	while (tt--)
	{
		cout<<"Case #"<<cas++<<": ";
		ll t;
		cin>>rr>>t;
		ll ans=find(t);
		cout<<ans-1<<endl;
	}
	return 0;
}