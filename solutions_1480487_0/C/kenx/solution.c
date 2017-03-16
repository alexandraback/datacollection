#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static long int scores[200];
static long double safeties[200];

void gSafeties(int N) {
	long double sum = 0, sum2 = 0;
	int x, newN;
	long double y1, y2;
	
	for (x = 0; x < N; x++)
		sum += scores[x];
	
	y1 = (long double)(sum + sum)/N;
	
	newN = 0;
	for (x = 0; x < N; x++) {
		if (y1 > scores[x]) {
			newN++;
			sum2 += scores[x];
		}
	}
	
	y2 = (long double)(sum2 + sum)/newN;
	
	//printf("sum = %.6Lf, y1 = %.6Lf, N = %d, y2 = %.6Lf, newN = %d\n", sum, y1, N, y2, newN);
	

	for (x = 0; x < N; x++) {
		if (y1 < scores[x])
			safeties[x] = 0.0;
		else
			safeties[x] = (long double)((long double)(y2 - scores[x])/sum) * 100;
	}
}


int main(void) {
	int values[2];
	int num_times, x, y, z, num_items;
	int N;

	scanf("%d", &num_times);
	//printf("Number of times: %d\n", num_times);
	for (x = 01; x <= num_times; x++) {
		
		scanf("%d", &N);
		
		for (y = 0; y < N; y++) {
			
			scanf("%ld", &scores[y]);
			//printf("%ld ", scores[y]);
		}
		//printf("\n");
		gSafeties(N);
		printf("Case #%d: ", x);
		for(y = 0; y < N; y++) {
			printf("%.6Lf ", safeties[y]);
		}
		printf("\n");
	}
}