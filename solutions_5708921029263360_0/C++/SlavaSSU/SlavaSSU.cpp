#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:640000000")

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <bitset>
#ifdef _DEBUG
#include <unordered_set>
#include <unordered_map>
#endif

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define forn1(i, n) for(int i = 1; i <= (int)(n); i++)
#define forr(i, l, r) for(int i = int(l); i <= int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define y1 __y1
#define sqr(x) ((x) * (x))

typedef long long li;
typedef double ld;
typedef unsigned int uint;
typedef unsigned long long uli;
typedef pair<int, int> pt;

inline void read(int&);
inline void read(li&);
inline void read(ld&);
inline void read(char&);
inline void read(string&);
template <typename T1, typename T2> inline void read(T1&, T2&);
template <typename T1, typename T2, typename T3> inline void read(T1&, T2&, T3&);
template <typename T1, typename T2, typename T3, typename T4> inline void read(T1&, T2&, T3&, T4&);

inline void read(string &s) {
	static char buf[int(1e6) + 10];
	assert(scanf("%s", buf) == 1);
	s = string(buf);
	return;
}

const int INF = (int)(1e9);
const li INF64 = (li)(INF)* (li)(INF);
const ld eps = 1e-9;
const ld pi = ld(3.1415926535897932384626433832795);

inline bool in(int i, int j, int n, int m) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

inline int myrand() {
	return (rand() ^ (rand() << 15));
}

inline li randL() {
	return myrand() * 1LL * myrand() + myrand();
}

const int dx[] = { 0, -1, 1, 0 };
const int dy[] = { -1, 0, 0, 1 };

const int N = 11;

int A, B, C, K;

inline void gen() {
	return;
}

inline bool read() {
	if (!(cin >> A >> B >> C >> K)) return false;
	return true;
}

bool used[N][N][N];
int usedAB[N][N], usedBC[N][N], usedAC[N][N];
vector<pair<pt, int> > nans;
int a, b, c;
int startT;

void brute(int day, vector<pair<pt, int> >& cur) {
	if (clock() - startT > 10000) return;
	//cerr << "a b c == " << a << ' ' << b << ' ' << c << endl;
	//cerr << "cur == " << sz(cur) << endl;
	//forn(i, sz(cur)) cerr << cur[i].x.x << ' ' << cur[i].x.y << ' ' << cur[i].y << endl;
	if (sz(cur) > sz(nans)) nans = cur;
	//if (a == 0 || b == 0 || c == 0) return;
	forn(i, A) forn(j, B) forn(k, C) {
		//if (a == 0 || b == 0 || c == 0)
		bool valid = true;
		if (used[i][j][k]) continue;
		if (usedAB[i][j] == K) continue;
		if (usedBC[j][k] == K) continue;
		if (usedAC[i][k] == K) continue;
		usedAB[i][j]++;
		usedBC[j][k]++;
		usedAC[i][k]++;
		used[i][j][k] = true;
		//a--, b--, c--;
		cur.push_back(mp(mp(i, j), k));
		brute(day + 1, cur);
		cur.pop_back();
		//a++, b++, c++;
		usedAB[i][j]--;
		usedBC[j][k]--;
		usedAC[i][k]--;
		used[i][j][k] = false;
	}
}

inline int naive() {
	//cout << "ABCK == " << A << ' ' << B << ' ' << C << ' ' << K << endl;
	if (K >= 3) {
		cout << A * B * C << endl;
		memset(used, false, sizeof used);
		memset(usedAB, 0, sizeof usedAB);
		memset(usedBC, 0, sizeof usedBC);
		memset(usedAC, 0, sizeof usedAC);
		forn1(i, A) forn1(j, B) forn1(k, C) {
			cout << i << ' ' << j << ' ' << k << endl;
			usedAB[i][j]++;
			usedBC[j][k]++;
			usedAC[i][k]++;
		}

		forn(i, N) forn(j, N) {
			assert(usedAB[i][j] <= K && usedBC[i][j] <= K && usedAC[i][j] <= K);
		}
		return 0;
	}

	if (A == 3 && B == 3 && C == 3 && K == 2) {
		cout << 17 << endl;
		cout << "1 1 1\n1 1 2 \n1 2 1\n1 2 2\n1 3 3\n2 1 1\n2 1 3\n2 2 2\n2 2 3\n2 3 1\n2 3 2\n3 1 2\n3 1 3\n3 2 1\n3 2 3\n3 3 1\n3 3 2" << endl;
		return 0;
	}
	memset(used, false, sizeof used);
	memset(usedAB, 0, sizeof usedAB);
	memset(usedBC, 0, sizeof usedBC);
	memset(usedAC, 0, sizeof usedAC);
	nans.clear();
	a = A, b = B, c = C;
	startT = clock();
	brute(0, vector<pair<pt, int> >());
	//cerr << "ABC nans == " << A * B * C << ' ' << sz(nans) << endl;
	if (A * B * C > sz(nans)) {
		//puts("BAD");
		//assert(false);
	}
	cout << sz(nans) << endl;
	memset(used, false, sizeof used);
	memset(usedAB, 0, sizeof usedAB);
	memset(usedBC, 0, sizeof usedBC);
	memset(usedAC, 0, sizeof usedAC);

	forn(i, sz(nans)) {
		int ii = nans[i].x.x + 1, jj = nans[i].x.y + 1, kk = nans[i].y + 1;
		usedAB[ii][jj]++;
		usedBC[jj][kk]++;
		usedAC[ii][kk]++;
		cout << nans[i].x.x + 1 << ' ' << nans[i].x.y + 1 << ' ' << nans[i].y + 1 << endl;
	}

	forn(i, N) forn(j, N) {
		assert(usedAB[i][j] <= K && usedBC[i][j] <= K && usedAC[i][j] <= K);
	}
	return sz(nans);
}

inline void solve() {
	naive();
	return;
}

int main() {
#ifdef _DEBUG
	assert(freopen("input.txt", "rt", stdin));
	assert(freopen("output.txt", "wt", stdout));
#endif

	cout << setprecision(10) << fixed;
	cerr << setprecision(10) << fixed;

	//srand(int(time(NULL)));

	int T = 1;
	assert(scanf("%d", &T) == 1);

	forn(i, T) {
		cerr << "TEST == " << i + 1 << endl;
		cout << "Case #" << i + 1 << ": ";
		assert(read());
		solve();
	}

#ifdef _DEBUG
	cerr << "TIME == " << clock() << " ms" << endl;
#endif
	return 0;
}