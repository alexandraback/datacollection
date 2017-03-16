/*
 * $File: c.cc
 * $Date: Sat Apr 13 14:42:22 2013 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll pal[20000000];
ll pal_sqr_pal[20000000];
int n_pal_sqr_pal;
ll ten[20];
int npal; 
ll ll_sqrt(ll num)
{
	return (ll)floor(sqrt((long double)num));
}

bool is_sqr(ll num)
{
	ll t = (ll)floor(sqrt((long double)num));
	return t * t == num;
}

bool is_pal(ll num);
bool is_pal_sqr(ll num)
{
	ll t = (ll)floor(sqrt((long double)num));
	return t * t == num && is_pal(t);
}


void decomp(ll num, int *bit, int &len)
{
	if (num == 0)
		throw "num can not be zero";
	len = 0;
	while (num)
	{
		bit[len ++] = num % 10;
		num /= 10;
	}
}

bool is_pal(ll num)
{
	int bit[20], len;
	decomp(num, bit, len);
	if (len == 1)
		return true;
	for (int i = 0; i < len >> 1; i ++)
		if (bit[i] != bit[len - i - 1])
			return false;
	return true;
}

ll concat(ll base, int *bit, int len)
{
	for (int i = 0; i < len; i ++)
		base = base * 10 + bit[i];
	return base;
}

int sqrt_max = 10000000;
void init()
{
	fprintf(stderr, "generating palindromes ...\n");
	npal = 0;
	ten[0] = 1;
	for (int i = 1; i <= 18; i ++) ten[i] = ten[i - 1] * 10;
	int bit[18];
	//for (int i = 1; i <= 9; i ++) pal[npal ++] = i;
	for (ll i = 1; i <= sqrt_max; i ++)
	{
		if (is_pal(i))
			pal[npal ++] = i;
		continue;
		int len;
		decomp(i, bit, len);
		pal[npal ++] = concat(i, bit, len);
		if (len > 1)
			pal[npal ++] = concat(i, bit + 1, len - 1);
	}
	pal[npal ++] = 1e16;
	fprintf(stderr, "sorting palindromes ...\n");
	sort(pal, pal + npal);

	fprintf(stderr, "generating pal_sqr_pal ...\n");
	n_pal_sqr_pal = 0;
	for (int i = 0; i < npal - 1; i ++)
		if (pal[i] <= sqrt_max)
		{
			ll t = pal[i] * pal[i];
			if (is_pal(t))
				pal_sqr_pal[n_pal_sqr_pal ++] = pal[i];
		}

	fprintf(stderr, "initializing finished\n");
}

int find_ge(ll num)
{
	int l = 0, r = n_pal_sqr_pal - 1;
	while (l != r)
	{
		int m = (l + r) >> 1;
		if (pal_sqr_pal[m] >= num)
			r = m;
		else l = m + 1;
	}
	return l;
}

int find_nle(ll num)
{
	if (num < pal_sqr_pal[0])
		return 0;
	int l = 0, r = n_pal_sqr_pal;
	while (l + 1 != r)
	{
		int m = (l + r) >> 1;
		if (pal_sqr_pal[m] > num)
			r = m;
		else l = m;
	}
	return l + 1;
}

ll force(ll a, ll b)
{
	ll ret = 0;
	for (ll i = a; i <= b; i ++)
		ret += is_pal(i) && is_pal_sqr(i);
	return ret;
}

void solve()
{
	ll A, B;
	scanf("%lld%lld", &A, &B);
	ll A_t = (int)ceil(sqrt((long double)A)), B_t = (int)floor(sqrt((long double)B));
	int ans = find_nle(B_t) - find_nle(A_t - 1);
	printf("%d\n", ans);
	//printf("%d %lld\n", ans, force(A, B));
}

int main()
{
	init();
	int ncase;
	scanf("%d", &ncase);
	for (int i = 1; i <= ncase; i ++)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}


/**
 * vim: syntax=cpp11 foldmethod=marker
 */

