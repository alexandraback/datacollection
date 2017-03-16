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

int n, X, Y;
set <pii> all;
double answer = 0.0;

pii go(int x, int y, int dx)
{
	int it = 0;
	while (y > 0 && !all.count(mp(x + dx, y - 1)))
	{
		//if (it > 0 && y > 1)
		//	assert(all.count(mp(x - dx, y - 1)));
		x += dx;
		y--;
		it++;
	}	
	return mp(x, y);
}

void go(int pos, int maxY, double prob)
{
	if (pos == n)
	{
		if (all.count(mp(X, Y)))
			answer += prob;
		return;	
	}
	if (!all.count(mp(0, 0)))
	{
		all.insert(mp(0, 0));
		go(pos + 1, 1, 1.0);
		all.erase(mp(0, 0));
	}
	else
	{
		int k = !all.count(mp(-1, maxY)) + !all.count(mp(1, maxY));
		if (k == 0)
		{
			all.insert(mp(0, maxY + 1));
			go(pos + 1, maxY + 2, prob);
			all.erase(mp(0, maxY));
		}
		else
		{
			if (!all.count(mp(-1, maxY)))
			{
				pii coord = go(0, maxY + 1, -1);
				all.insert(coord);
				go(pos + 1, maxY, prob * 1.0 / k);
				all.erase(coord);
			}
			if (!all.count(mp(1, maxY)))
			{
				pii coord = go(0, maxY + 1, 1);
				all.insert(coord);
				go(pos + 1, maxY, prob * 1.0 / k);
				all.erase(coord);
			}
		}
	}
}

void solve(int test)
{
	answer = 0;
    scanf("%d%d%d", &n, &X, &Y);
    all.clear();
    go(0, 0, 1.0);
    printf("Case #%d: %.7lf\n", test, answer);
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		solve(test);
		eprintf("solved test %d\n", test);
	}	
	return 0;
}
