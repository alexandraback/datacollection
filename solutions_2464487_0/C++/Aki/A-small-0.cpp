#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long i64;


int main() {
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
	fprintf(stderr, "Case #%d of %d...\n", Ti, T);

	i64 r, t;
	scanf("%lld %lld", &r, &t);

	i64 n = 0;
	for (i64 u = 1; ; u += 4) {
		t -= 2 * r + u;
		if (t < 0) break;
		++n;
	}

	printf("Case #%d: %lld\n", Ti, n);
  }
  return 0;
}
