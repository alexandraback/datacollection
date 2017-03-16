#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define si() (scanf("%d", &TEMP), TEMP);

using namespace std;

int TEMP;

int K, C, S;

long long int check(int *li) {
	long long int ret = li[0];

	for (int i = 1; i < C; i++) {
		ret *= K;
		ret += li[i];
	}
	return ret;
}

void solve() {
	scanf("%d%d%d", &K, &C, &S);

	if (S * C < K) {
		printf("IMPOSSIBLE\n");
		return;
	}

	int list[200];
	for (int i = 0; i < (K - 1) / C + 1; i++) {
		if (C * (i + 1) > K) {
			for (int j = i * C ; j < K; j++) {
				list[j - i * C] = j;
			}
			for (int j = K; j < C * (i + 1) ; j++) {
				list[j - i * C] = 0;
			}
		}
		else {
			for (int j = i * C ; j < C * (i + 1) ; j++) {
				list[j - i * C] = j;
			}
		}
		printf("%lld ", check(list) + 1);
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

