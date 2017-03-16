#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 100 + 3;

int maxWith[35], maxWithout[35];
int n, s, p;
int t[N];
int d[N][N];

int solve ()
{
	forn(i, n + 1)
		forn(j, n + 1)
			d[i][j] = 0;
			
	forn(i, n)
		forn(cnt, s + 1)
		{
			if (maxWithout[t[i]] != -1)
				d[i + 1][cnt] = max(d[i + 1][cnt], d[i][cnt] + (maxWithout[t[i]] >= p));
			
			if (maxWith[t[i]] != -1 && cnt < s)
				d[i + 1][cnt + 1] = max(d[i + 1][cnt + 1], d[i][cnt] + (maxWith[t[i]] >= p));
		}
	
	return d[n][s];
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	memset(maxWith, -1, sizeof(maxWith));
	memset(maxWithout, -1, sizeof(maxWithout));
	
	forn(i, 11)
		forn(j, i + 1)
			forn(k, j + 1)
				if (i - k > 2)
					continue;
				else if (i - k == 2)
					maxWith[i + j + k] = max(maxWith[i + j + k], i);
				else
					maxWithout[i + j + k] = max(maxWithout[i + j + k], i);
					
	int testCount;
	cin >> testCount;
	
	forn(test, testCount)
	{
		scanf("%d%d%d", &n, &s, &p);
		forn(i, n)
			scanf("%d", &t[i]);
			
		printf("Case #%d: %d\n", test + 1, solve());
	}				

	return 0;
}
























































