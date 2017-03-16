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

struct num
{
	int id;
	int minus;
	num() {  }
	num(int _id, int _minus)
	{
		id = _id;
		minus = _minus;
	}
};


const int NMAX = 2000000;

int L;
lint X;
char s[NMAX];
num a[4][4];
int Test = 1;

num operator*(const num &n1, const num &n2)
{
	num res = a[n1.id][n2.id];
	res.minus ^= n1.minus ^ n2.minus;
	return res;
}

void read()
{
	scanf("%d %lld\n%s", &L, &X, s);
}

num get(int id)
{
	return a[s[id] - 'i' + 1][0];
}

void solve()
{
	if (X > 20)
	{
		for(int i = 20; i <= X; i++)
		{
			if ((X - i) % 4 == 0)
			{
				X = i;
				break;
			}
		}
	}

	bool I = false, K = false;
	num cur = num(0, 0);
	for(int i = 0; i < X*L; i++)
	{
		num g = get(i % L);
		cur = cur * g;
		if (cur.id == 1 && cur.minus == 0)
			I = true;
		if (cur.id == 3 && cur.minus == 0 && I)
			K = true;
	}

	bool result = I && K && cur.id == 0 && cur.minus == 1;
	printf("Case #%d: %s\n", Test ++, (result? "YES" : "NO"));
}

int main()
{
	prepare("");

	a[0][0] = num(0, 0);
	a[0][1] = num(1, 0);
	a[0][2] = num(2, 0);
	a[0][3] = num(3, 0);

	a[1][0] = num(1, 0);
	a[1][1] = num(0, 1);
	a[1][2] = num(3, 0);
	a[1][3] = num(2, 1);

	a[2][0] = num(2, 0);
	a[2][1] = num(3, 1);
	a[2][2] = num(0, 1);
	a[2][3] = num(1, 0);

	a[3][0] = num(3, 0);
	a[3][1] = num(2, 0);
	a[3][2] = num(1, 1);
	a[3][3] = num(0, 1);

	int t;
	scanf("%d\n", &t);
	forn(i, t)
	{
		read();
		solve();
	}

	return 0;
}
