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
#include <unordered_set>
//#include <random>
 
using namespace std;
 
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef double ldouble;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<pii, pii> piiii;
 
#define pb push_back
#define sq(x) ((x)*(x))
#define tmin(x,y,z) (min(min((x),(y)),(z)))
#define rand32() (((unsigned int)(rand()) << 16) | (unsigned int)(rand()))
#define rand64() (((unsigned int64)(rand32()) << 16) | (unsigned int64)(rand32()))
#define bit(mask, b) ((mask >> b) & 1)
#define biton(mask, bit) (mask | (((uint64)(1)) << bit))
#define bitoff(mask, bit) (mask & (~(((uint64)(1)) << bit)))
#define bitputon(mask, bit) (mask |= (((uint64)(1)) << bit))
#define bitputoff(mask, bit) (mask &= (~(((uint64)(1)) << bit)))
#define FAIL() (*((int*)(0)))++
#define INF ((int)(1e9) + 1337)
#define LINF ((int64)(1e18))
#define EPS (1e-7)
#define PI (3.1415926535897932384626433832795)
#define y1 yy1
#define y0 yy0
#define j0 jj0

//#define HMOD (1000000000000000003LL)
//#ifdef _MY_DEBUG
//#define HMOD 1000000007
//#endif
//#define HBASE 524287

//mt19937 ggen;
const int MAXN = 3010;
int n, cnt;
int ans = 0, num = 0;
vector < int > siev;
vector < int64 > di;
vector < int > jab;
string a;
int64 pr(int64 x)
{
	for(int64 i = 2; i * i <= x; ++i)
	{
		if (!(x % i))
			return i;
	}
	return -1;
}

int solve()
{
	cin >> n >> cnt;
	di.resize(11);
	jab.resize(n);
	siev.resize(1 << 27);
	
	for(int i = 0; i <= (1 << (n - 2)) && cnt; ++i)
	{
		int x = i;
		for(int j = 1; j < n - 1; ++j)
			jab[j] = ((1 << (j - 1)) & i) > 0;
		jab[0] = 1;
		jab[n - 1] = 1;
		bool flag = 0;
		for(int I = 2; I <= 10; ++I)
		{
			int64 num = 0, pw = 1;
			for(int j = 0; j < n; ++j)
			{
				num += jab[j] * pw;
				pw *= I;
			}
			int64 k = pr(num);
			if (k != -1)
			{
				di[I] = k;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			continue;
		for(int I = n - 1; I >= 0; --I)
			printf("%d", jab[I]);
		for(int I = n - 1; I >= 0; --I)
			printf("%d", jab[I]);
		for(int I = 2; I < 11; ++I)
			printf(" %d", di[I]);
		printf("\n");
		cnt--;
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef _MY_DEBUG
    freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#else
    //freopen(TASK ".in", "rt", stdin); freopen(TASK ".out", "wt", stdout);
#endif
    srand(1313);
	int t;
	scanf("%d", &t);
	for(int j = 1; j <= t; ++j)
	{
		printf("Case #1:\n");
		solve();
	}
    return 0;
}