#include<cstdio>

typedef long long LL;

int T;
LL a, b;
LL gcd(LL a, LL b){
//	printf("#%I64d %I64d\n", a, b);
	return b==0? a : gcd(b, a%b);
}

int main(){
	freopen("A1.in", "r", stdin);
	freopen("A1.out", "w", stdout);
	scanf("%d", &T);
	for(int O=1; O<=T; O++){
		scanf("%I64d/%I64d", &a, &b);
		LL t = gcd(a, b);
		a /= t; b /= t;
		if (b != (b&(-b))){
			printf("Case #%d: impossible\n", O);
			continue;
		}
		int cnt=0;
		for(;b>a;){
			b/=2; cnt++;
			//printf("%I64d %I64d\n", a, b);
		}
		printf("Case #%d: %d\n", O, cnt);
	}
	return 0;
}
