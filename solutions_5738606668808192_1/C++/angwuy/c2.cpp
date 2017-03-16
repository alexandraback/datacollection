#include <cstdio>
#include <cstring>

const int MAXN = 50;

int s[MAXN];
int a[MAXN], b[MAXN], la, lb;
int n = 32;
int j = 500;
int f[MAXN];
int limit = 1000;

void add()
{
	if (la < lb) la = lb;
	for (int i = 1; i <= la; ++i)
		a[i] += b[i];
	for (int i = 1; i < la; ++i)
	if (a[i] > 9)
	{
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	while (a[la] > 9)
	{
		a[la + 1] = a[la] / 10;
		a[la++] %= 10;
	}
}

void mul(int k)
{
	for (int i = 1; i <= lb; ++i)
		b[i] *= k;
	for (int i = 1; i < lb; ++i)
	if (b[i] > 9)
	{
		b[i + 1] += b[i] / 10;
		b[i] %= 10;
	}
	while (b[lb] > 9)
	{
		b[lb + 1] = b[lb] / 10;
		b[lb++] %= 10;
	}
}

bool divide(int k)
{
	int cur = 0;
	for (int i = la; i > 0; --i)
		cur = (cur * 10 + a[i]) % k;
	return cur == 0;
}

int isPrime()
{
	int l = limit;
	for (int i = 2; i <= limit; ++i)
		if (divide(i)) return i;
	return 1;
}

void solve()
{
	memset(s, 0, sizeof(s));
	s[n] = s[1] = 1;
	while (j > 0)
	{
		bool ok = true;
		for (int i = 2; i <= 10; ++i)
		{
			memset(a, 0, sizeof(a));
			memset(b, 0, sizeof(b));
			la = lb = b[1] = 1;
			for (int j = 1; j <= n; ++j)
			{
				if (s[j] == 1) add();
				mul(i);
			}
			f[i] = isPrime();
			if (f[i] == 1)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			for (int i = n; i > 0; --i)
				printf("%d", s[i]);
			for (int i = 2 ; i <= 10; ++i)
				printf(" %d", f[i]);
			printf("\n");
			--j;
		}
		s[2] += 1;
		int cur = 2;
		while (s[cur] > 1)
		{
			s[cur + 1] += 1;
			s[cur++] = 0;
		}
	}
}

int main()
{
	printf("Case #1:\n");
	solve();
	return 0;
}