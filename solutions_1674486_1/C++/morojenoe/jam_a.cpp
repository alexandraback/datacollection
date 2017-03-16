#pragma comment(linker, "/STACK:1073741824")
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <functional>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <ctime>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, b, a) for (int i = (int)(b); i >= (int)(a); i--)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1000000000;

using namespace std;

void prepare(){
#ifndef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
#endif  
}

int n, m;
vector <int> g[1010];
bool ok;
int used[1010];
int test;

void readdata ()
{
	ok = false;
	for (int i = 0; i <= n; i++)
		g[i].clear();
	scanf ("%d", &n);
	forn (i, n)
	{
		int t;
		scanf ("%d", &t);
		forn(j, t)
		{
			int tt;
			scanf ("%d", &tt);
			g[i + 1].pb ( tt );
		}
	}
}

void writedata ()
{
	if ( ok )
		printf ("Yes\n");
	else
		printf ("No\n");
}

bool dfs (int v)
{
	used[v] = test;
	forn(i, g[v].size())
	{
		int u = g[v][i];
		if (used[u] != test)
		{
			if (dfs ( u ))
				return true;
		}
		else
			return true;
	}
	return false;
}

void solve ()
{
	test ++;
	for (int i = 1; i <= n; i++)
	{
		if (used[i] != test)
			if (dfs ( i ))
			{
				ok = true;
				return;
			}
		test ++;
	}
	test ++;
}

int main()
{
    prepare();
	zero ( used );
	int t;
	n = 1000;
	scanf ("%d",&t);
	test = 1;
	for (int i = 0; i < t; i++)
	{
		printf ("Case #%d: ", i + 1);
		readdata ();
		solve ();
		writedata ();
	}
    return 0;
}