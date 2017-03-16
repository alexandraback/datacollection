#include <cstdio>

using namespace std;

long long twoPower[50];
int ways[50][50];

void problemCase() {
	long long target;
	int buildingCount;
	int i, j;
	int requiredBuilding;
	int full;
	int left;

	for (i = 0; i < 50; i++) for (j = 0; j < 50; j++) ways[i][j] = 0;

	scanf("%d %lld", &buildingCount, &target);

	for (i = 2; twoPower[i - 2] < target; i++) { }
	requiredBuilding = i;
	full = twoPower[i - 2] == target;
	left = target - twoPower[i - 2];

	if (requiredBuilding > buildingCount) {
		printf("IMPOSSIBLE\n");
	} else {
		printf("POSSIBLE\n");
		ways[0][buildingCount - 1] = 1;
		for (i = 1; i < requiredBuilding - 1; i++) {
			ways[0][i] = 1;
			if (i < requiredBuilding - 2 || full) {
				for (j = 1; j < i; j++) {
					ways[i][j] = 1;
				}
				ways[i][buildingCount - 1] = 1;
			} else {
				for (j = 1; j < i; j++) {
					ways[i][j] = left & 1ll;
					left >>= 1;
				}
			}
		}

		for (i = 0; i < buildingCount; i++) {
			for (j = 0; j < buildingCount; j++) {
				printf("%d", ways[i][j]);
			}
			printf("\n");
		}
	}
}

void init() {
	int i;
	long long ans = 1;
	for (i = 0; i < 50; i++) {
		twoPower[i] = ans;
		ans *= 2;
	}
}

int main() {
	int tc, t;

	init();

	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		printf("Case #%d: ", t);
		problemCase();
	}

	return 0;
}