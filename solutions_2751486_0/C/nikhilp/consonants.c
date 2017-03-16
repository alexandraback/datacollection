#include <stdio.h>
#include <string.h>

int is_n_conso (char *name, unsigned long i, unsigned long j, unsigned long n) {
	char *start = name + i;
	unsigned long cons = 0;

	if ((j - i + 1) < n)
		return 0;

	while (start <= name + j) {
		if (*start != 'a' && *start != 'e' && *start != 'i' && *start != 'o' && *start != 'u') {
			cons++;
			if (cons == n)
				return 1;
		}
		else
			cons = 0;
		start++;
	}
	return 0;
}

int main () {
	int T, test_case = 0;
	unsigned long n, result, i, j, len;
	char name[1000010];

	scanf("%d",&T);

	while (test_case++ < T) {
		//scan and proces one test-case
		fflush(stdin);
		scanf("%s", name);
		scanf("%lu", &n);

		result = 0;
		len = strlen (name);

		for (i = 0; i < len; i++) {
			for (j = i; j < len; j++) {
				if (is_n_conso (name, i, j, n))
					result++;
			}
		}

		printf("Case #%d: %lu\n", test_case, result);
	}
	return 0;
}

