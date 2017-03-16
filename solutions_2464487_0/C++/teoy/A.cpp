#include "iostream"
#include "cstring"
#include "cstdio"
#include "cmath"
using namespace std;
typedef long long LOL;
bool gao(LOL now,LOL r,LOL t)
{
	LOL l=r+(now-1)*2;
	double sum=(double)(l+r)*(double)now+now;
	if(sum>t){
		return false;
	}
	return true;
}
int main(void)
{
	int T,g=0;
	LOL r,t;
	freopen("A-small-attempt0.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&r,&t);
		LOL le=1,ri=1000000000ll;
		while(le<ri){
			LOL mid=(le+ri+1)/2;
			if(gao(mid,r,t)){
				le=mid;
			}else{
				ri=mid-1;
			}
		}
		printf("Case #%d: %lld\n",++g,le);
	}
	return 0;
}