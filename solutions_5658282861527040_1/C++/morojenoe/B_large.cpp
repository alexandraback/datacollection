#pragma comment(linker, "/STACK:128777216")
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <string.h>
#include <sstream>
#include <cmath>
#include <math.h>
#include <queue>
#include <deque>
#include <cassert>
#include <time.h>

#define forn(i,n) for (int i = 0; i < (int)n; i++)
#define fornd(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define forab(i,a,b) for (int i = (int)a; i <= (int)b; i++)
#define forabd(i, b, a) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define zero(a) memset (a, 0, sizeof (a))
#define last(v) (int)v.size() - 1
#define _(a, val) memset (a, val, sizeof (a))
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

#ifdef _DEBUG
#define dbg(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define dbgx(x) {cerr << #x << " = " << x << endl;}
#define dbgv(v) {cerr << #v << " = {"; for (typeof(v.begin()) it = v.begin(); it != v.end(); it ++) cerr << *it << ", "; cerr << "}"; cerr << endl;}
#else
#define dbg(...) { }
#define dbgx(x) { }
#define dbgv(v) { }
#endif

typedef long long lint;
typedef unsigned long long ull;
typedef long double ld;

const lint LINF = 1000000000000000000LL;
const int INF = 1000000000;
const long double eps = 1e-9;
const long double PI = 3.1415926535897932384626433832795l;

using namespace std;

void prepare (string s)
{
#ifdef _DEBUG
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

const int MAXSTATE = 2;
lint dp[32][MAXSTATE][MAXSTATE][MAXSTATE];
int a, b, c;

void read()
{
	scanf("%d %d %d", &a, &b, &c);
}

int g_bit(int msk, int bit)
{
	return (msk >> bit) & 1;
}

int nxt_msk(int cur_state, int msk, int cur_bit, int d)
{
	if (cur_state == 0)
		return 0;
	if (cur_state == 1)
	{
		if (g_bit(msk, cur_bit) < d)
			return -1;
		if (g_bit(msk, cur_bit) == d)
			return 1;
		return 0;
	}
	assert( false );
	return -1;
}

void upd2(int bit, int s1, int s2, int s3, lint val)
{
	dp[bit][s1][s2][s3] += val;
}

void upd(int bit, int s1, int s2, int s3)
{
	int ns1, ns2, ns3;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			ns1 = nxt_msk(s1, a, bit - 1, i);
			ns2 = nxt_msk(s2, b, bit - 1, j);
			ns3 = nxt_msk(s3, c, bit - 1, i & j);
			if (ns1 == -1 || ns2 == -1 || ns3 == -1) continue;
			upd2(bit - 1, ns1, ns2, ns3, dp[bit][s1][s2][s3]);
		}
	}
}

void solve()
{
	_(dp, 0);
	dp[31][1][1][1] = 1;
	
	for(int i = 31; i >= 1; i--)
	{
		for(int s1 = 0; s1 < MAXSTATE; s1 ++)
		{
			for(int s2 = 0; s2 < MAXSTATE; s2++)
			{
				for(int s3 = 0; s3 < MAXSTATE; s3 ++)
				{
					if (dp[i][s1][s2][s3] > 0)
						upd(i, s1, s2, s3);
				}
			}
		}
	}
	
	
	printf("%lld\n", dp[0][0][0][0]);
}

int main ()
{
	prepare ("");

	int t;
	scanf("%d", &t);
	forn(i, t)
	{
		printf("Case #%d: ", i + 1);
		read();
		solve();
	}

	return 0;
}
