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
#include <memory.h>
#include <sstream>
#include <cassert>
#include <ctime>
#include <complex>
#include <random>
 
using namespace std;
 
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<pii, pii> piiii;
typedef pair<int64, int> pli;
typedef pair<double, double> pdd;
 
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
const int64 LINF = 1e18;
const int MOD = 1000000007;

int test;

string s1, s2;
string p1, p2;
string a1, a2;
char buf1[100], buf2[100];
int c1 = INF, c2 = 0;

inline int to_int(string s)
{
	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}

void rec2(int pos2)
{
	if (pos2 == p2.size())
	{
		int r1 = to_int(s1);
		int r2 = to_int(s2);
		if (abs(c1 - c2) > abs(r1 - r2)
			|| abs(c1 - c2) == abs(r1 - r2) && r1 < c1
			|| abs(c1 - c2) == abs(r1 - r2) && r1 == c1 && r2 < c2)
		{
			c1 = r1;
			c2 = r2;
			a1 = s1;
			a2 = s2;
		}
	}
	else
	{
		char l = '0', r = '9';
		if (p2[pos2] != '?')
		{
			l = r = p2[pos2];
		}
		for (char i = l; i <= r; i++)
		{
			s2[pos2] = i;
			rec2(pos2 + 1);
		}
	}
}

void rec1(int pos1)
{
	if (pos1 == p1.size())
	{
		rec2(0);
	}
	else
	{
		char l = '0', r = '9';
		if (p1[pos1] != '?')
		{
			l = r = p1[pos1];
		}
		for (char i = l; i <= r; i++)
		{
			s1[pos1] = i;
			rec1(pos1 + 1);
		}
	}
}

void solve()
{
	c1 = INF; c2 = 0;
	scanf ("%s%s", &buf1, &buf2);
	p1 = buf1;
	p2 = buf2;
	s1.resize(p1.size());
	s2.resize(p2.size());
	rec1(0);
	printf("Case #%d: %s %s\n", test, a1.c_str(), a2.c_str());
}

#define TASK "substr"

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef _MY_DEBUG
    freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
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