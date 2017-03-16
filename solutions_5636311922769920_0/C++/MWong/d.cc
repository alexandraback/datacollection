#include<cstdio>
#define LL long long

int t;
LL k, c, s;

int main(){
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ca++){
		scanf("%lld%lld%lld", &k, &c, &s);
		printf("Case #%d:", ca);
		if (s * c >= k){
			LL tmp = 0, base = 1;
			bool out = false;
			for (int i = 0; i < k; i++){
				out = true;
				tmp += base * i;
				base *= k;
				if ((i + 1) % c == 0){
					out = false;
					printf(" %lld", tmp + 1);
					tmp = 0; base = 1;	
				}
			}
			if (out) printf(" %lld\n", tmp + 1);
			else printf("\n");
		}else {
			printf(" IMPOSSIBLE\n");
		}
	}
}
