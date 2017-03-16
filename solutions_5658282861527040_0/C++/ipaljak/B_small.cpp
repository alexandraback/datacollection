#include <cstdio>

using namespace std;

int T, A, B, K;

void solve(int t) {

	printf("Case #%d: ", t);
	scanf("%d%d%d", &A, &B, &K);

	int sol = 0;
	for (int i = 0; i < A; ++i) {
		for (int j = 0; j < B; ++j) {
			if ((i & j) < K) ++sol;
		}
	}
	
	printf("%d\n", sol);

}

int main(void) {

	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) solve(i);

}
