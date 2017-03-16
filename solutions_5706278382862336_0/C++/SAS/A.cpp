#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int checktwo(long long int a){
	while(a != 0 && a != 1){
		if(a % 2 != 0)return -1;
		a/= 2;
	}
	return 1;
}
long long int gcd(long long int a,long long int b){
	if(b > a)return gcd(b,a);

	if(a % b != 0)return gcd(b, a % b);
	return b;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <=T ;ca++){
		long long int p,q;
		scanf("%lld/%lld", &p, &q);
		long long int g = gcd(p,q);
		if(g != 1){
			p /= g;
			q /= g;
		}

		printf("Case #%d: ",ca);
		if(checktwo(q) == -1){
			printf("impossible\n");
			continue;
		}

		long long int ans = 0;
		for(;p < q;ans++){
			p *= 2;
		}
		printf("%lld\n",ans);
		


	}
	return 0;
}
