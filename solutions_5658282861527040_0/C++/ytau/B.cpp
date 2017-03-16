#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long T, A, B, K, ans;

int main() {
	scanf("%lld", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%lld%lld%lld", &A, &B, &K);
		ans = 0;
		for (int i = 0; i < A; ++i) {
			for (int j = 0; j < B; ++j) {
				if ((i&j) < K) ans++;
			}
		}
		printf("Case #%d: %lld\n", tc, ans);
	}
	return 0;
}