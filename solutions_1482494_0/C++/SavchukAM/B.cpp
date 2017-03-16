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
const int INF = 1000 * 1000 * 1000, NMAX = 1005;

PII a[NMAX], b[NMAX];

int main() {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);    
	ios_base::sync_with_stdio(false);
	int tests;
	cin >> tests;
	forn(test, tests) {				
		int n;
		cin >> n;
		
		bool wasZ = false;
		forn(i, n) {
			cin >> a[i].fs >> b[i].fs;
			a[i].sc = b[i].sc = i;
			if (a[i].fs == 0 || b[i].fs == 0) wasZ = true;
		}
		if (!wasZ) {
			cout << "Case #" << test + 1 << ": Too Bad\n";
			continue;
		}
		bool used[NMAX];
		memset(used, false, sizeof(used));

		sort(a, a + n);
		sort(b, b + n);

		int s = 0;
		int ans = 0;

		bool bad = false;
		bool wasG = false;
		forn(i, n) {
			if (s >= b[i].fs) {
				if (used[b[i].sc]) ++s;
				else s += 2;
				++ans;
			} else {
				for (int j = i; j < n; j++) {
					if (s >= b[i].fs) break;
					if (!used[a[j].sc]) {
						if (j == n - 1) wasG = true;
						s += 1;
						++ans;
						used[a[j].sc] = true;
					}
				}
				if (s >= b[i].fs) {
					if (used[b[i].sc]) ++s;
					else s += 2;
					++ans;
				} else {
					bad = true;
					break;
				}
			}
		}
		if (wasG) --ans;
		if (bad) cout << "Case #" << test + 1 << ": Too Bad\n";
		else cout << "Case #" << test + 1 << ": " << ans << "\n";
	}
    return 0;
}
