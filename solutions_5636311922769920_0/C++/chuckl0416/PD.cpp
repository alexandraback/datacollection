#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
long long int K, C, S;
long long int i, x, y, Ans;

int main(){
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small-attempt1.out", "w", stdout);
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d:", T);
		scanf("%lld%lld%lld", &K, &C, &S);
		
		if (K>C*S){
			puts(" IMPOSSIBLE");
			continue;
		}
		
		for (i=0; i<S; i++){
			if (i) if (!((i*C)%K)) break;
			Ans = 0;
			for (x=0; x<C; x++) Ans = Ans*K+((i*C+x)%K);
			Ans++;
			printf(" %lld", Ans);
		}
		puts("");
	}
	
	return 0;
}


