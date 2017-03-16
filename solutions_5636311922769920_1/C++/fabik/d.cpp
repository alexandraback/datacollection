#include <cstdio>

typedef long long ll;

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);

		ll seq[105];
		int ss = 0;

		ll pos = 0;
		int depth = 0;

		for (int i = 1; i <= K; i++) {
			pos = (pos == 0) ? i : K * (pos - 1) + i;
			depth++;

			if (depth == C) {
				seq[ss++] = pos;
				pos = 0;
				depth = 0;
			}
		}

		if (pos != 0) {
			seq[ss++] = pos;
		}

		printf("Case #%d:", tc);

		if (ss > S) {
			printf(" IMPOSSIBLE\n");
		} else {
			for (int i = 0; i < ss; i++) {
				printf(" %lld", seq[i]);
			}

			printf("\n");
		}
	}
	return 0;
}
