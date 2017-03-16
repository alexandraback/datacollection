#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const long double eps=1e-20;

LL R,V;

void init(){
	LL tr,tv;
	scanf("%lld%lld",&tr,&tv);
	R=tr; V=tv;
}

bool pd(LL n){
	LL tmp=2*R-3+2*(n+1);
	return V/n-tmp>=0;
}

void work(){
	LL l=0,r=LL(1e18),mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(pd(mid)) l=mid; else r=mid-1;
	}
	printf("%lld",l);
}

int main(){
	int T; scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d: ",t);
		init();
		work();
		printf("\n");
	}
	return 0;
}
