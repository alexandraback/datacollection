#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <memory.h>

#include <iostream>
#include <fstream>
#include <sstream>

#ifdef _WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 nextInt64() { int64 x; if (scanf(LLD, &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 1000;
const int MAXB = 100;

int64 A, B, K, d[MAXN][2][2][2];
string a, b, k;

string printBits(int64 x) {
	string ans = "";
	forn(i, MAXB) {
		ans += char('0' + (x % 2));
		x /= 2;
	}

	reverse(all(ans));
	return ans;
}

int calc(int cur, int ls, int or) {
	if (ls == 0 && cur > or) return -1;
	return (cur < or || ls == 1) ? 1 : 0;
}

int64 solve(int v, int la, int lb, int lk) {
	if (v == MAXB) return (la & lb & lk);
	int64 &ans = d[v][la][lb][lk];
	if (ans != -1) return ans;

	ans = 0;
	forn(aa, 2) {
		forn(bb, 2) {
			int nla = calc(aa, la, a[v] - '0');
			int nlb = calc(bb, lb, b[v] - '0');
			int nlk = calc(aa & bb, lk, k[v] - '0');
			if (nla == -1 || nlb == -1 || nlk == -1) continue;
			ans += solve(v + 1, nla, nlb, nlk);
		}
	}

	return ans;
}

int64 stupid() {
	int64 ans = 0;
	forn(i, A) {
		forn(j, B) {
			if ((i & j) < K) {
				ans++;
			}
		}
	}

	return ans;
}

void solve(bool skipThisTest) {
    if (true) {
        cerr << "\tinput mode: read test." << endl;
        A = nextInt64(); a = printBits(A);
        B = nextInt64(); b = printBits(B);
        K = nextInt64(); k = printBits(K);
        if (skipThisTest) return;
    } else {
        cerr << "\tinput mode: generated test." << endl;
        A = rand() % 10000; a = printBits(A);
		B = rand() % (2000000000 / A); b = printBits(B);
		K = rand() % max(A, B);	k = printBits(K);
    }

	memset(d, 255, sizeof d);
    int64 ans = solve(0, 0, 0, 0);

	cout << ans << endl;
    cerr << "\tclever answer is '" << ans << "'." << endl;
    if (A * B < int64(10E9)) {
        int64 stupidAnswer = stupid();
        cerr << "\tstupid answer is '" << stupidAnswer << "'." << endl;
        assert(ans == stupidAnswer);
    }
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#else
#endif

    int minTest = 1, maxTest = INF;
    if (argc == 3) {
        minTest = atoi(argv[1]);
        maxTest = atoi(argv[2]);
    }

    cout.precision(10);
    cout.setf(ios::fixed);

    cerr.precision(10);
    cerr.setf(ios::fixed);

    srand((unsigned int)time(0));
    int tests = nextInt();
    clock_t totalStartTime = clock();
    for(int test = 1; test <= tests; test++) {
        clock_t startTime = clock();
        cerr << "Case #" << test << endl;
        bool skipThisTest = (test < minTest || test > maxTest);
        if (!skipThisTest) cout << "Case #" << test << ": ";
        solve(skipThisTest);

        char formattedTime[100];
        clock_t time = clock() - startTime;
        sprintf(formattedTime, "%d.%03d", int(time / CLOCKS_PER_SEC), int(time % CLOCKS_PER_SEC));
        cerr << "time for test is " << formattedTime << " s." << endl << endl;
    }

    char formattedTime[100];
    clock_t totalTime = clock() - totalStartTime;
    sprintf(formattedTime, "%d.%03d", int(totalTime / CLOCKS_PER_SEC), int(totalTime % CLOCKS_PER_SEC));
    cerr << string(20, '=') << endl;
    cerr << "TOTAL TIME IS " << formattedTime << " s." << endl;

    return 0;
}
