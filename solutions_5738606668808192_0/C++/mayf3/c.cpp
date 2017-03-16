#include <cstdio>

typedef long long LL;

const int N = 8;
const int M = 50;

LL change(int x, int base){
	LL ret = 0, now = 1;
	for(LL i = 0; i < N; i++){
		ret = ret + (((1 << i) & x) != 0) * now;
		now *= base;
	}
	return ret;
}

int main(){
	puts("Case #1:");
	for(LL i = (1 << (N - 1)) + 1, k = 0; k < M; i += 2, k++){
		//printf("%d", i | (i << N));
		LL tmp = (i | (i << N));
		for(LL j = 2 * N - 1; j >= 0; j--){
			if (((1 << j) & tmp) != 0) putchar('1');
			else putchar('0');
		}
		for(int j = 2; j <= 10; j++){
			printf(" %lld", change(i, j));
		}
		puts("");
	}
}
