#include <stdio.h>
#include <map>

using namespace std;

inline bool isp(long long n) {
	int array[20];
	int amany = 0;
	while (n > 0) {
		array[amany++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < amany; i++)
		if (array[i] != array[amany-1-i])
			return false;
	return true;
}

long long ans[1000];
int aamany;

int main() {
	for (long long i = 0; i < 10000000; i++)
		if (isp(i) && isp(i*i))
			ans[aamany++] = i*i;

	int ecase, ecount;

	scanf("%d", &ecase);
	for (ecount = 1; ecount <= ecase; ecount++) {
		long long ea, eb;
		scanf("%I64d%I64d", &ea, &eb);
		int a = 0;
		for (int i = 0; i < aamany; i++)
			if (ea <= ans[i] && ans[i] <= eb)
				a++;
		printf("Case #%d: %d\n", ecount, a);
	}

	return 0;
}
