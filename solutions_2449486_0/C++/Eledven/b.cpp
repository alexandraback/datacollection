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
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;
const ldb PI = fabs(atan2(0.0, -1.0));

int n, m;
int need[111][111];
void load()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &need[i][j]);
	}
}

int a[111][111];
bool solve()
{
	for (int i = 0; i < n; i++)
	{	
		for (int j = 0; j < m; j++)
			a[i][j] = 100;
	}

	for (int i = 0; i < n; i++)
	{
		int mx = -1;
		for (int j = 0; j < m; j++)
			mx = max(mx, need[i][j]);
		for (int j = 0; j < m; j++)
			a[i][j] = min(a[i][j], mx);	
	}

	for (int j = 0; j < m; j++)
	{
		int mx = -1;
		for (int i = 0; i < n; i++)
			mx = max(mx, need[i][j]);
		for (int i = 0; i < n; i++)
			a[i][j] = min(a[i][j], mx);	
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != need[i][j])
				return false;
		}
	}
	return true;
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		load();
		bool ok = solve();
		printf("Case #%d: %s\n", test, ok ? "YES" : "NO");
	}	
	return 0;
}
