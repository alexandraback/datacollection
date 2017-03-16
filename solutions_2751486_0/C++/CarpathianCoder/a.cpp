#include <algorithm>
#include <limits>
#include <cmath>
#include <cstdio>
#include <cstring>

#define BUFFER_SIZE 1000000
#define MAX_N 1000000

bool v[MAX_N];
char str[BUFFER_SIZE + 10];

using namespace std;

int isvowel(int c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int solve_problem(int num_case)
{
	int n;

	if (scanf("%s %d", str, &n) != 2)
		return 1;

	int run_length = 0;
	size_t len = strlen(str);
	for (size_t i = 0; i < len; i++) {
		if (isvowel((unsigned char) str[i])) {
			run_length = 0;
		} else {
			++run_length;
		}
		v[i] = (run_length >= n);
	}

	long long result = 0;
	size_t j = 0;
	for (size_t i = 0; i < len; i++) {
		while (j < len && (j < i + n - 1 || !v[j]))
			++j;
		if (j == len)
			break;
		result += len - j;
	}
	printf("Case #%d: %lld\n", num_case, result);

	return 0;
}

int main(int argc, char *argv[])
{
	const char *filenames[] = {
		"a.in",
		"a.out",
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
