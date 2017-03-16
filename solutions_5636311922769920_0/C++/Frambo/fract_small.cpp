#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
	static int casenr = 1;
	printf("Case #%d: ", casenr++);
	
	int K, C, S; scanf("%d%d%d", &K, &C, &S);

	for (int i = 0; i < K; ++i) {
		long long p = 0;
		for (int j = 0; j < C; ++j) {
			p *= (long long) K;
			p += (long long) i;
		}
		printf(" %lld", p + 1);
	}
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	while (T-- > 0) {
		solve();
	}
	return 0;
}
