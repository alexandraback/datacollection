#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <cassert>
#include <ctime>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <functional>
#include <limits>
#include <cstring>
using namespace std;

typedef long long li;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int,int> pt;


#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n - 1); i >= 0; i--)
#define pb push_back
#define mp make_pair
#define matrix(T,n,m,v) vector<vector<T> >(n, vector<T>(m, v))
#define ft first
#define sc second
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()

template<class T> T sqr(const T& x) { return x * x; }
template<class T> T abs(const T& x) { return x < 0 ? -x : x; }

template<class T, class P>
ostream& operator << (ostream& out, std::pair<T, P> p) {
	return (out << '(' << p.first << ' ' << p.second << ')');
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-8;
const ld PI = 3.1415926535897932384626433832795;

const int N = 1000 + 13;

int n;
ld a[N], b[N];

bool read() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
	}
	forn (i, n) {
		cin >> b[i];
	}
	return true;
}

int war() {
	sort(a, a + n);
	sort(b, b + n);
	reverse(a, a + n);
	bool used[N];
	memset(used, 0, sizeof(used));
	int ans = 0;
	forn (i, n) {
		ld v = a[i];
		int k = -1;
		forn (j, n) {
			if (b[j] > v && !used[j]) {
				k = j;
				break;
			}
		}
		if (k == -1) {
			forn (j, n) {
				if (!used[j]) {
					k = j;
					break;
				}
			}
			used[k] = true;
			ans++;
		} else {
			used[k] = true;
		}
	}
	return ans;
}

int decWar() {
	sort(a, a + n);
	sort(b, b + n);

	/*
	forn (i, n) {
		cerr << double(a[i]) << ' ';
	}
	cerr << endl;
	forn (i, n) {
		cerr << double(b[i]) << ' ';
	}
	cerr << endl;
	*/

	bool used[N];
	memset(used, 0, sizeof(used));
	int ans = 0;
	forn (i, n) {
		ld v = a[i];
		int k = -1;
		forn (j, n) {
			if (!used[j]) {
				k = j;
				break;
			}
		}
		if (b[k] > v) {
			ford (j, n) {
				if (!used[j]) {
					k = j;
					break;
				}
			}
		    used[k] = true;
		} else {
			used[k] = true;
			ans++;
		}
	}
	return ans;
}

void solve(int test) {
	cout << "Case #" << test << ": " << decWar() << ' ' << war() << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int testCnt;
	cin >> testCnt;
	forn (test, testCnt) {
		read();
		solve(test + 1);
	}
	
    return 0;
}