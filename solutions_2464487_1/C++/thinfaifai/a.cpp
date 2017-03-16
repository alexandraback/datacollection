#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
		LL r,tt;
		scanf("%lld%lld",&r,&tt);
		LL mid,mi = 0,mx = 707106781,ret = 0;
		while (mi < mx) {
			mid = (mi+mx)/2;
			//printf("(%lld,%lld) %lld %lld\n",mi,mx,mid,((2*r+1+2*r+4*mid-3)*mid)/2 );
			if ((2*r+1+2*r+4*mid-3) <= tt*2/mid) {
				ret = max(ret,mid);
				mi = mid+1;
			}
			else mx = mid;
		}
		printf("Case #%d: %lld\n",t,ret);
	}
	return 0;
}
