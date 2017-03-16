#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <gmpxx.h>
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef std::pair<int, int> pii;
#define DEBUG 1

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
#endif
}


char s[100000];

mpz_class c[200][200];
mpz_class _pow10[200];


bool good(mpz_class n)
{
	gmp_sprintf(s, "%Zd", n.get_mpz_t());
	int l = (int) strlen(s);
	for(int i = 0; i < l; i++)
	{
		if (s[i] != s[l - i - 1])
			return false;
	}
	return true;
}

mpz_class sqr(mpz_class n)
{
	return n * n;
}


mpz_class solve(mpz_class sum, int l, int r, int remain, mpz_class n)
{
	if(sum * sum > n)
		return 0;
	if (remain < 0)
		return 0;
	l --; r++;
	if (l < r)
		return 1;
	mpz_class ans = 0;
	if (l == r)
	{
		ans++;
		if (remain >= 1 && sqr(sum + _pow10[l]) <= n)
			ans++;
		if (remain >= 4 && sqr(sum + 2*_pow10[l]) <= n)
			ans++;
		return ans;
	}
	if (sqr(sum + 2*_pow10[l] + 2*_pow10[r]) <= n)
	{
		int free = (l - r + 1) / 2;
		for(int k = 0; k <= remain/2; k++)
			ans += c[free][k];
		if ((l - r) % 2 == 0)
		{
			for(int k = 0; k <= remain/2; k++)
				ans += c[free][k];
			if (remain >= 4)
				for(int k = 0; k <= (remain-4)/2; k++)
					ans += c[free][k];
		}
	}
	else
	{
		ans = solve(sum, l, r, remain, n) + solve(sum + _pow10[l] + _pow10[r], l, r, remain - 2, n);
	}
	return ans;
}

mpz_class solve(mpz_class n)
{
	mpz_class ans = 0;
	if (n < 1000000)
	{
		for(mpz_class i = 1; i * i <= n; i++)
		{
			if (good(i) && good(i*i))
				ans++;
		}
		return ans;
	}
	ans = 10;
	for(int len = 3; _pow10[2*len] <= n; len++)
	{
		if (sqr(2*_pow10[len] + 2) <= n)
			ans++;
		if (len % 2 == 0 && sqr(2*_pow10[len] + _pow10[len/2] + 2) <= n)
			ans++;
		ans += solve(_pow10[len] + 1, len, 0, 7, n);
	}
	return ans;
}


void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	mpz_class l, r;
	gmp_scanf("%Zd%Zd", l.get_mpz_t(), r.get_mpz_t());
	mpz_class ans = solve(r) - solve(l-1);
	gmp_printf("%Zd\n", ans.get_mpz_t());
}

int main()
{
	for(int i = 0; i < 200; i++)
	{
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		_pow10[i] = (i == 0) ? mpz_class(1) : 10 * _pow10[i-1];
	}
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
