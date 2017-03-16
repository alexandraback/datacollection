#include <iostream>
#include <cstdio>

long long r,k;

bool cando(long long n) {
	double ans=(2*(double)r+2*(double)n-1)*(double)n;
	if (ans>k) return false;
	return true;
}

long long find(long long l,long long r) {
	//printf("%lld %lld\n",l,r);
	if (l==r) return l;
	long long t=l/2+r/2;
	if ((l%2!=0)&&(r%2!=0)) t++;
	if (cando(t+1)) return find(t+1,r);
	return find(l,t);
}

int main() {
	int t,tt;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%lld%lld",&r,&k);
		printf("Case #%d: %lld\n",tt,find(0,k));
	}
	return 0;
}
