#include<stdio.h>

long long countbinary(long long x, int cnt, int depth){
	if(x < 1) return cnt;
	if(x % 2 == 1) return countbinary(x/2, depth, depth+1);
	else return countbinary(x/2, cnt, depth+1);

}

long long gcd(long long x, long long y){
	if(y == 0) return x;
	else return gcd(y, x%y);
}

int main(){
	int T;
	int cnt = 0;
	scanf("%d", &T);
	while(T--){
		long long a, b;
		scanf("%lld/%lld", &a, &b);
		long long g = gcd(b, a);
		if(g != 1) a/=g, b/=g;
		//printf("%d %d", a, b);
		//printf("g%d", g);
		bool flag = true;
		int power = 0;
		for(long long i = b; i > 1;){
			if(i%2 == 1){
				flag = false;
				break;
			}else power++, i/=2;	
		}
		if(!flag){
			printf("Case #%d: impossible\n", ++cnt);
			continue;
		}
		//printf("p%d", power);	
		printf("Case #%d: %lld\n", ++cnt, power - countbinary(a, 0, 0));
	}

	return 0;
}
