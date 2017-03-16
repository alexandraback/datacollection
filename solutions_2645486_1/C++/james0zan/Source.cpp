#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <io.h>
#include <stdint.h>
#include <queue>
using namespace std;

typedef int32_t I32;
typedef int64_t I64;
typedef uint64_t UI64;
#define mp make_pair

I64 v[20000], r[20000];
pair<I64, int> S[20000];

int main() {
	int T, TC = 1;;
	I64 R, n, E;
	
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld", &E, &R, &n);
		for (int i=0; i<n; i++) scanf("%lld", &v[i]);
		int ST = 0;
		S[ST++] = mp(20000000, n);
		for (int i=n-1; i>=0; i--) {
			while (S[ST - 1].first < v[i]) ST --;
			r[i] = S[ST - 1].second;
			S[ST++] = mp(v[i], i);
		}
		I64 cur = E, ans = 0;
		for (int i=0; i<n; i++) {
			if (r[i] == n) {
				ans += v[i] * cur;
				cur = 0;
			} else {
				I64 tt = max(cur + (r[i] - i) * R - E, 0ll);
				I64 t = min(tt, cur);
				ans += t * v[i];
				cur -= t;
			}
			//printf("%lld %lld\n", ans, cur);
			cur += R;
			cur = min(cur, E);
		}
		printf("Case #%d: %lld\n", TC++, ans);
	}
}