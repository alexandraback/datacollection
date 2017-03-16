#include <stdio.h>

int gcd(int p, int q){
	if(p==0 || q==0) return p+q;
	else return gcd(q, p%q);
}

int ispossible(int p, int q){
	if(q%2) return -41;
	if(q==1 && p==0) return -41;
	if(q==1 && p==1) return 1;
	if(2*p < q)
		return 1+ispossible(p, q/2);
	if(ispossible(p-q/2, q/2))
		return 1;	
}

int main(){
	int T,i,j,k,p,q,ans;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		scanf("%d/%d",&p,&q);
		int g = gcd(p,q);
		p = p/g;
		q = q/g;
		if(q & (q-1)) ans = -1;
		else
			ans = ispossible(p,q);
		if(ans < 0)
			printf("Case #%d: Impossible\n",i);
		else
			printf("Case #%d: %d\n",i,ans);
	}
}
