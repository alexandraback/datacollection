#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
long long int N;
long long int i, x, C, D;

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		scanf("%lld", &N);
		if (N==0){
			puts("INSOMNIA");
			continue;
		}
		
		C = (1<<10)-1;
		i = 0;
		while(C){
			i++;
			x = N*i;
			while(x){
				D = x%10;
				if (C&(1<<D)) C -= (1<<D);
				x /= 10;
			}
		}
		
		printf("%lld\n", N*i);
	}
	
	return 0;
}


