#include <stdio.h>
#include <stdlib.h>

int mintime(int *hist, int max) {
	int i=max;
	while(i > 0 && hist[i] <= 0)
		i--;
	if(i == 1)
		return 1;
		
	int r1, r2, r3, div, mod;
	r1 = i;
//	if(hist[i] >= i)
//		return r1;

	int k, minr2 = 1001;
	div = i/2;
	int j = hist[i];
	hist[i] = 0;
	for(k=1; k <= div; k++) {
		hist[k] += j;
		hist[i-k] += j;
		r2 = mintime(hist, i);
		hist[k] -= j;
		hist[i-k] -= j;
		if(r2 < minr2)
			minr2 = r2;
	}
	hist[i] = j;
/*	int j, minr2=1000;
	for(j=i; j > 1; j--)
		if(hist[j]) {
			if(max == 1000) printf("%d %d\n", j, hist[j]);
			div=j/2;
			mod=j%2;
			hist[j]--;
			hist[div]++;
			hist[div+mod]++;
			r2 = mintime(hist, i);
			hist[j]++;
			hist[div]--;
			hist[div+mod]--;			
			if(r2 < minr2)
				minr2 = r2;
		}*/

//	hist[i] = j;
//	hist[div] -= j;
//	hist[div+mod] -= j;
//	r3 = mintime(hist+1, i-1);
//	r3 = 1000;
	return (r1 < j+minr2 ? r1 : j+minr2);
//	return (r1 < j+r2 ? (r1 < 1+r3 ? r1 : 1+r3) : (j+r2 < 1+r3 ? j+r2 : 1+r3));
}

int main() {
	int *hist = malloc(1100*sizeof(int));
	int n, s, sum, req, i, j, k;

	scanf("%d", &n);
	for(i=0; i < n; i++) {
		scanf("%d", &s);
		for(j=0; j < 1100; j++)
			hist[j] = 0;
		for(j=0; j < s; j++) {
			scanf("%d", &k);
			hist[k]++;
		}
		printf("Case #%d: %d\n", i+1, mintime(hist,1000));
	}
}

