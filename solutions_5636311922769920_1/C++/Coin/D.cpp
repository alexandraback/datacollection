#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, kase = 0;
	scanf("%d", &T);
	while (++kase <= T) {
		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);
		int n = K - C + 1;
		if (n < 1) n = 1;
		if (n > S)
			printf("Case #%d: IMPOSSIBLE\n", kase);
		else {
			printf("Case #%d:", kase);
			long long start = 1;
			for (int i = 2; i <= C; i++) {
				int offset = min(i, K);
				start = start * K - K + offset;
			}
			for (int i = 0; i < n; i++) {
				printf(" %lld", start + i);
			}
			printf("\n");
	
		}
	}

	return 0;
}