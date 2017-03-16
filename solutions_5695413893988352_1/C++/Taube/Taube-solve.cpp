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
const int64 LINF = 8e18;
const int MOD = 1000000007;

int test;

string s1, s2;
string p1, p2;
string a1, a2;
char buf1[100], buf2[100];
int64 c1 = LINF, c2 = 0;

inline int64 to_int(string s)
{
	int64 res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		res *= 10LL;
		res += s[i] - '0';
	}
	return res;
}

void update()
{
	int64 r1 = to_int(s1);
	int64 r2 = to_int(s2);
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

void fill_max(string &p, string &s, int pos)
{
	for (int i = pos; i < s.size(); i++)
	{
		if (p[i] == '?')
		{
			s[i] = '9';
		}
		else
		{
			s[i] = p[i];
		}
	}
}

void fill_min(string &p, string &s, int pos)
{
	for (int i = pos; i < s.size(); i++)
	{
		if (p[i] == '?')
		{
			s[i] = '0';
		}
		else
		{
			s[i] = p[i];
		}
	}
}

void solve()
{
	c1 = LINF; c2 = 0;
	scanf ("%s%s", &buf1, &buf2);
	p1 = buf1;
	p2 = buf2;
	s1.resize(p1.size());
	s2.resize(p2.size());
	
	for (int i = 0; i < p1.size(); i++)
	{
		if (p1[i] == '?' && p2[i] == '?')
		{
			s1[i] = '0';
			s2[i] = '1';
			fill_max(p1, s1, i + 1);
			fill_min(p2, s2, i + 1);
			update();
			s1[i] = '1';
			s2[i] = '0';
			fill_min(p1, s1, i + 1);
			fill_max(p2, s2, i + 1);
			update();
			s1[i] = s2[i] = '0';
		}
		else if (p1[i] != '?' && p2[i] == '?')
		{
			if (p1[i] != '9')
			{
				s1[i] = p1[i];
				s2[i] = p1[i] + 1;
				fill_max(p1, s1, i + 1);
				fill_min(p2, s2, i + 1);
				update();
			}
			if (p1[i] != '0')
			{
				s1[i] = p1[i];
				s2[i] = p1[i] - 1;
				fill_min(p1, s1, i + 1);
				fill_max(p2, s2, i + 1);
				update();
			}
			s1[i] = s2[i] = p1[i];
		}
		else if (p1[i] == '?' && p2[i] != '?')
		{
			if (p2[i] != '0')
			{
				s1[i] = p2[i] - 1;
				s2[i] = p2[i];
				fill_max(p1, s1, i + 1);
				fill_min(p2, s2, i + 1);
				update();
			}
			if (p2[i] != '9')
			{
				s1[i] = p2[i] + 1;
				s2[i] = p2[i];
				fill_min(p1, s1, i + 1);
				fill_max(p2, s2, i + 1);
				update();
			}
			s1[i] = s2[i] = p2[i];
		}
		else
		{
			s1[i] = p1[i];
			s2[i] = p2[i];
			if (p1[i] != p2[i])
			{
				if (p1[i] < p2[i])
				{
					fill_max(p1, s1, i + 1);
					fill_min(p2, s2, i + 1);
				}
				else
				{
					fill_min(p1, s1, i + 1);
					fill_max(p2, s2, i + 1);
				}
				break;
			}
		}
	}
	update();

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