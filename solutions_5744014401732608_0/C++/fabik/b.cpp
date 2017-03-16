#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>

typedef long long ll;

using namespace std;

bool E[51][51];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int B;
		ll M;
		scanf("%d%lld", &B, &M);

		E[0][0] = false;

		for (int j = 1; j < B; j++) {
			ll ways = (B-j >= 2) ? (1LL << (B-j-2)) : 1;
			if (M >= ways) {
				E[0][j] = true;
				M -= ways;
			} else {
				E[0][j] = false;
			}
		}

		for (int i = 1; i < B; i++) {
			for (int j = 0; j < B; j++) {
				E[i][j] = (i < j);
			}
		}

		printf("Case #%d: ", t);
		if (M == 0) {
			printf("POSSIBLE\n");
			for (int i = 0; i < B; i++) {
				for (int j = 0; j < B; j++) {
					printf("%d", E[i][j] ? 1 : 0);
				}
				printf("\n");
			}
		} else {
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
