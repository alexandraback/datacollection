#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int K, L, S;
char alpha[100], word[100];

int count_letter(char x) {
	int i, result = 0;
	for(i = 0; i < K; i++) {
		if (alpha[i] == x) result++;
	}
	//printf("%c : %d\n", x, result);
	return result;
}

int overlapping() {
	int i;
	char word2[100] = {0};
	strcpy(word2, word);
	int result = 0;
	for(i = 1; i < L; i++) {
		if ((strncmp(word, &word2[i], L-i) == 0) && (L+i <= S)) result++;
	}
	return result;
	
}

double proba() {
	int i;
	double tab_p[L];
	int max_n = S/L+overlapping();
	int valid = 0;
	double result = 0;
	double proba = 1;
	for(i = 0; i < L; i++) {
		tab_p[i] = (double) count_letter(word[i])/K;
		if (tab_p[i] == 0) return 0.0;
		proba *= tab_p[i];
	}
	for(i = 0; i < K-1; i++) {
		if (alpha[i] != alpha[i+1]) {
			valid = 1;
			break;
		}
	}
	if (valid == 0) return 0;
	for(i = 0; i < max_n; i++) {
		result += (max_n-i)*pow(proba, (max_n-i));
	}
	return max_n-result;
}

int main() {

	int i, T;
	scanf("%d", &T);
	
	for(i = 0; i < T; i++) {
		memset(alpha, 0, 100);
		memset(word, 0, 100);
		scanf("%d %d %d", &K, &L, &S);
		scanf("%s", alpha);
		scanf("%s", word);
		printf("Case #%d: %lf\n", i+1, proba());
	}
}
