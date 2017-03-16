#include <cstdio>
#include <cstring>
using namespace std;
int T;
int K, C, S;
int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		scanf("%d%d%d", &K, &C, &S);
		if (C * S < K)
			printf("IMPOSSIBLE\n");
		else {
			int now = 1, rest = K;
			while (rest) {
				long long ans = 0;
				for (int j = 1; j <= C; j++) {
					if (rest == 0) break;
					rest--;
					ans = ans * K + ((now++) % K);
				}
				printf(" %lld", ans + 1);
			}
			printf("\n");
		}
	}
	return 0;
}