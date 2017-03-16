#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

int solve()
{
	char sa[10], sb[10];
	scanf("%s %s", sa, sb);
	int a = atoi(sa);
	int b = atoi(sb);
	int l = strlen(sa);
	assert(l == strlen(sb));
	int scale = (int) pow(10.0, l - 1);

	int count = 0;
	bool* occur = (bool*) calloc(b - a + 1, sizeof(bool));
	for (int i = a; i <= b; i++) {
		if (occur[i-a]) continue;
		int localCount = 0;
		for (int n = i, j = 0; j < l; j++, n = (n / 10) + ((n % 10) * scale)) {
			if (n < a || n > b || occur[n-a]) continue;
			localCount++;
			occur[n-a] = true;
		}
		if (localCount > 1) {
			count += localCount * (localCount - 1) / 2;
		}
	}
	free(occur);
	return count;
}

int main(int argc, char** argv)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("Case #%d: %d", i, solve());
	}
}
