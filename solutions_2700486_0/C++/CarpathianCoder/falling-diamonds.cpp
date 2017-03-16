#include <algorithm>
#include <limits>
#include <cmath>
#include <cstdio>
#include <cstring>

#define TABLE_SIZE 230

int table[TABLE_SIZE];

double p[4 * TABLE_SIZE + 2][4 * TABLE_SIZE + 2];
double sp[4 * TABLE_SIZE + 2][4 * TABLE_SIZE + 2];

using namespace std;

void build_p()
{
	for (int i = 0; i <= 4 * TABLE_SIZE + 1; i++) {
		p[i][0] = (i > 0) ? p[i - 1][0] / 2 : 1.0;
		for (int j = 1 ; j <= i; j++) {
			p[i][j] = (p[i - 1][j] + p[i - 1][j - 1]) / 2;
		}
	}
	for (int i = 0; i <= 4 * TABLE_SIZE + 1; i++) {
		sp[i][0] = p[i][0];
		for (int j = 1 ; j <= i; j++)
			sp[i][j] = sp[i][j - 1] + p[i][j];
	}
#if 0
	for (int i = 0; i <= 10; i++) {
		for (int j = 0 ; j <= i; j++)
			printf(" %lf", sp[i][j]);
		printf("\n");
	}
#endif
}

int solve_problem(int num_case)
{
	int n, x, y;

	if (scanf("%d %d %d", &n, &x, &y) != 3)
		return 1;

	int pos = lower_bound(table, table + TABLE_SIZE, n) - table;
	int sum = (abs(x) + y) / 2;
	double result = 0.0;
	if (sum < pos) {
		result = 1.0;
	} else if (sum > pos) {
		result = 0.0;
	} else {
		if (table[pos] == n) {
			result = 1.0;
		} else {
			if (x == 0) {
				result = 0.0;
			} else {
				int rem = table[pos] - n;
				int num_elems = 4 * pos + 1 - rem;
				//printf("n_e=%d y'=%d\n", num_elems, y + 1);
				if (y + 1 <= num_elems) {
					int idx = num_elems - (y + 1);
					if (num_elems >= 2 * pos) {
						if (idx < 2 * pos)
							idx = 2 * pos;
						if (idx > num_elems - 2 * pos)
							idx = num_elems;
					}
					result = sp[num_elems][idx];
				} else {
					result = 0.0;
				}
			}
		}
	}
	printf("Case #%d: %.8lf\n", num_case, result);

	return 0;
}

int main(int argc, char *argv[])
{
	const char *filenames[] = {
		"falling-diamonds.in",
		"falling-diamonds.out",
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

	build_p();

	table[0] = 1;
	for (int i = 1; i < TABLE_SIZE; i++)
		table[i] = table[i - 1] + 2 * (2 * i) + 1;
#if 0
	for (int i = 0; i < TABLE_SIZE; i++)
		printf(" %d", table[i]);
	printf("\n");
#endif
	if (scanf("%d", &num_tests) != 1)
		return 1;
	for (int i = 0; i < num_tests; i++)
		solve_problem(i + 1);

	return 0;
}
