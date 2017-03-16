#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <iomanip>
#define nextLine() { for (int c = getchar(); c != '\n' && c != EOF; c = getchar()); }
#define sqr(a) ((a)*(a))
#define has(mask,i) (((mask) & (1<<(i))) == 0 ? false : true)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long long LL;
typedef long double ldb;

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;
const ldb PI = fabs(atan2(0.0, -1.0));
const int MAXN = 205;
const int ITERATIONS = 120;

int n;
int s[MAXN];
int all = 0;

void load()
{
	scanf("%d", &n);
	all = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
		all += s[i];
	}	
}

bool good(ldb m, int id)
{
	vector < pair<ldb, int> > cur;
	ldb weHave = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != id) cur.pb(mp(s[i], i));
		else 
		{
			weHave = s[i] + all * m;
			cur.pb(mp(s[i] + all * m, i));
		}	
	}

	sort(cur.begin(), cur.end());
	ldb left = 1.0 - m;
	for (int i = 0; i < n; i++)
	{
		if (cur[i].se == id) return false;
		ldb need = (weHave - cur[i].fi) / all;
		if (left + EPS < need) return true;
		left -= need;
	}
	return true;
}

void solve(int test)
{
	printf("Case #%d:", test);
	for (int i = 0; i < n; i++)
	{
		ldb left = 0.0;
		ldb right = 1.0;
		for (int it = 0; it < ITERATIONS; it++)
		{
			ldb md = (left + right) / 2;
			if (good(md, i)) right = md;
			else left = md;
		}
		printf(" %.10lf", (double)right * 100.0);
	}
	printf("\n");
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		cerr << test << endl;
		load();
		solve(test);
	}	
	return 0;
}
