#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double bestKeystrokes(int typed, int total, double * probs) {
	double best, sofar, check, sum;
	int x, y;
	
	// enter right away
	best = (double) (total + 2);
	//printf("@> %lf\n", best);

	for (x = 0; x <= typed; x++) {
		sofar = 1;
		sum = (double)((total - typed) + x + x + 1);
		for (y = 0; y < typed-x; y++) {
			sofar *= probs[y];
		}
		check = sofar*(sum) + (1-sofar)*(sum+total+1);
		//printf("-> %lf\n", check);
		
		best = check < best ? check: best;
	}

	
	return best;
}


int main(void) {
	int num_times, x , y, tmp;
	int typed, total;
	double z;
	double * probs;
	

	scanf("%d", &num_times);
	//printf("Number of times: %d\n", num_times);
	for (x = 1; x <= num_times; x++) {
		scanf("%d", &typed);
		scanf("%d", &total);
		
		probs = (double *) malloc(sizeof(double) * typed);
		for (y = 0; y < typed; y++)
			scanf("%lf", &probs[y]);
		
		z = bestKeystrokes(typed, total, probs);
		printf("Case #%d: %.6lf\n", x, z);
		free(probs);
	}
	return 0;
}
