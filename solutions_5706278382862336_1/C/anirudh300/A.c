#include <stdio.h>

long long gcd(long long p, long long q){
	if(p==0LL || q==0LL) return p+q;
	else return gcd(q, p%q);
}

int ispossible(long long p, long long q){
	if(q%2LL) return -41;
	if(q==1LL && p==0LL) return -41;
	if(q==1LL && p==1LL) return 1;
	if(2LL*p < q)
		return 1+ispossible(p, q/2LL);
	if(ispossible(p-q/2LL, q/2LL))
		return 1;	
}

int main(){
	long long T,i,j,k,p,q,ans;
	scanf("%lld",&T);
	for(i=1LL;i<=T;i++){
		scanf("%lld/%lld",&p,&q);
		long long g = gcd(p,q);
		p = p/g;
		q = q/g;
		if(q & (q-1LL)) ans = -1LL;
		else
			ans = ispossible(p,q);
		if(ans < 0)
			printf("Case #%lld: Impossible\n",i);
		else
			printf("Case #%lld: %lld\n",i,ans);
	}
}
