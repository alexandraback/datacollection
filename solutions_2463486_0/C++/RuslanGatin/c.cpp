#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/stack:256000000")

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <bitset>
#include <map>
#include <memory.h>
#include <cassert>
#include <ctime>

using namespace std;

#define fo(a,b,c) for (int a = (b); a < (c); a++)
#define fr(a,b) fo(a, 0, (b))
#define fi(n) fr(i, (n))
#define fj(n) fr(j, (n))
#define fk(n) fr(k, (n))
#define fd(a,b,c) for (int a = (b); a >= (c); a--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define _(a,b) memset((a), (b), sizeof(a))
#define __(a) memset((a), 0, sizeof(a))
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long lint;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> pii;

const int INF = 1000000000;
const lint LINF = 4000000000000000000LL;
const double eps = 1e-9;

int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

void prepare()
{
	freopen("input.txt", "r", stdin);
	freopen("c-small.in", "r", stdin);
	freopen("c-small.out", "w", stdout);
}

void panic(bool expression = false)
{
	if (!expression)
	{
		cerr << "PANIC!" << endl;
		assert(false);
	}
}

lint pals[39] =
{
1LL,
4LL,
9LL,
121LL,
484LL,
10201LL,
12321LL,
14641LL,
40804LL,
44944LL,
1002001LL,
1234321LL,
4008004LL,
100020001LL,
102030201LL,
104060401LL,
121242121LL,
123454321LL,
125686521LL,
400080004LL,
404090404LL,
10000200001LL,
10221412201LL,
12102420121LL,
12345654321LL,
40000800004LL,
1000002000001LL,
1002003002001LL,
1004006004001LL,
1020304030201LL,
1022325232201LL,
1024348434201LL,
1210024200121LL,
1212225222121LL,
1214428244121LL,
1232346432321LL,
1234567654321LL,
4000008000004LL,
4004009004004LL
};
int np = 39;
char s[50];

bool isPal(lint num)
{
	sprintf(s, "%lld", num);
	int n = strlen(s), n2 = n >> 1;
	fi(n2)
	{
		if (s[i] != s[n - i - 1])
			return false;
	}
	return true;
}

void pre()
{
	fi(10000000)
	{
		if (isPal(i))
		{
			lint z = (lint)i * i;
			if (isPal(z))
			{
				cerr << z << endl;
				pals[np++] = z;
			}
		}
	}
	cerr << np;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	lint a = nll(), b = nll();
	int start = lower_bound(pals, pals + np, a) - pals;
	int finish = upper_bound(pals, pals + np, b) - pals;
	printf("%d\n", finish - start);
}

int main()
{
	prepare();
	//pre();
	int number_of_tests;
	scanf("%d\n", &number_of_tests);
	fi(number_of_tests)
		solve(i + 1);
	return 0;
}