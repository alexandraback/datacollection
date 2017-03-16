#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:128777216")

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>

#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <string.h>

#include <memory.h>
#include <cassert>
#include <time.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i,a,b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, b, a) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define _(a, val) memset (a, val, sizeof (a))
#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long lint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vii;

const lint LINF = 1000000000000000000LL;
const int INF = 1000000000;
const long double eps = 1e-9;
const long double PI = 3.1415926535897932384626433832795l;

#ifdef MY_DEBUG
#define dbgx( x ) { cerr << #x << " = " << x << endl; }
#define dbg( ... ) { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#else
#define dbgx( x ) {  } 
#define dbg( ... ) {  } 
#endif

void prepare(string s)
{
#ifdef MY_DEBUG
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#else
	if (s.length() != 0)
	{
		freopen ((s + ".in").c_str(), "r", stdin);
		freopen ((s + ".out").c_str(), "w", stdout);
	}
#endif
}

const int NMAX = 1005;

int n;
int a[NMAX];
int mx;
int d[NMAX][NMAX];
int Test = 1;

void read()
{
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
}

void build()
{
	for(int i = 0; i < NMAX; i++)
	{
		for(int j = 0; j < NMAX; j++)
		{
			if (i <= j)
				d[i][j] = 0;
			else
			{
				d[i][j] = INF;
				for(int k = 1; k < i; k++)
					d[i][j] = min(d[i][j], 1 + d[k][j] + d[i - k][j]);
			}
		}
	}
}

void solve()
{
	mx = *max_element(a, a + n);
	int ans = INF;
	for(int i = 1; i <= mx; i++)
	{
		int tmp = i;
		for(int j = 0; j < n; j++)
		{
			tmp += d[a[j]][i];
		}
		ans = min(ans, tmp);
	}

	printf("Case #%d: %d\n", Test ++, ans);
}

int main()
{
	prepare("");

	build();

	int t;
	scanf("%d\n", &t);
	forn(i, t)
	{
		read();
		solve();
	}

	return 0;
}
