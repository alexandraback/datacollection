#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

vector<long long> a;

bool check(long long x)
{
	int c[100];
	int cnt = 0;
	while (x)
	{
		c[cnt++] = x % 10;
		x /= 10;
	}
	for (int i = 0, j = cnt - 1; i < j; ++i, --j)
		if (c[i] != c[j])
			return false;
	return true;
}

void pre_cal()
{
	for (int i = 0; i < 10000000; ++i)
	{
		if (!check(i))
			continue;
		long long x = i;
		x *= i;
		if (check(x))
		{
			a.push_back(x);
		}
	}
}

int main()
{
	pre_cal();
	/*
	printf("%d\n", a.size());
	return 0;
	*/
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		long long A, B;
		scanf("%I64d%I64d", &A, &B);
		int i, j;
		for (i = 0; i < a.size() && a[i] < A; ++i)
		{
		}
		for (j = i; j < a.size() && a[j] <= B; ++j)
		{
		}
		printf("Case #%d: %d\n", tt, j - i);
	}
	return 0;
}
