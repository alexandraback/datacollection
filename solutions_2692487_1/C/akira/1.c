#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mote[100];

int fcmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	int x, y, T, A, N, i, n, t;
	scanf("%d", &T);
	for(x = 1; x <= T; ++x){
		scanf("%d %d", &A, &N);
		for(i = 0; i < N; ++i){
			scanf("%d", mote + i);
		}
		qsort(mote, N, sizeof(int), fcmp);
		y = N;
		t = i = 0;
		if(A > 1){
			while(i < N){
				while(i < N && mote[i] < A){
					A += mote[i++];
				}
				if(t + N - i < y){
					y = t + N - i;
				}
				if(i >= N){
					break;
				}
				n = log((double)(mote[i] - 1) / (A - 1)) / log(2);
				A = (A - 1) * (1 << n) + 1;
				while(A <= mote[i]){
					A += A - 1;
					++n;
				}
				t += n;
				if(t >= y){
					break;
				}
			}
		}
		printf("Case #%d: %d\n", x, y);
	}
}