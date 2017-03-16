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

int ans = 0;
int l = 0;
string C;
string ansS, ansT;

int num(const string& s) {
    int ret = 0;
    for (int i = 0; i < s.length(); i++) {
        ret = ret * 10 + s[i];
    }
    return ret;
}

void dfs() {
    bool finish = true;
    for (int k = 0; k < C.length(); k++) {
        if (C[k] == '?') {
            finish = false;
            for (int i = 0; i < 10; i++) {
                C[k] = '0' + i;
                dfs();
            }
            C[k] = '?';
        }
    }

    if (finish) {
        string S = C.substr(0, l);
        string T = C.substr(l);
        int diff = abs(num(S) - num(T));
        if (ans > diff) {
            ans = diff;
            ansS = S;
            ansT = T;
        }
    }
}

void solve() {
    string S, T;
    cin >> S >> T;

    l = S.length();
    C = S + T;
    ans = 100000;
    dfs();
    cout << ansS << " " << ansT << endl;
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

#define _LOCAL_TEST 1

int main() {
#if _LOCAL_TEST == 0
    clock_t startTime = clock();
    freopen("b.in", "r", stdin);
#elif _LOCAL_TEST == 1
    freopen("../input/B-small-attempt0.in", "r", stdin);
    freopen("../output/B-small0.out", "w", stdout);
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
