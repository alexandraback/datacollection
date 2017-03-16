#include <cstdio>

int msk;

long long get(int base)
{
	long long x = 0;
	for (int i = 29; i >= 0; --i)
	{
		x *= base;
		if (msk >> i & 1)
			x++;
	}
	return x;
}

void find()
{
	long long p[11];
	int cnt = 0;
	for (msk = 11; cnt < 500; msk += 11)
	{
		for (int i = 2; i <= 10; ++i)
			p[i] = get(i);
		if (p[2] % 11 || p[3] % 2 || p[4] % 3 || p[5] % 2 || p[6] % 7
			|| p[7] % 2 || p[8] % 5 || p[9] % 2 || p[10] % 3)
			continue;
		cnt++;
		printf("1");
		for (int i = 29; i >= 0; --i)
			putchar('0' + (msk >> i & 1));
		puts("1 11 2 3 2 7 2 5 2 3");
	}
}

int main()
{
	freopen("cl.out", "w", stdout);
	printf("Case #1:\n");
	find();
	return 0;
}
