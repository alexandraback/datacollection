//Dan Johnson
//Google Code Jam
//Qualifying Round 2012
//Problem B
//Dancing With the Googlers
#include <stdio.h>

int main() {
	int T;
	scanf("%d\n", &T);
	int i, x;
	int num;
	int N, S, p;
	for(i = 0; i < T; ++i) {
		int count = 0;
		int surprise_eligible = 0;
		scanf("%d %d %d ", &N, &S, &p);
		int required_score = 3 * p - 2;
		int score;
		for(x = 0; x < N; ++x) {
			scanf("%d", &score);
			if (score >= required_score) {
				++count;
			}
			else if (score >= p) {
				int smallest = (score - p) / 2; //floor ok
				if (p-smallest <= 2) {
					++surprise_eligible;
				}
			}
		}
		if(surprise_eligible > S) surprise_eligible = S;
		num = count + surprise_eligible;
		if (num > N) num = N;
		printf("Case #%d: %d\n", i + 1, num);
	}
}
