#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int CONN[64][64];

void solve()
{
	static int casenr = 1;
	printf("Case #%d: ", casenr++);

	int B;
	long long M;
	scanf("%lld%lld", &B, &M);
	memset(CONN, 0, sizeof(CONN));

	for (int i = 0; i < B; ++i) {
		for (int j = i + 1; j < B - 1; ++j) {
			CONN[i][j] = 1;
		}
	}
	
	CONN[0][B-1] = 1;

	long long x = M - 1LL;
	for (int i = 1; i < B-1; ++i) {
		long long v = (1LL << ((long long)i - 1LL));
		if (x & v) {
			CONN[i][B-1] = 1;
			x -= v;
		}
	}

	if (x != 0LL) {
		puts("IMPOSSIBLE");
		return;
	}

	puts("POSSIBLE");
	for (int i = 0; i < B; ++i) {
		for (int j = 0; j < B; ++j) {
			printf("%d", CONN[i][j]);
		}
		puts("");
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T-- > 0) {
		solve();
	}
	return 0;
}
