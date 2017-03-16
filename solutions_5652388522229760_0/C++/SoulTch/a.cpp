#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define si() (scanf("%d", &TEMP), TEMP);

using namespace std;

int TEMP;

void solve() {
	int N = si();
	if (!N) {
		printf("INSOMNIA\n");
		return;
	}

	int table[10];

	for (int i = 0; i < 10; i++) table[i] = 0;

	int c = 0;
	while (1) {
		c += N;
		for (int j = c; j > 0; j /= 10) {
			table[j % 10] = 1;
		}

		int flag = true;
		for (int i = 0; i < 10; i++) {
			flag = flag & table[i];
		}
		if (flag) {
			printf("%d\n", c);
			return;
		}
	}
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