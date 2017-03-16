#include<cstdio>
#define LL long long
int t;
LL n;
LL flip(LL x){
	LL y = 0;
	while(x){
		y*=10;
		y+= x%10;
		x/=10;
		}
	return y;
	}
int main(){
    scanf("%d",&t);
    while(t--){
		scanf("%lld",&n);
		printf("%lld\n",flip(n));
		}
	}
