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
template<typename T1, typename T2> std::ostream& operator<<(std::ostream &out, const pair<T1, T2>& a) { out << "(" << a.first << ", " << a.second << ")"; return out; }
template<typename T> std::ostream& operator<<(std::ostream &out, const vector<T>& a) { out << "[" << a.size() << "]{ "; forn(i, a.size()) { out << a[i] << " "; } out << "}"; return out; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 nextInt64() { int64 x; if (scanf(LLD, &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E19;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

string s1, s2;

using TResult = pair<int64, pair<string, string>>;

TResult equalGame(int p, string a1, string a2) {
    if (p == int(s1.size())) {
        forn(i, p) {
            assert(isdigit(a1[i]));
            assert(isdigit(a2[i]));
        }
        int64 v1, v2;
        stringstream st1, st2;
        st1 << a1; st1 >> v1;
        st2 << a2; st2 >> v2;
        return mp(Abs(v1 - v2), mp(a1, a2));
    }

    if (a1[p] == '?' || a2[p] == '?' || a1[p] == a2[p]) {
        cerr << "t2" << endl;
        throw;
    }

    char c1 = '0', c2 = '9';
    if (a1[p] < a2[p]) {
        swap(c1, c2);
    }

    forn(i, a1.size()) {
        if (i <= p) continue;
        if (a1[i] == '?') {
            a1[i] = c1;
        }
        if (a2[i] == '?') {
            a2[i] = c2;
        }
    }

    return equalGame(int(a1.size()), a1, a2);
}

TResult cGame(int p, string a1, string a2) {
    assert(a1.substr(0, p) == a2.substr(0, p));
    if (p == (int)a1.size()) {
        return equalGame(p, a1, a2);
    }

    if (a1[p] != '?' && a2[p] != '?') {
        if (a1[p] == a2[p]) {
            return cGame(p + 1, a1, a2);
        } else {
            return equalGame(p, a1, a2);
        }
    }

    if (a1[p] == '?' && a2[p] == '?') {
        a1[p] = '0'; a2[p] = '0';
        TResult result = cGame(p + 1, a1, a2);

        a1[p] = '1'; a2[p] = '0';
        result = min(result, equalGame(p, a1, a2));

        a1[p] = '0'; a2[p] = '1';
        result = min(result, equalGame(p, a1, a2));
        return result;
    }

    if (a1[p] == '?' && a2[p] != '?') {
        a1[p] = a2[p];
        TResult result = cGame(p + 1, a1, a2);

        if (a2[p] != '0') {
            a1[p] = a2[p] - 1;
            result = min(result, equalGame(p, a1, a2));
        }

        if (a2[p] != '9') {
            a1[p] = a2[p] + 1;
            result = min(result, equalGame(p, a1, a2));
        }
        return result;
    }


    if (a2[p] == '?' && a1[p] != '?') {
        a2[p] = a1[p];
        TResult result = cGame(p + 1, a1, a2);

        if (a1[p] != '0') {
            a2[p] = a1[p] - 1;
            result = min(result, equalGame(p, a1, a2));
        }

        if (a1[p] != '9') {
            a2[p] = a1[p] + 1;
            result = min(result, equalGame(p, a1, a2));
        }
        return result;
    }

    cerr << "t1" << endl;
    throw;
}

TResult st(int p, string s1, string s2) {
    if (p == int(s1.size())) return equalGame(p, s1, s2);

    if (s1[p] == '?') {
        TResult result = mp(INF64, mp("", ""));
        forn(i, 10) {
            s1[p] = '0' + i;
            result = min(result, st(p, s1, s2));
        }
        return result;
    }

    if (s2[p] == '?') {
        TResult result = mp(INF64, mp("", ""));
        forn(i, 10) {
            s2[p] = '0' + i;
            result = min(result, st(p, s1, s2));
        }
        return result;
    }

    return st(p + 1, s1, s2);
}

pair<string, string> stupid() {
    TResult answer = st(0, s1, s2);
    return answer.second;
}

void solve(bool skipThisTest) {
    if (true) {
        cerr << "\tinput mode: read test." << endl;
        cin >> s1 >> s2;
        if (skipThisTest) return;
    } else {
        cerr << "\tinput mode: generated test." << endl;
        // generate test.
    }

    TResult answer = cGame(0, s1, s2);
    pair<string, string> ans = answer.second;
    cout << ans.first << " " << ans.second << endl;

    cerr << "\tclever answer is '" << ans << "'." << endl;
    if (s1.size() <= 4) {
        pair<string, string> stupidAnswer = stupid();
        cerr << "\tstupid answer is '" << stupidAnswer << "'." << endl;
        assert(ans == stupidAnswer);
    }
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
