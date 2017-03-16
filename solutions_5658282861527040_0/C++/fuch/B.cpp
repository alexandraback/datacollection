#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

long long brute(long long A, long long B, long long K)
{
	long long ans = 0;
	for (long long a = 0; a < A; ++a)
	{
		for (long long b = 0; b < B; ++b)
		{
			if ((a & b) < K) ++ans;
		}
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cs = 1; cs <= t; ++cs)
	{
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		printf("Case #%d: %I64d\n", cs, brute(a, b, k));
	}
}
