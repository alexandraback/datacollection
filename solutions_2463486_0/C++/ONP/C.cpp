#include <cstdio>
#include <cstring>
#include <cstdlib>

const long long limit	=	100000000000000LL;

long long fs[1000];
int len;

inline bool ok(long long x)
{
	int a[100],n=0;
	while (x > 0)
	{
		a[n ++] = x % 10;
		x = x / 10;
	}
	for (int i = 0;i < n;++ i)
	{
		if (a[i] != a[n - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	for (long long i = 1; i * i <= limit;++ i)
	{
		if (ok(i) && ok(i * i))
		{
			fs[len ++] = i * i;
		}
	}
	int T, caseNum = 1;
	for (scanf("%d", &T);T --;)
	{
		long long A,B;
		scanf("%I64d%I64d", &A, &B);
		int cnt=0;
		for (int i = 0;i < len;++ i)
		{
			if (A <= fs[i] && fs[i] <= B)
			{
				++cnt;
			}
		}
		printf("Case #%d: %d\n",caseNum ++,cnt);
	}
	return 0;
}
