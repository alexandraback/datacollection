#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int cases, a, b, keys;
	float *p, prob, min;
	
	scanf("%d", &cases);
	
	for (int z=1; z<=cases; z++) {
		scanf("%d %d", &a, &b);
		
		p = malloc(sizeof(int) * a);
		
		for (int i=0; i<a; i++) {
			scanf("%f", &(p[i]));
		}
		
		/* press enter, always faster than n backspaces */
		min = b + 2;
		
		/* backspace (a-1)...0 times */
		for (int i=a-1; i>=0; i--) {
			prob = 1;
			keys = 0;
			for (int j=0; j<a-i; j++) {
				prob *= p[j];
			}
			/* Chance everything before i was right */
			keys = (b - a) + 2*i + 1;
			
			prob = keys * prob + (keys + b + 1) * (1 - prob);
			if (prob < min) {
				min = prob;
			}
		}
		
		printf("Case #%d: %f\n", z, min);
		
		free(p);
	}
	
	return 0;
}