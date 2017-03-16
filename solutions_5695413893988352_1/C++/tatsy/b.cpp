#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <list>
#include <stack>
#include <tuple>
#include <utility>
#include <complex>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <typeinfo>
using namespace std;

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

#define REP(i,n) for(int i=0; i<(n); i++)
#define REPA(i,s,e) for(int i=(s); i<=(e); i++)
#define REPD(i,s,e) for(int i=(s); i>=(e); i--)
#define ALL(a) (a).begin(), (a).end()

#define PRT(a) cerr << #a << " = " << (a) << endl
#define PRT2(a, b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << endl
#define PRT3(a, b, c) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << ", " << #c << " = " << (c) <<  endl
template <class Ty> void print_all(Ty b, Ty e) {
    cout << "[ ";
    for(Ty p=b; p!=e; ++p) {
        cout << (*p) << ", ";
    }
    cout << " ]" << endl;
}

// -----------------------------------------------------------------------------
// Code starts 
// -----------------------------------------------------------------------------

int N;
string S, T;

enum { EQ, LE, GT };

void solve() {
    cin >> S >> T;
    N = S.length();

    bool ok = true;
    bool swapped = false;
    REP(i, N) {
        if (ok) {
            if (S[i] == '?' && T[i] == '?') {
                S[i] = '0';
                T[i] = '0';
            } else if (S[i] == '?') {
                S[i] = T[i];
            } else if (T[i] == '?') {
                T[i] = S[i];
            } else {
                if (S[i] != T[i]) {
                    ok = false;
                    if (S[i] < T[i]) {
                        swap(S, T);
                        swapped = !swapped;
                    }
                }
            }
        } else {
            if (S[i] == '?' && T[i] == '?') {
                S[i] = '0';
                T[i] = '9';
            } else if (S[i] == '?') {
                if (T[i] == '0') {
                    S[i] = '0';
                    ok = true;
                }
                else {
                    S[i] = T[i] - 1;
                }
            } else if (T[i] == '?') {
                if (S[i] == '9') {
                    T[i] = '9';
                    ok = true;
                }
                else {
                    T[i] = S[i] + 1;
                }
            } else {
                if (S[i] == T[i]) ok = true;
                else if (S[i] < T[i]) {
                    swap(S, T);
                    swapped = !swapped;
                }
            }
        }
    }

    if (swapped) {
        swap(S, T);
    }

    cout << S << " " << T << endl;
}

// -----------------------------------------------------------------------------
// Code ends 
// -----------------------------------------------------------------------------

void coding() {
    int T;
    cin >> T;
    REPA(t,1,T) {
        fprintf(stderr, "%3d / %d\n", t, T);
        printf("Case #%d: ", t);
        solve();
    }
}

#define _LOCAL_TEST 2

int main() {
#if _LOCAL_TEST == 0
    clock_t startTime = clock();
    freopen("b.in", "r", stdin);
#elif _LOCAL_TEST == 1
    freopen("../input/B-small-attempt0.in", "r", stdin);
    freopen("../output/B-small1.out", "w", stdout);
#elif _LOCAL_TEST == 2
    freopen("../input/B-large.in", "r", stdin);
    freopen("../output/B-large.out", "w", stdout);
#endif

    coding();

#if _LOCAL_TEST == 0
    clock_t elapsedTime = clock() - startTime;
    cerr << endl;
    cerr << (elapsedTime / 1000.0) << " sec elapsed." << endl;
    cerr << "This is local test" << endl;
    cerr << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif

}
