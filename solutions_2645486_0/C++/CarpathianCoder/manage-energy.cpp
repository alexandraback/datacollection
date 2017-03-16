#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

#define MAX_N 10000

using namespace std;

int v[MAX_N];

int solve_problem(int num_case)
{
	int e, r, n;

	if (scanf("%d %d %d", &e, &r, &n) != 3)
		return 1;

	for (int i = 0; i < n; i++)
		if (scanf("%d", &v[i]) != 1)
				return 1;

	if (r > e)
		r = e;

	int max_value = v[0];
	long long sum = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] > max_value)
			max_value = v[i];
		sum += v[i];
	}

	printf("Case #%d: %lld\n", num_case, sum * r + max_value * (e - r));
	return 0;
}

int main()
{
	int num_tests;
#if 0
	if (freopen("manage-energy.in", "rt", stdin) == NULL) {
		fprintf(stderr, "Could not reopen stdin\n");
		return 1;
	}
	if (freopen("manage-energy.out", "wt", stdout) == NULL) {
		fprintf(stderr, "Could not reopen stdin\n");
		return 1;
	}
#endif
	if (scanf("%d", &num_tests) != 1)
		return 1;
	for (int i = 0; i < num_tests; i++)
		solve_problem(i + 1);

	return 0;
}
