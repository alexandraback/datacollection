#include <cstdio>
#include <string>

using namespace std;

int main() {
	int T, K, C, S;
	char buf[512];

	memset(buf, 0x00, sizeof(buf));
	fgets(buf, 512, stdin);
	sscanf(buf, "%d", &T);

	int i, j;

	for (i = 0; i < T; ++i) {
		memset(buf, 0x00, sizeof(buf));
		fgets(buf, 512, stdin);

		sscanf(buf, "%d %d %d", &K, &C, &S);

		if (C * S < K) {
			printf("Case #%d: IMPOSSIBLE\n", i + 1);
			continue;
		}

		long long see_index = 0;
		int see_height = 0;

		printf("Case #%d:", i + 1);

		for (j = 0; j < K; ++j) {
			if (see_height == 0)
				see_index = j;
			else
				see_index = see_index * K + j;

			++see_height;

			//printf(" (j is %d - %d %d)", j, see_index + 1, see_height);

			if (j == K - 1) {
				while (see_height < C) {
					see_index *= K;
					++see_height;
				}
			}

			if (see_height >= C) {
				see_height = 0;
				printf(" %lld", see_index + 1);
			}
		}
		printf("\n");
	}

	return 0;
}