#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const double eps=1e-8;

double R,V;

void init(){
	scanf("%lf%lf",&R,&V);
}

bool pd(double n){
	double tmp=2*R*n-3*n+2*n*(n+1);
	return V-tmp>=-eps;
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
