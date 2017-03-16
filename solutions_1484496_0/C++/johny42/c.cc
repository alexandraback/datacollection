#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int x[20];

void dump(int subset) {
	bool first = true;
	for (int i = 0; i < 20; ++i) {
		if ((subset>>i)&1) {
			if (!first) printf(" ");
			first = false;
			printf("%d", x[i]);
		}
	}
	printf("\n");
}

int sum(int subset) {
	int res = 0;
	for (int i = 0; i < 20; ++i) {
		if ((subset>>i)&1) res += x[i];
	}
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		printf("Case #%d:\n", tt);

		scanf("%d", &x[0]);
		for (int i = 0; i < 20; ++i) scanf("%d", &x[i]);

		bool sums[2000042];
		memset(sums, 0, sizeof(sums));

		for (int subset = 1; subset < (1<<20); ++subset) {
			int cursum = sum(subset);
			//printf("%d\n", cursum);
			if (sums[cursum]) {
				dump(subset);
				for (int other = 1; other < subset; ++other) {
					if (sum(other) == cursum) {
						dump(other);
						goto end;
					}
				}
			}
			sums[cursum] = true;
		}

		printf("Impossible\n");
		end: ;
	}
}
