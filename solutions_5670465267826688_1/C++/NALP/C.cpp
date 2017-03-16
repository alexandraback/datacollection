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

enum ENumbers {
    E_ONE = 1,
    E_I = 2,
    E_J = 3,
    E_K = 4,
    E_NAN = 100000
};

const int Z[5][5] = {
    {E_NAN, E_NAN,  E_NAN, E_NAN,  E_NAN},
    {E_NAN, E_ONE,   E_I,    E_J,    E_K},
    {E_NAN,  E_I, -E_ONE,    E_K,   -E_J},
    {E_NAN,  E_J,   -E_K, -E_ONE,    E_I},
    {E_NAN,  E_K,    E_J,   -E_I, -E_ONE},
};

int sign(int x) {
    return (x < 0) ? -1 : +1;
}

int getEnum(char c) {
    switch (c) {
        case 'i': return E_I;
        case 'j': return E_J;
        case 'k': return E_K;
        default: throw;
    }
}

int mul(int a, int b) {
    int s = sign(a) * sign(b);
    a = abs(a); b = abs(b);
    assert(1 <= a && a <= 4);
    assert(1 <= b && b <= 4);
    return s * Z[a][b];
}

string repeat(const string& s, int k) {
    string ans = "";
    forn(i, k) {
        ans += s;
    }
    return ans;
}

string reverse(string s) {
    reverse(all(s));
    return s;
}

int64 findFirst(const string &s, int value, bool rev) {
    int ans = E_ONE;
    forn(i, s.size()) {
        if (rev) {
            ans = mul(getEnum(s[i]), ans);
        } else {
            ans = mul(ans, getEnum(s[i]));
        }
        if (ans == value) {
            return i + 1;
        }
    }
    return INF64;
}

int getTotal(const string& s) {
    int ans = E_ONE;
    forn(i, s.size()) {
        ans = mul(ans, getEnum(s[i]));
    }
    return ans;
}

void solve(bool skipThisTest) {
    cerr << "\tinput mode: read test." << endl;
    int n = nextInt();
    int64 m = nextInt64();
    string s;
    cin >> s;
    if (skipThisTest) return;

    int64 fsI = findFirst(repeat(s, 4), E_I, false);
    int64 lsK = findFirst(reverse(repeat(s, 4)), E_K, true);
    // assert(getTotal(repeat(s, int(m % 4))) == getTotal(repeat(s, int(m))));
    bool ans = getTotal(repeat(s, int(m % 4))) == -E_ONE && fsI + lsK < n * m;

    cout << (ans ? "YES" : "NO") << endl;
    cerr << "\tclever answer is '" << ans << "'." << endl;
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
    freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
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
