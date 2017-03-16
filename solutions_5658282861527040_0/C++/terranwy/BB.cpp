#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int cases;
long long A, B, K;

int main() {

	scanf("%d", &cases);
	
	for (int casei = 1; casei <= cases; ++casei) {
		scanf("%lld%lld%lld", &A, &B, &K);
		long long ans = 0;
		for (long long i = 0; i < A; ++i)
			for (long long j = 0; j < B; ++j)
				if ((i & j) < K) ++ans;
		
		printf("Case #%d: %lld\n", casei, ans);
	}
	
	return 0;
}