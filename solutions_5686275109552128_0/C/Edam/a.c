#include <stdio.h>

int P[1000];
int D;

int max()
{
	int i, max;
	for(i = 0, max = 0; i < D; i++) {
		if(P[max] < P[i])
			max = i;
	}
	return max;
}

int main(void)
{
	int T, i;
	int j, ii;
	int Time;
	int maxDiner;
	int newTime;

	freopen("B-small-attempt4.in.txt", "r", stdin);
	//freopen("in.txt", "r", stdin);
	scanf("%d", &T);
	freopen("Result.txt", "w", stdout);
	for(i = 0; i < T; i++) {
		Time = 0;
		newTime = 0;
		scanf("%d", &D);
		for(j = 0; j < D; j++) 
			scanf("%d", &P[j]); 
		j = 1;
		Time = P[max()];
		// split diner j's pancakes
		for(j = 1; j < P[max()]; ++j) {
			newTime = 0;
			for (ii = 0; ii < D; ++ii) {
				newTime += (P[ii] - 1) / j;
			}
			newTime += j;
			if(newTime < Time)
				Time = newTime;
		}

		printf("Case #%d: %d\n", i+1, Time);
	}
	return 0;
}