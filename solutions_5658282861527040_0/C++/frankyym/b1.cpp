#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int T;
	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		int A, B, K;
		scanf("%d%d%d", &A, &B, &K);

		ll ret = 0;
		for (int a=0; a<A; ++a) for (int b=0; b<B; ++b)
			if ((a&b) < K) ++ret;

		printf("Case #%d: %lld\n", t+1, ret);
	}
	return 0;
}
