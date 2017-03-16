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
int K, L, S;
int lenkey;
int lenstr;
char key[NMAX];
char str[NMAX];
int cnt[NMAX];

const int DPMAX = 105;
double dp[DPMAX][DPMAX][DPMAX];
int mapa[NMAX][30];

void read()
{
	scanf("%d %d %d\n", &K, &L, &S);
	scanf("%s\n%s\n", key, str);
}

bool gopa()
{
	int used[500];
	_(used, 0);
	for(int i = 0; i < K; i++)
		used[key[i]] = 1;

	for(int i = 0; i < L; i++)
		if (!used[str[i]])
			return true;
	return false;
}

int kmp(char *s) {
	int n = strlen(s);
	vector<int> pi (n);
	for (int i=1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi[n - 1];
}

int get(int L1, int SYMB)
{
	char a[300];
	_(a, 0);
	forn(i, lenstr)
		a[i] = str[i];
	a[lenstr] = '#';
	forn(i, L1)
		a[lenstr + 1 + i] = str[i];
	a[lenstr + L1 + 1] = 'A' + SYMB;
	a[lenstr + L1 + 2] = '\0';
	return kmp( a );
}

void calcmp()
{
	_(mapa, 0);
	for(int i = 0; i <= lenstr; i++)
		mapa[i][str[0] - 'A'] = 1;

	for(int i = 1; i <= lenstr; i++)
	{
		for(int j = 0; j < 26; j++)
			mapa[i][j] = get(i, j);
	}
}

int calcMaxB()
{
	int k = kmp(str);
	int ans = 1;
	int cur = L;
	while(cur <= S)
	{
		cur += L - k;
		ans ++;
	}
	return ans - 1;
}

void calcdp(int maxb)
{
	forn(i, S + 5) forn(j, L + 5) forn(k, maxb + 5) dp[i][j][k] = 0.0;

	dp[0][0][0] = 1.0;
	forn(i, S)
	{
		forn(j, L + 1)
		{
			forn(k, maxb + 1)
			{
				if (dp[i][j][k] < eps) continue;
				for(int c = 0; c < K; c++)
				{
					dp[i + 1][mapa[j][key[c] - 'A']][k + (int)(mapa[j][key[c] - 'A'] == L)] += dp[i][j][k] / (double)K;
				}
			}
		}
	}
}

void solve()
{
	if (S < L || gopa())
	{
		printf("Case #%d: 0\n", Test ++);
		return;
	}

	lenkey = strlen(key);
	lenstr = strlen(str);

	calcmp();

	int maxb = calcMaxB();

	
	calcdp(maxb);

	double ans = maxb;
	for(int i = 0; i <= maxb; i++)
	{
		for(int j = 0; j <= L; j++)
			ans -= dp[S][j][i] * i;
	}

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
