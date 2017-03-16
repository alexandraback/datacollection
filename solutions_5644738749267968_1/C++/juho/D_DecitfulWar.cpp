#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
double Naomi[1000];
double Ken[1000];

int gameDecitfulWar()
{
	int score = 0;
	int kn = N - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (Naomi[kn] > Ken[i]) {
			score++;
			kn--;
		} else {
		}
	}
	return score;
}

int gameWar()
{
	int score = 0;
	int kh = N - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (Ken[kh] > Naomi[i]) {
			kh--;
		} else {
			score++;
		}
	}
	return score;
}

void solve()
{
	sort(Naomi, Naomi + N);
	sort(Ken, Ken + N);

	int dwar = gameDecitfulWar();

	int war = gameWar();

	printf("%d %d\n", dwar, war);
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N;j++) {
			scanf("%lf", &Naomi[j]);
		}
		for (int j = 0; j < N;j++) {
			scanf("%lf", &Ken[j]);
		}

		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
