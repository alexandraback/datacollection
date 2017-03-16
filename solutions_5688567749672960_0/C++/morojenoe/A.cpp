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

int n;
queue<lint> q;
map<lint, int> d;

void read()
{
	scanf("%d", &n);
}

bool upd(lint k, int val)
{
	if (d.find(k) == d.end())
	{
		d[k] = val;
		q.push( k );
	}
	if (k == n) return true;
	return false;
}

lint rev(lint k)
{
	char tmp[25];
	forn(i, 25) tmp[i] = '\0';
	sprintf(tmp, "%lld", k);
	int len = strlen(tmp);
	reverse(tmp, tmp + len);
	lint r = 0;

	forn(i, len)
		r = r*10LL + tmp[i] - '0';
	return r;
}

int Case = 1;

void stupsolve()
{
	while(!q.empty()) q.pop();
	d[1] = 1;
	q.push( 1 );
	while(!q.empty())
	{
		lint k = q.front(); q.pop();
		if (k > INF / 1000) continue;
		if (k == n) break;
		if (upd(k + 1, d[k] + 1)) break;
		if (upd(rev(k), d[k] + 1)) break;
	}
}

void solve()
{
	printf("Case #%d: %d\n", Case ++, d[n]);
}

int main()
{
	prepare("");

	stupsolve();

	int t;
	scanf("%d", &t);

	forn(i, t)
	{
		read();
		solve();
	}

	return 0;
}
