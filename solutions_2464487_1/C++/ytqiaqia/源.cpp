#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <queue>

using namespace std;
const int MAXN = 1e5+10;
const long double eps = 1e-7;
const long double imax = 2e18;
int N,M;
unsigned long long r,t;
unsigned long long fun(unsigned long long k)
{
	return 2*r*k+2*k*k-k;
}
bool judge(unsigned long long k)
{
	if(2.0*r*k+2.0*k*k-1.0*k <=imax+10.0)return true;
	return false;
}
unsigned long long erfen()
{
	unsigned long long ans = 0;
	unsigned long long l = 0,r = 1007106780;
	while(l<=r)
	{
		unsigned long long mid = (l+r)>>1;
		unsigned long long tmp = fun(mid);
		if(!judge(mid))
		{
			r = mid-1;
			continue;
		}
		//cout<<mid<<" "<<tmp<<" ss"<<endl;
		if(tmp<=t)
		{
			l = mid+1;
			ans = max(ans,mid);
		}
		else
		{
			r = mid - 1;
		}
	}
	return ans;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("AA.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; ++i)
	{
		cin>>r>>t;
		cout<<"Case #"<<i<<": "<<erfen()<<endl;
		//scanf("%llu%llu", &r,&t);
		//printf("Case #%d: %llu\n",i, erfen());
	}
	return 0;
}
