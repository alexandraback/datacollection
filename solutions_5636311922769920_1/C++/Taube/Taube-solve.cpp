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

string s;

string power(string s, int k, int c)
{
	string add(k, 'G');
	string a[2];
	a[0] = s;
	int cur = 0;
	for (int i = 2; i <= c; i++)
	{
		cur = cur ^ 1;
		a[cur].clear();
		for (int j = 0; j < a[1 ^ cur].size(); j++)
		{
			if (a[1 ^ cur][j] == 'L')
			{
				a[cur] += s;
			}
			else
			{
				a[cur] += add;
			}
		}
	}
	return a[cur];
}

void generate(int k, int c)
{
	for (int i = 0; i < (1 << k); i++)
	{
		string s;
		for (int j = 0; j < k; j++)
		{
			if (i & (1 << j))
			{
				s += "L";
			}
			else
			{
				s += "G";
			}
		}
		printf("%s\n", power(s, k, c).c_str());
	}
}

void solve()
{
	int64 k, c, s;
	scanf ("%I64d%I64d%I64d", &k, &c, &s);
	//generate(k, c);
	int64 ans = (k + c - 1) / c;
	printf("Case #%d: ", test);
	if (ans > s)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	vector <int64> ind;
	int64 all = 1;
	for (int i = 1; i <= c; i++)
	{
		all *= k;
	}
	for (int j = 1; j <= k; j += c)
	{
		int64 delta = 0, r = all;
		for (int i = j; i <= min(j + c - 1, k); i++)
		{
			delta += (r) / k * (i - 1);
			r /= k;
		}
		ind.push_back(delta + 1);
	}
	for (int i = 0; i < ind.size(); i++)
	{
		printf("%lld ", ind[i]);
	}
	printf("\n");
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef _MY_DEBUG
    freopen("D-large.in", "rt", stdin); freopen("output.txt", "wt", stdout);
#else
    //freopen(TASK ".in", "rt", stdin); freopen(TASK ".out", "wt", stdout);
#endif
    srand(1313);
    
	int tests = 1;
	scanf ("%d", &tests);
	for (test = 1; test <= tests; test++)
	{
		solve();
	}

    return 0;
}