#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long i64;

i64 P, Q;

int main(int argc, char **argv) {
	FILE *fd = argc > 1 ? fopen(argv[1], "r") : stdin;
	int T; fscanf(fd, "%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti) {
		fprintf(stderr, "Case #%d of %d...\n", Ti, T);

		fscanf(fd, "%lld/%lld", &P, &Q);

		int res = INT_MAX;
		int n=0;
		while (P != 0 && n <= 40) {
			if (P >= Q) {
				P -= Q;
				res = min(res, n);
			}
			if (Q % 2 == 1) {
				P *= 2;
				Q *= 2;
			}
			Q /= 2;
			n++;
		}

		if (P != 0) {
			printf("Case #%d: impossible\n", Ti);
		} else {
			printf("Case #%d: %d\n", Ti, res);
		}
	}
	if (fd != stdin) {
		fclose(fd);
	}
	return 0;
}
