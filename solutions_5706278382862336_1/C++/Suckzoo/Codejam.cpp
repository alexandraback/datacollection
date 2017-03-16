#include <cstdio>
long long a,b;
long long T,Ti;
long long gcd(long long a,long long b) {
	if(a==0) return b;
	return gcd(b%a,a);
}
long long div2(long long x) {
	long long rx=x;
	while(1) {
		if(rx%2==1) break;
		rx/=2;
	}
	return rx==1;
}
long long recur(long long x,long long y) {
	long long gx,gy;
	gx=x;
	gy=y;
	long long g=gcd(gx,gy);
	gx/=g;
	gy/=g;
	if(gx==1 && gy==1) return 0;
	if(2*gx>gy) return 1;
	return 1+recur(gx,gy/2);
}
int main() {
	freopen("input.txt","rt",stdin);
	FILE *fo=fopen("output.txt","wt");
	scanf("%d",&T);
	for(Ti=1;Ti<=T;Ti++) {
		scanf("%lld/%lld",&a,&b);
		long long g=gcd(a,b);
		a/=g;
		b/=g;
		//printf("Case %d proceeding\n",Ti);
		if(!div2(b)) {
			fprintf(fo,"Case #%d: impossible\n",Ti);
		} else {
			long long r=recur(a,b);
			if(r<=40) fprintf(fo,"Case #%lld: %lld\n",Ti,r);
			else fprintf(fo,"Case #%lld: impossible\n",Ti);
		}
	}
	return 0;
}