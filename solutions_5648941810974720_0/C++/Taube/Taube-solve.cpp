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

int cnt[26];
string out, in;
char buf[100500];

char d[10] = {'0', '8', '6', '2', '3', '4', '1', '5', '7', '9'};
string s[10] = {"ZERO", "EIGHT", "SIX", "TWO", "THREE", "FOUR", "ONE", "FIVE", "SEVEN", "NINE"};
char c[10] = {'Z', 'G', 'X', 'W', 'H', 'R', 'O', 'F', 'S', 'N'};

void solve()
{
	scanf ("%s", &buf);
	in = buf;
	out = "";
	for (int i = 0; i < in.size(); i++)
	{
		cnt[in[i] - 'A']++;
	}
	for (int i = 0; i < 10; i++)
	{
		while (cnt[c[i] - 'A'])
		{
			for (int j = 0; j < s[i].size(); j++)
			{
				cnt[s[i][j] - 'A']--;
			}
			out.push_back(d[i]);
		}
	}
	sort (out.begin(), out.end());
	printf("Case #%d: %s\n", test, out.c_str());
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