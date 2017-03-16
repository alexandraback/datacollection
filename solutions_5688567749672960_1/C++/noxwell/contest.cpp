#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#define _CRT_NO_DEPRECEATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <memory.h>
#include <sstream>
#include <cassert>
#include <ctime>
#include <complex>

#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define sq(x) ((x)*(x))
#define tmin(x,y,z) (min(min((x),(y)),(z)))
#define _MOD 1000000009LL
#define MOD(x) (((x) + 2LL * (_MOD)) % (_MOD))
#define INF ((int)(1e9))
#define LINF ((long long)(1e16))
#define EPS (1e-8)
#define PI (3.1415926535897932384626433832795)
#define y1 asdf_1
#define y0 asdf_2
#define j0 jj0
typedef unsigned long long ull;
typedef long double ldd;

using namespace std;

long long n;

long long flip(long long k)
{
	long long res = 0;
	while (k)
	{
		res *= 10LL;
		res += k % 10LL;
		k /= 10LL;
	}
	return res;
}

/*long long f[1000001];
long long dyn(long long k)
{
	if (k == 1)
		return 1;
	if (f[k] != -1)
		return f[k];
	f[k] = dyn(k - 1) + 1;
	if (flip(k) < k && flip(flip(k)) == k)
		f[k] = min(f[k], dyn(flip(k)) + 1);
	return f[k];
}
long long dynsolve(long long k)
{
	memset(f, -1, sizeof f);
	return dyn(k);
}*/

int llen(long long k)
{
	int res = 0;
	while (k)
	{
		res++;
		k /= 10LL;
	}
	return res;
}

long long pref(long long k, int l)
{
	long long res = 0;
	long long p = 1;
	for (int i = 0; i < l; i++)
	{
		res += (k % 10LL) * p;
		p *= 10LL;
		k /= 10LL;
	}
	return res;
}

long long niner(int l)
{
	long long res = 0;
	for (int i = 0; i < l; i++)
	{
		res *= 10LL;
		res += 9LL;
	}
	return res;
}

long long solve(long long k)
{
	n = k;
	bool zer = (n % 10 == 0);
	if (zer)
		n--;
	long long cur = 1;
	long long res = 1 + zer;
	int len = llen(n);
	for (int i = 1; i < len; i++)
	{
		if (i == 1)
		{
			cur += 9;
			res += 9;
			continue;
		}
		int half = i / 2;
		cur += niner(half);
		res += niner(half);
		cur = flip(cur);
		res++;
		half = i - half;
		cur += niner(half);
		res += niner(half);
	}
	if (cur == n)
		return res;
	
	int half = len / 2;
	long long fn = flip(n);
	if (pref(flip(cur), half) != pref(fn, half))
	{
		cur += pref(fn, half);
		res += pref(fn, half);
		if (cur == n)
			return res;
		cur = flip(cur);
		res++;
	}
	half = len - half;
	res += pref(n, half) - pref(cur, half);
	cur += pref(n, half) - pref(cur, half);
	return res;
}

/*void stress(long long k)
{
	if (solve(k) != dynsolve(k))
	{
		cout << "WA " << k << " " << solve(k) << " " << dynsolve(k) << endl;
	}
}*/

int main()
{
	//freopen("input.txt", "w", stdout); testgen(5, 60, 120); return 0;
	//freopen("output.txt", "w", stdout);	for (int i = 1; i < 10000; i++) stress(i);	return 0;

	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int ts;
	cin >> ts;
	for (int tt = 0; tt < ts; tt++)
	{
		cin >> n;
		cout << "Case #" << tt + 1 << ": " << solve(n) << endl;
	}

	return 0;
}