#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T;
long long r, t;

bool pass(long long n)
{
	long long x = 2 * n;
	long long y = 2 * n * n - n;
	return r <= (t - y) / x;
}

int find(int p, int q)
{
	if (p == q) return p;
	int mid = (p + q + 1) / 2;
	if (pass(mid))
		return find(mid, q);
	return find(p, mid - 1);
}

int main()
{
	int ca = 0;
	scanf("%d", &T);
	while (T--)
	{
		ca++;
		scanf("%lld%lld", &r, &t);
		printf("Case #%d: %d\n", ca, find(1, 2000000000));
	}
	return 0;
}
