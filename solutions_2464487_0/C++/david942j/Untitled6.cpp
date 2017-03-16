//by daivd942j
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
LL t,r;
bool ok(LL k)
{
	return 2*k*k+(2*r-1)*k <=t;
}
LL bs(LL low,LL up){
	if(up==0)return 0;
	while(low<=up){
		LL mid=low+up>>1;
		if(ok(mid))low=mid+1;
		else up=mid-1;
	}
	return up;
}
int main()
{
	int T,w=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&r,&t);
		LL ans=bs(0,min(t/r/2,(LL)sqrt(t)));
		printf("Case #%d: %lld\n",w++,ans);
	}
}
//r+1 -r  2r+1
//r+3 -r+2  2r+5
//          2r+9
// t = 2x^2 + (2r-1)x
// x = -2r+1 + sqrt(4r^2-4r+1 + 8t) / 4

