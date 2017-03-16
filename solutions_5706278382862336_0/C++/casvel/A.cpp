#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define For(i, a, b) for(int i=a; i<b; ++i)
#define MP make_pair
#define INF (100)

using namespace std;

typedef pair <int, int> ii;

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int f(long long p, long long q)
{
	int res = 0;
	while (q > p)
	{
		res++;
		q >>= 1;
	}

	return res;
}

int main()
{
	int T;
	scanf("%d", &T);

	int caso = 1;
	while (T--)
	{
		long long p, q;
		scanf("%lld/%lld", &p, &q);

		long long g = gcd(p, q);

		p = p/g;
		q = q/g;

		int l = 0;
		while (((long long)(1)<<l) < q)
			l++;

		printf("Case #%d: ", caso++);
		
		if (((long long)(1)<<l) == q and l <= 40)
			printf("%d\n", f(p, q));
		else
			printf("impossible\n");

	}
	return 0;
}