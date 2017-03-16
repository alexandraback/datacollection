#include<stdio.h>


long long gcd(long long a, long long b){
	if(b==0){
		return a;
	}else {
    	return gcd(b, a%b);
    }
}

int main(){
	freopen("1C/A-large.in","r",stdin);
	freopen("1C/out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		long long P,Q;
		scanf("%lld/%lld",&P,&Q);

		long long mod = gcd(P,Q);
		P /= mod;
		Q /= mod;

		long long p=P,q=Q;

		int x=0;
		while(q%2==0 && x<40){
			q /= 2;
			x++;
		}

		if(x <= 40 && q != 1){
			printf("Case #%d: impossible\n",t);
		}else{
			x=0;
			while(p < Q){
				x++;
				p *= 2;
			}
			printf("Case #%d: %d\n",t,x);
		}
	}
}
