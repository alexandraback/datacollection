#include <stdlib.h>
#include <stdio.h>

int max(int a, int b) {
	if (a > b) return a;
	return b;
};

int get_score_if_hit(int X, int W) {
	if (X <= 0)
		return 0;
	if (X > W)
		return W + 1;
	return X;
};


int last_line_score(int X, int W) {
	if (X <= 0)
		return 0;
	if (X <= W)
		return X;
	int score_if_miss = 1 + last_line_score(X - W, W);
	int score_if_hit =  get_score_if_hit(X, W);
	return max(score_if_miss, score_if_hit);
};
	


int solve(int ctry){
	unsigned int X, Y, W;
	scanf("%u %u %u", &Y, &X, &W);
	int rez = (Y - 1) * (X / W);	// rest of the lines
	rez += last_line_score(X, W);
	printf("Case #%d: %d\n", ctry, rez);
};


int main(){

	if (freopen("test.in", "rt", stdin)){
//		freopen("A-large-practice.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	if (freopen("A-small-attempt0.in", "rt", stdin)){
		freopen("A-small-attempt0.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	if (freopen("A-large.in", "rt", stdin)){
		freopen("A-large.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	return 0;
};