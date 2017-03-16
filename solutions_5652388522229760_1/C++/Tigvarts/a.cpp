#include <iostream>
#include <cstdio>
using namespace std;

long long
find_min(long long n)
{
	if (n == 0) {
		return 0;
	}
	int was[10];
	for (int i = 0; i < 10; ++i) {
		was[i] = 0;
	}
	for (long long i = 1; i < 1000000; ++i) {
		long long cur = i * n;
		while (cur) {
			was[cur % 10] = 1;
			cur /= 10;
		}
		int sum = 0;
		for (int j = 0; j < 10; ++j) {
			sum += was[j];
		}
		if (sum == 10) {
			return i;
		}
	}
	return 0;
}

void
solve()
{
	long long n;
	scanf("%lld", &n);
	long long res = find_min(n);
	if (res == 0) {
		printf("INSOMNIA\n");
	} else {
		printf("%lld\n", res * n);
	}
}

int
main()
{
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
}
