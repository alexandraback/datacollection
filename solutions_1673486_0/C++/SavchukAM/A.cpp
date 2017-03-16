#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:67108864")

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <string>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <iostream>

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define forn(i, n) for(register int i = 0; i < int(n); ++i)
#define forv(i, v) forn(i, (v).size())

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define all(v) (v).begin(), (v).end()
#define correct(x, y, n, m) ((x) >= 0 && (x) < (n) && (y) >= 0 && (y) < (m))

template <class T> inline T abs(T a) { return (a) > 0 ? (a) : -(a); }
template <class T> inline T sqr(T a) { return (a) * (a); }

typedef long double ld;
typedef pair <ld, ld> pt;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef long long LL;

const ld PI = 3.1415926535897932, EPS = 1E-9;
const int INF = 1000 * 1000 * 1000, NMAX = 100005;

int main() {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);    
	cout.precision(6);
	cout.setf(ios::fixed);
	ios_base::sync_with_stdio(false);
	int tests;
	cin >> tests;
	forn(test, tests) {				
		int	n, all;
		cin >> n >> all;
		ld a[NMAX];
		forn(i, n) cin >> a[i]; 

		ld p[NMAX];
		p[0] = 1;
		forn(i, n)
			p[i + 1] = p[i] * a[i];		

		ld m1 = p[n] * (all - n + 1) + (1 - p[n]) * (all - n + 1 + all + 1);

		ld m2 = INF;
		for (int b = 1; b <= n; b++) {
			m2 = min(m2, p[n - b] * (b + all - (n - b) + 1) + (1 - p[n - b]) * (b + all - (n - b) + 1 + all + 1));
		}

		ld m3 = 2 + all;

		cout << "Case #" << test + 1 << ": " << min(min(m1, m2), m3) << "\n";
	}
    return 0;
}
