#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


double naomi[1000], ken[1000];
int deceitiful(double naomi[], double ken[], int N) {
	int score = N;
	for (int i = 0, j = 0; i < N; ++i) {
		if (naomi[i] < ken[j]) {
			--score;
		}
		else {
			++j;
		}
	}
	return score;
}
int war(double naomi[], double ken[], int N) {
	int score = N;
	for (int i = 0, j = 0; i < N && j < N; ++i) {
		while (j < N && naomi[i] > ken[j]) {
			++j;
		}
		if (j < N) {
			--score;
			++j;
		}
	}
	return score;
}
int main(){
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		printf("Case #%d: ", cas);
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%lf", naomi + i);
		}
		for (int i = 0; i < N; ++i) {
			scanf("%lf", ken + i);
		}
		sort(naomi, naomi + N);
		sort(ken, ken + N);
		//for (int i = 0; i < N; ++i) fprintf(stderr, "%.3f ", naomi[i]); fprintf(stderr, "\n");
		//for (int i = 0; i < N; ++i) fprintf(stderr, "%.3f ", ken[i]); fprintf(stderr, "\n");
		printf("%d %d\n", deceitiful(naomi, ken, N), war(naomi, ken, N));
	}
	return 0;
}
