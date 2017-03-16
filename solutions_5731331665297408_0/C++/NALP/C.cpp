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

const int MAXN = 110;

bool g[MAXN][MAXN], inTree[MAXN], inSt[MAXN], used[MAXN], ans[MAXN];
string a[MAXN];
int n, m;

bool get(int v) {
	if (inTree[v]) return inSt[v];
	if (used[v]) return ans[v];

	ans[v] = false;
	used[v] = true;
	forn(u, n) {
		if (g[v][u] && get(u)) {
			ans[v] = true;
		}
	}

	return ans[v];
}

bool checkBad(const vector<int> &a) {
	memset(inSt, 0, sizeof inSt);
	forn(i, a.size()) inSt[a[i]] = true;
	forn(i, n) {
		memset(used, 0, sizeof used);
		if (!inTree[i] && !get(i)) {
			return false;
		}
	}

	return true;
}

vector<int> check(vector<int> a, int v) {
	while (!a.empty()) {
		if (g[a.back()][v] && checkBad(a)) return a;
		a.pop_back();
	}

	return a;
}

string stupid() {
    return "";
}

void solve(bool skipThisTest) {
    if (true) {
        cerr << "\tinput mode: read test." << endl;
        n = nextInt();
		m = nextInt();
		forn(i, n) {
			cin >> a[i];
		}

		memset(g, 0, sizeof g);
		forn(i, m) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			g[v][u] = g[u][v] = true;
		}
        if (skipThisTest) return;
    } else {
        cerr << "\tinput mode: generated test." << endl;
        // generate test.
    }

    string ans = "";
	map<string, int> st;
	forn(i, n) {
		st[a[i]] = i;
	}

	vector<int> s;
	memset(inTree, 0, sizeof inTree);
	while (!st.empty()) {
		string sel = "";
		for(map<string, int>::iterator i = st.begin(); i != st.end(); i++) {
			vector<int> cur = check(s, i->second);
			if (!cur.empty() || s.empty()) {
				s = cur;
				s.pb(i->second);
				inTree[s.back()] = true;
				ans += i->first;
				sel = i->first;
				break;
			}
		}
		
		if (sel == "") {
			throw;
		}
		st.erase(sel);
	}

	cout << ans << endl;
	cerr << "\tclever answer is '" << ans << "'." << endl;
    if (false) {
        string stupidAnswer = stupid();
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
