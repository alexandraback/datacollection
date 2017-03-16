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

const long double eps = 1e-7;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n;
char p[50];
double v[50], x[50];

string write (double x) {
	char buf[100];
	sprintf (buf, "%.10lf", x);
	return buf;
}

bool try_move (int v) {
	bool ok = 1;
	forn (i, n)
		if (v != i && fabs (x[v] - x[i]) - 5 < -eps)
			ok = 0;
	if (!ok)
		return 0;
	if (p[v] == 'L')
		p[v] = 'R';
	else
		p[v] = 'L';
	return 1;
	
}

string calc () {
	cin >> n;
	forn (i, n)
		cin >> p[i] >> v[i] >> x[i];
	double cur = 0;
	while (1) {
		double t = 1e100;
		forn (i, n)
			forn (j, n)
				if (i != j)
					if (p[i] == p[j] && x[i] <= x[j] && v[i] > v[j])
						t = min (t, (x[j] - x[i] - 5) / (v[i] - v[j]));
		if (t > 1e50)
			return "Possible";
		cur += t;
		forn (i, n)
			x[i] += v[i] * t;
		double m = x[0];
		forn (i, n)
			m = min (m, x[i]);
		forn (i, n)
			x[i] -= m;
		bool ok = 0;
		int it = 0;
		while (!ok) {
			it ++;
			if (it == 100000)
				return write (cur);
			bool ch = 0;
			forn (i, n)
				forn (j, n)
					if (i != j && p[i] == p[j] && fabs (x[j] - x[i]) - 5 < eps && v[i] > v[j] && x[i] < x[j]) {
						if (try_move (i)) 
							ch = 1;
						else
						if (try_move (j))
							ch = 1;
						else
							return write (cur);
					}
			if (ch)
				ok = 0;
			else
				ok = 1;
		}
	}

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
