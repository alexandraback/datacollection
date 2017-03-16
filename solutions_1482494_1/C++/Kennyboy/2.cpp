#include <cstdio>
#include <algorithm>

const int MAX = 1000;

int n;
int star1[MAX];
int star2[MAX];
int levelGot[MAX];
int sortable[MAX];

void proc() {

	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d ", &star1[i], &star2[i]);
		levelGot[i] = 0;
	}

	int numTries = 0;
	int numStars = 0;
	while (numStars < 2 * n) {
		bool gotten = false;
		for (int i = 0; i < n; i++) {
			if (levelGot[i] < 2) {
				if (star2[i] <= numStars) {
					numStars += 2 - levelGot[i];
					levelGot[i] = 2;
					gotten = true;
					numTries++;
					break;
				}
			}
		}
		if (gotten == true) {
			continue;
		}

		int best = -1;
		for (int i = 0; i < n; i++) {
			if (levelGot[i] < 1) {
				if (star1[i] <= numStars) {
					if (best == -1 || star2[i] > star2[best]) {
						best = i;
						gotten = true;
					}
				}
			}
		}

		if (gotten) {
			numStars += 1 - levelGot[best];
			levelGot[best] = 1;
			numTries++;
		}

		if (!gotten) {
			printf("Too Bad");
			return;
		}
	}
	printf("%d", numTries);
}

int main() {
	int t;
	scanf("%d ", &t);

	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		proc();
		printf("\n");
	}

	return 0;
}
