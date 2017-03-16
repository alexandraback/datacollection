#include <stdio.h>
#include <math.h>

int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t=0;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		long long r,t;
		scanf("%lld %lld",&r,&t);
		long long p = (long long)sqrt((2*r-1)*(2*r-1)+8*t);
		long long n = (p-2*r+1)/4;
		printf("Case #%d: %lld\n",tt,n);
	}
	return 0;
}