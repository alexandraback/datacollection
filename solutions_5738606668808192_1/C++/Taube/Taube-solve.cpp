#pragma comment (linker, "/STACK:256000000")
 
#define _USE_MATH_DEFINES
#define _CRT_NO_DEPRECEATE
#define _CRT_SECURE_NO_WARNINGS
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
//#include <random>
 
using namespace std;
 
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<pii, pii> piiii;
typedef pair<int64, int> pli;
 
#define pb push_back
#define sq(x) ((x)*(x))
#define tmin(x,y,z) (min(min((x),(y)),(z)))
#define tmax(x,y,z) (max(max((x),(y)),(z)))
#define rand32() (((unsigned int)(rand()) << 16) | (unsigned int)(rand()))
#define rand64() (((unsigned int64)(rand32()) << 16) | (unsigned int64)(rand32()))
#define bit(mask, b) ((mask >> b) & 1)
#define biton(mask, bit) (mask | (((uint64)(1)) << bit))
#define bitoff(mask, bit) (mask & (~(((uint64)(1)) << bit)))
#define bitputon(mask, bit) (mask |= (((uint64)(1)) << bit))
#define bitputoff(mask, bit) (mask &= (~(((uint64)(1)) << bit)))
#define FAIL() (*((int*)(0)))++
#define INF ((int)(1e9) + 1337)
#define EPS (1e-11)
#define y1 yy1
#define y0 yy0
#define j0 jj0

//#define HMOD (1000000000000000003LL)
//#ifdef _MY_DEBUG
//#define HMOD 1000000007
//#endif
//#define HBASE 524287

//mt19937 ggen;

const long double PI = acosl((long double)-1.0);

int test;

const int MAXN = 10500;

vector <int64> primes;
int lp[MAXN];

void precalc_primes()
{
	for (int i = 2; i < MAXN; i++)
	{
		if (!lp[i])
		{
			primes.push_back(i);
		}
		for (int j = 0; j < primes.size(); j++)
		{
			int q = primes[j] * i;
			if (q >= MAXN)
			{
				break;
			}
			lp[q] = primes[j];
		}
	}
}

struct jamcoin
{
	string s;
	vector <int64> d;

	jamcoin(string s, vector <int64> &d) : s(s), d(d)
	{

	}
};

int n, k;
char jam[35];
vector <jamcoin> v;

int64 get_div(int64 q)
{
	for (int64 i = 2LL; i * i <= q; i++)
	{
		if (!(q % i))
		{
			return i;
		}
	}
	return 0;
}

int64 get_number(string s, int64 base, int64 mod)
{
	int64 res = 0LL;
	int64 pw = 1LL;
	for (int i = (int)s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '1')
		{
			res += pw;
		}
		pw *= base;
		pw %= mod;
	}
	return res % mod;
}

bool check()
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].s.size() != n || v[i].s[0] != '1' || v[i].s[n - 1] != '1')
		{
			return false;
		}
		for (int j = 2; j <= 9; j++)
		{
			if (v[i].d[j - 2] < 2LL)
			{
				return false;
			}
			if (get_number(v[i].s, j, v[i].d[j - 2]))
			{
				return false;
			}
		}
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i].s == v[j].s)
			{
				return false;
			}
		}
	}
	return true;
}

void print()
{
	assert(check());
	printf("Case #1:\n");
	for (int i = 0; i < v.size(); i++)
	{
		printf ("%s ", v[i].s.c_str());
		for (int j = 0; j < v[i].d.size(); j++)
		{
			printf ("%lld ", v[i].d[j]);
		}
		printf("\n");
	}
}

int rec(int pos)
{
	if (pos >= n)
	{
		vector <int64> divs;
		for (int i = 2; i <= 10; i++)
		{
			int64 divv = 0;
			for (int64 j = 0; j < primes.size(); j++)
			{
				if (!get_number(string(jam + 1), i, primes[j]))
				{
					divv = primes[j];
					break;
				}
			}
			if (!divv)
			{
				break;
			}
			else
			{
				divs.push_back(divv);
			}
		}
		if (divs.size() == 9)
		{
			v.push_back(jamcoin(string(jam + 1), divs));
			fprintf(stderr, "%d\n", v.size());
			if (v.size() == k)
			{
				print();
				exit(0);
			}
		}
	}
	else
	{
		jam[pos] = '0';
		rec(pos + 1);
		jam[pos] = '1';
		rec(pos + 1);
	}
}

void solve()
{
	scanf ("%d%d", &n, &k);
	jam[1] = jam[n] = '1';
	rec(2);
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef _MY_DEBUG
    freopen("C-large.in", "rt", stdin); freopen("output.txt", "wt", stdout);
#else
    //freopen(TASK ".in", "rt", stdin); freopen(TASK ".out", "wt", stdout);
#endif
    srand(1313);
    
	precalc_primes();
	int tests = 1;
	scanf ("%d", &tests);
	for (test = 1; test <= tests; test++)
	{
		solve();
	}

    return 0;
}