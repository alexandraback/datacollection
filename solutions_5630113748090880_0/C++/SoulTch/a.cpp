#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define si() (scanf("%d", &TEMP), TEMP)

using namespace std;

int TEMP;

int li[100][100];
int hi[3000];
int N;

void solve() {
	N = si();

	for (int i = 0; i < 2600; i++) {
		hi[i] = 0;
	}

	for (int i = 0; i < (N << 1) - 1; i++) {
		for (int j = 0; j < N; j++) {
			hi[si()]++;
		}
	}
	for (int i = 0; i < 2600; i++) {
		if (hi[i] & 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N = si();
	for (int i = 0; i < N; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}
}

