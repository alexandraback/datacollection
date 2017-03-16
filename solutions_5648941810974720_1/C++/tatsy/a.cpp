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

string digits[10] = { "ZERO", "TWO", "SIX", "EIGHT", "THREE", "FOUR", "FIVE", "SEVEN", "ONE", "NINE" };
char key[10] = { 'Z', 'W', 'X', 'G', 'H', 'R', 'F', 'V', 'O', 'I' };
int num[10] = { 0, 2, 6, 8, 3, 4, 5, 7, 1, 9 };

int hist[256];
int ans[10];

void solve() {
    string S;
    cin >> S;

    memset(hist, 0, sizeof(hist));
    for (char c : S) {
        hist[c] += 1;
    }

    for (int i = 0; i < 10; i++) {
        int n = hist[key[i]];
        ans[num[i]] = n;
        for (char c : digits[i]) {
            hist[c] -= n;            
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < ans[i]; j++) {
            printf("%d", i);
        }
    }
    printf("\n");
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
    freopen("a.in", "r", stdin);
#elif _LOCAL_TEST == 1
    freopen("../input/A-small-attempt1.in", "r", stdin);
    freopen("../output/A-small.out", "w", stdout);
#elif _LOCAL_TEST == 2
    freopen("../input/A-large.in", "r", stdin);
    freopen("../output/A-large.out", "w", stdout);
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
