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

char buf[100500];
string s;

int func(string s)
{
	int ans = 0;
	int l = 0, r = 0;
	while (r < s.size())
	{
		while (r + 1 < s.size() && s[l] == s[r + 1])
		{
			r++;
		}
		l = ++r;
		ans++;
	}
	if (s.back() == '+')
	{
		ans--;
	}
	return ans;
}

void solve()
{
	scanf ("%s", &buf);
	printf("Case #%d: %d\n", test, func(buf));
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef _MY_DEBUG
    freopen("B-small-attempt0.in", "rt", stdin); freopen("output.txt", "wt", stdout);
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