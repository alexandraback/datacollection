#include <stdio.h>
#include <stdlib.h>

int bestNormal(int score) {
	return (score + 2) / 3;
}

int bestSurprising(int score) {
	if(score < 2 || score > 28)
		return -1;
	else
		return (score + 4) / 3;
}

int cmpInt(const void* v1, const void* v2) {
	return *(int*) v2 - * (int*) v1;
}

int main() {
	int T, N, S, p;
	int t[100];
	int tno, i, s;
	
	scanf("%d", &T);
	
	for(tno = 0; tno < T; tno++) {
		scanf("%d%d%d", &N, &S, &p);
		for(i = 0; i < N; i++) {
			scanf("%d", t + i);
		}
		
		qsort(t, N, sizeof(int), cmpInt);
		
		for(i = 0; i < N && bestNormal(t[i]) >= p; i++);
		for(s = 0; i < N && s < S && bestSurprising(t[i]) >= p; i++, s++);
		
		printf("Case #%d: %d\n", tno + 1, i);
	}
	
	return EXIT_SUCCESS;
}

int main1() {
	int T, N, S, p;
	int t[100];
	int tno, i, s;
	int count;
	
	scanf("%d", &T);
	
	for(tno = 0; tno < T; tno++) {
		scanf("%d%d%d", &N, &S, &p);
		for(i = 0; i < N; i++) {
			scanf("%d", t + i);
		}
		
		qsort(t, N, sizeof(int), cmpInt);
		
		printf("Case #%d: ", tno + 1);
		printf("%d googlers, %d special, %d minimum [ ", N, S, p);
		
		for(i = 0; i < N; i++) {
			printf("%d(%d,%d) ", t[i], bestNormal(t[i]), bestSurprising(t[i]));
		}
		
		for(i = 0, count = 0; i < N && bestNormal(t[i]) >= p; i++, count++);
		printf("] %d NORMAL, ", i);
		for(s = 0; i < N && s < S && bestSurprising(t[i]) >= p; i++, s++, count++);
		printf("%d TOTAL\n", i);
	}
	
	return EXIT_SUCCESS;
}

int main0() {
	int i;
	
	printf("NORMAL\n");
	printf("------\n");
	for(i=0; i<=30; i++) {
		printf("%2d:%2d |\t", i, bestNormal(i));
	}
	printf("\n");
	printf("SURPRISING\n");
	printf("----------\n");
	for(i=0; i<=30; i++) {
		printf("%2d:%2d |\t", i, bestSurprising(i));
	}
	printf("\n");
	
	return EXIT_SUCCESS;
}
