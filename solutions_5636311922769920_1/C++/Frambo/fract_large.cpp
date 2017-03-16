#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
	static int casenr = 1;
	printf("Case #%d:", casenr++);
	
	int K, C, S; scanf("%d%d%d", &K, &C, &S);
	
	if (K > S * C) {
		puts(" IMPOSSIBLE");
		return;
	}
	
	int x = 0;
	while (x < K) {
		long long p = 0LL;
		int c = C;
		while (c--) {
			p *= (long long) K;
			p += (long long) (x++ % K);
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
