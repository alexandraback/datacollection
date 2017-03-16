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

int E,R,N;
int v[10000];
int total_gain;

int solve(int first, int last, int e)
{
	if (first >= last) return 0;

	int vi = v[first];
	if (first + 1 == last) {
		return vi * e;
	}

	int max_total = 0;
	for (int u = 0; u <= e; ++u) {
		int total = vi * u;
		total += solve(first + 1, last, min(e - u + R, E));
		if (max_total < total) {
			max_total = total;
		}
	}
	return max_total;
}

int main() {
	int T; scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti) {
		fprintf(stderr, "Case #%d of %d...\n", Ti, T);

		scanf("%d %d %d", &E, &R, &N);

		for (int i = 0; i < N; ++i) {
			scanf("%d", &v[i]);
		}

		printf("Case #%d: %d\n", Ti, solve(0, N, E));
	}
	return 0;
}
