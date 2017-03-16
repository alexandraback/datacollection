#include <cstdio>

#define BIG 1LL<<40
typedef long long ll;

ll gcd(ll a, ll b){
	if(b > a) return gcd(b,a);
	return (b==0)?a:gcd(b,a%b);
}

int main(){
	int t;
	ll big = BIG;
	scanf("%d", &t);
	for(int x = 1; x <= t; x++){
		printf("Case #%d: ", x);
		ll a, b;
		char aoeu;
		scanf(" %lld %c %lld ", &a, &aoeu, &b);
		ll g = gcd(a,b);
		a/=g;
		b/=g;
		if(big%b) printf("impossible\n");
		else{
			a *= (big/b);
			ll p2 = 1, c = 40;
			while(p2 <= a){
				c--;
				p2 *= 2;
			}
			c++;
			if(c <= 0) c = 1;
			printf("%d\n", c);
		}
	}
	return 0;
}


