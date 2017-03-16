#include <algorithm>
#include <limits>
#include <cmath>
#include <cstdio>
#include <cstring>

#define BUFFER_SIZE 1000000

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
char dir[] = { 'E', 'W', 'N', 'S' };
char str[BUFFER_SIZE + 10];

using namespace std;

int solve_problem(int num_case)
{
	int x, y;

	if (scanf("%d %d", &x, &y) != 2)
		return 1;

	int sum = abs(x) + abs(y);

	int n = 1;
	while (n * (n + 1) / 2 < sum)
		++n;

	if (sum & 1) {
		while (n % 4 != 1 && n % 4 != 2)
			++n;
	} else {
		while (n % 4 != 0 && n % 4 != 3)
			++n;
	}

	str[n] = 0;
	for (; n > 0; n--) {
		int j;
		for (j = 0; j < 4; j++) {
			int nx = x + dx[j] * n;
			int ny = y + dy[j] * n;
			if (abs(nx) + abs(ny) <= n * (n - 1) / 2) {
				str[n - 1] = dir[j];
				x = nx;
				y = ny;
				break;
			}
		}
		if (j == 4)
			fprintf(stderr, "ERROR: j not found!!!\n");
	}

	printf("Case #%d: %s\n", num_case, str);

	return 0;
}

int main(int argc, char *argv[])
{
	const char *filenames[] = {
		"b.in",
		"b.out",
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
