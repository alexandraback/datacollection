#include <stdio.h>

// a<=b
unsigned long long gcd(unsigned long long a, unsigned long long b){
	if(a == 0) return b;
	return gcd(b%a,a);
}

int powof2(unsigned long long x){
	int i;
	for(i=0; i <= 40; i++){
		unsigned long long t = x >> i;
		if(t == 1) return i;
	}
	return -1;
}

int go(void){
	unsigned long long p;
	unsigned long long q;
	scanf("%llu/%llu",&p,&q);
	//printf("DEBUG: %llu %llu\n",p,q);
	if(p>q) return -1;
	unsigned long long div = gcd(p,q);
	p /= div;
	q /= div;
	int a = powof2(p);
	int b = powof2(q);
	//printf("DEBUG: %llu %llu %d %d %llu\n",p,q,a,b,div);
	if(b == -1 || q != (((unsigned long long)1) << b)) return -1;
	return b-a;
}

int main(int argc, char** argv){
	int t;
	scanf("%d",&t);
	int i;
	for(i=1; i<=t; i++){
		int ans = go();
		printf("Case #%d: ",i);
		switch(ans){
		case -1:
			printf("impossible\n");
			break;
		default:
			printf("%d\n",ans);
			break;
		}
	}
	return 0;
}
