#include <stdio.h>

int T, N, X, Y;

double com[3100][3100];

void print(int t, double p){
	printf("Case #%d: %.8lf\n", t, p);
}

void init(void){
	int i, j;

	com[0][0] = 1.0;
	for (i=1; i<3100; i++){
		com[i][0] = com[i][i] = com[i-1][0]/2.0;
		for (j=1; j<i; j++)
			com[i][j] = (com[i-1][j]+com[i-1][j-1])/2.0;
	}
}

int main(void){
	int t;
	int i, j, k;

	double sum;

	init();

	scanf("%d", &T);
	for (t=1; t<=T; t++){
		scanf("%d%d%d", &N, &X, &Y);
		if (X<0) X = -X;

		for (i=0; i<X+Y; i+=2){
			N -= i*2+1;
			if (N<0) break;
		}

		//printf("%d\n", N);

		if (N<0 || N<Y+1){
			print(t, 0.0);
			continue;
		}
		if (N>=(X+Y)*2+1){
			print(t, 1.0);
			continue;
		}
		if (X==0){
			print(t, 0.0);
			continue;
		}
		if (N==(X+Y)*2){
			print(t, 1.0);
			continue;
		}

		sum = 0.0;
		for (i=Y+1; i<=X+Y; i++){
			if (N-i >= X+Y+1) continue;
			if (i<X+Y && N-i<X+Y){
				sum += com[N][i];
			}
			else {
				if (i==X+Y) j = N-i;
				else j = i;

				k = 0;
				for (; j>=0; j--){
					k ++;
					//printf("(%d, %d): %lf\n", N-k, j, com[N-k][j]);
					sum += com[N-k][j]/2.0;
				}
			}
			//printf("%lf\n", sum);
		}

		print(t, sum);
	}
	return 0;
}
