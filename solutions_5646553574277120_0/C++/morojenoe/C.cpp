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

const int NMAX = 55;

int c, d, v;
int a[NMAX];
int b[NMAX];

void read()
{
	scanf("%d %d %d", &c, &d, &v);
	forn(i, d) scanf("%d", &a[i]);
	assert(c == 1);
}

void go()
{
	forn(msk, 1 << d)
	{
		int k = 0;
		forn(i, d)
			if ((msk >> i) & 1)
				k += a[i];
		b[k] = 1;
	}
}
int Test = 1;
void solve()
{
	_(b, 0);
	go();
	int ans = 0;
	for(int i = 0; i <= v; i++)
	{
		if (b[i]) continue;
		ans ++;
		a[d++] = i;
		b[i] = 1;
		go();
	}

	printf("Case #%d: %d\n", Test ++, ans);
}

int main()
{
	prepare("");

	int t;
	scanf("%d", &t);

	forn(i, t)
	{
		read();
		solve();
	}

	return 0;
}
