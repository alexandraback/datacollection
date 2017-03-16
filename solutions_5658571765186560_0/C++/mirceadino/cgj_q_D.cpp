#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

int number_of_cases, testcase;
int X, R, C;

int main() {
	int sol = 0;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &number_of_cases);

	for (testcase = 1; testcase <= number_of_cases; testcase++) {
		scanf("%d%d%d", &X, &R, &C);

		sol = 0;

		if (R > C) swap(R, C);

		if (X <= 6 && (R * C) % X == 0) {
			if (X <= 2) sol = 1;

			if (X == 3 && R >= 2) sol = 1;

			if (X == 4 && R >= 3) sol = 1;

			if (X == 5 && R >= 4) sol = 1;

			if (X == 6 && R >= 5) sol = 1;
		}

		printf("Case #%d: %s\n", testcase, sol ? "GABRIEL" : "RICHARD");
	}

	return 0;
}