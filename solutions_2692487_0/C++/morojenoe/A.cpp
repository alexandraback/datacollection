#pragma comment(linker, "/STACK:128777216")
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <string.h>
#include <cmath>
#include <math.h>
#include <queue>
#include <cassert>
#include <time.h>
#include <bitset>
#include <sstream>

#define forn(i,n) for (int i = 0; i < (int)n; i++)
#define fornd(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define forab(i,a,b) for (int i = (int)a; i <= (int)b; i++)
#define forabd(i, b, a) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define zero(a) memset (a, 0, sizeof (a))
#define last(v) (int)v.size() - 1
#define _(a, val) memset (a, val, sizeof (a))
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll LINF = 1000000000000000000LL;
const int INF = 1000000000;
const long double eps = 1e-9;
const long double PI = 3.1415926535897932384626433832795l;

using namespace std;

void prepare (string s)
{
#ifndef _DEBUG
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

int a, n;
const int nmax = 110;
int b[nmax];
int id = 0;
void solve ();
void writedata ();

void readdata ()
{
	scanf ("%d %d", &a, &n);
	forn(i, n)
		scanf ("%d", &b[i]);
	sort (b, b + n);

	if (a == 1)
	{
		printf ("%d\n", n);
		return;
	}

	solve ();
}

void writedata ()
{

}

void solve ()
{
	queue <pair <pair <int, int>, int> > q;
	q.push( mp (mp (a, 0), 0) );
	while (!q.empty())
	{
		int aa = q.front().first.first;
		int p = q.front().first.second;
		int tt = q.front().second;
		q.pop();

		
		for (; p < n && b[p] < aa ; p ++)
			aa += b[p];
		
		if (p == n)
		{
			printf ("%d\n", tt);
			return;
		}

		

		q.push (mp (mp (aa + aa - 1, p), tt + 1));
		q.push (mp (mp (aa, p + 1), tt + 1));
	}
}

void test ()
{
	freopen ("input.txt", "w", stdout);
	printf ("100\n");
	forn(i, 100)
	{
		printf ("%d 100\n", 2);
		forn (j, 100)
		{
			int t = ((rand() << 15) + rand ()) % 1000000 + 1;
			printf ("%d ", t);
		}
		printf ("\n");
	}
}

int main ()
{
	prepare ("");
	int t;
	scanf ("%d", &t);
	forn(i, t)
	{
		printf ("Case #%d: ", i + 1);
		readdata ();
	}
	//test ();
	return 0;
}


