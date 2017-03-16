#include <algorithm>
#include <limits>
#include <cmath>
#include <cstdio>
#include <cstring>

#define MAX_N 100

int v[MAX_N];
int p[MAX_N + 1];
int q[MAX_N + 1];

using namespace std;

int solve_problem(int num_case)
{
	int a, n;

	if (scanf("%d %d", &a, &n) != 2)
		return 1;

	for (int i = 0; i < n; i++)
		if (scanf("%d", &v[i]) != 1)
			return 1;

	sort(v, v + n);

	p[0] = a;
	q[0] = 0;
	for (int i = 0; i < n; i++) {
		p[i + 1] = -1;
		q[i + 1] = numeric_limits<int>::max();
		for (int j = 0; j <= i; j++)
			if (q[j] != numeric_limits<int>::max()) {
				if (q[j] > v[i]) {
					int cand_p = p[j] + v[i];
					int cand_q = q[j] + (i - j);
					if (cand_q < q[i + 1] || (cand_q == q[i + 1] && cand_p > p[i + 1])) {
						p[i + 1] = cand_p;
						q[i + 1] = cand_q;
					}
				} else {
					int offset = 0;
					int x = p[j];
					if (x > 1) {
						while (x <= v[i]) {
							x += x - 1;
							offset++;
						}
						int cand_p = x + v[i];
						int cand_q = q[j] + offset + (i - j);
						if (cand_q < q[i + 1] || (cand_q == q[i + 1] && cand_p > p[i + 1])) {
							p[i + 1] = cand_p;
							q[i + 1] = cand_q;
						}
					}
				}
			}
	}

	int result = numeric_limits<int>::max();
	for (int i = 0; i <= n; i++)
		if (q[i] != numeric_limits<int>::max()) {
			int cand = q[i] + (n - i);
			if (cand < result)
				result = cand;
		}

	printf("Case #%d: %d\n", num_case, result);

	return 0;
}

int main(int argc, char *argv[])
{
	const char *filenames[] = {
		"osmos.in",
		"osmos.out",
	};
	int num_tests;

	for (int i = 1; i < argc && i <= 2; i++)
		filenames[i - 1] = argv[i];

	if (freopen(filenames[0], "rt", stdin) == NULL) {
		fprintf(stderr, "Could not reopen stdin\n");
		return 1;
	}
	if (freopen(filenames[1], "wt", stdout) == NULL) {
		fprintf(stderr, "Could not reopen stdout\n");
		return 1;
	}

	if (scanf("%d", &num_tests) != 1)
		return 1;
	for (int i = 0; i < num_tests; i++)
		solve_problem(i + 1);

	return 0;
}
