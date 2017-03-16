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

const int NMAX = 315;

int Test = 1;
int k, l, s;
int lenkey;
int lenstr;
char key[NMAX];
char str[NMAX];
int cnt[NMAX];

void read()
{
	scanf("%d %d %d\n", &k, &l, &s);
	scanf("%s\n%s\n", key, str);
}

char word[NMAX];

int cntBananas(char *word)
{
	int res = 0;
	for(int i = 0; i < s - l + 1; i++)
	{
		bool ok = true;
		for(int j = 0; j < l; j++)
		{
			ok = ok && word[i + j] == str[j];
		}
		if (ok)
			res ++;
	}
	return res;
}

void go(int i)
{
	if (i == s)
	{
		cnt[cntBananas(word)] ++;
		return;
	}

	for(int j = 0; j < lenkey; j++)
	{
		word[i] = key[j];
		go(i + 1);
	}
}

bool gopa()
{
	int used[500];
	_(used, 0);
	for(int i = 0; i < k; i++)
		used[key[i]] = 1;

	for(int i = 0; i < l; i++)
		if (!used[str[i]])
			return true;
	return false;
}

void solve()
{
	if (s < l || gopa())
	{
		printf("Case #%d: 0\n", Test ++);
		return;
	}

	lenkey = strlen(key);
	lenstr = strlen(str);
	_(cnt, 0);
	go( 0 );

	int sum = 0;
	int maxb = 0;
	for(int i = 0; i <= 100; i++)
	{
		sum += cnt[i];
		if (cnt[i])
			maxb = i;
	}

	double ans = maxb;
	for(int i = 0; i <= maxb; i++)
		ans -= ((double)cnt[i] / (double)sum) * (double)i;

	printf("Case #%d: %.15lf\n", Test ++, ans);

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
