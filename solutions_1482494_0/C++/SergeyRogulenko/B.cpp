#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n;
int a[1000], b[1000];
multiset <int> ONE;
bool u[1000];

string calc () {
	cin >> n;
	forn (i, n)
		cin >> a[i] >> b[i];
	int res = 0;
	ONE.clear ();
	seta (u, 0);
	int cnt = 0;
	while (res < n*2) {
		if (ONE.size() > 0 && (*ONE.begin()) <= res) {
			res ++;
			cnt ++;
			ONE.erase (ONE.begin());
			continue;
		}
		bool ok = 0;
		forn (i, n)
			if (!u[i] && b[i] <= res) {
				u[i] = 1;
				cnt ++;
				res += 2;
				ok = 1;
				break;
			}
		if (ok)
			continue;
		int v = -1;
		forn (i, n)
			if (!u[i] && a[i] <= res) 
				if (v == -1 || b[i] >= b[v]) 
					v = i;
		if (v != -1) {
			res ++;
			cnt ++;
			u[v] = 1;
			ONE.insert (b[v]);
			continue;
		}
		break;
	}
	if (res < n*2)
		return "Too Bad";
	char buf[1000];
	sprintf (buf, "%d", cnt);
	return buf;

}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn (ii, tt) {
		printf ("Case #%d: %s\n", ii+1, calc().data());
	}	
	return 0;
}
