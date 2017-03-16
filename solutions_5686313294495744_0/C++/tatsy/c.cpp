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
int dp[20][1 << 16];
string F[20];
string S[20];

void dfs(int d, int bits, int fakes) {
    if (dp[d][bits] >= fakes) {
        return;
    }

    dp[d][bits] = fakes;

    if (d == N) {
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (((bits >> i) & 0x01) == 0) {
            int nbits = bits | (1 << i);

            bool m1 = false, m2 = false;
            for (int j = 0; j < N; j++) {
                if (((bits >> j) & 0x01) != 0) {
                    if (F[j] == F[i]) m1 = true;
                    if (S[j] == S[i]) m2 = true;
                }
            }

            int nfakes = dp[d][bits];
            if (m1 && m2) {
                nfakes += 1;
            }
            dfs(d + 1, nbits, nfakes);
        }
    }
}

void solve() {
    cin >> N;
    REP(i, N) {
        cin >> F[i] >> S[i];
    }

    memset(dp, -1, sizeof(dp));
    dfs(0, 0, 0);

    int bits = (1 << N ) - 1;
    printf("%d\n", dp[N][bits]);
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
    freopen("c.in", "r", stdin);
#elif _LOCAL_TEST == 1
    freopen("../input/C-small-attempt0.in", "r", stdin);
    freopen("../output/C-small_test.out", "w", stdout);
#elif _LOCAL_TEST == 2
    freopen("../input/C-large.in", "r", stdin);
    freopen("../output/C-large.out", "w", stdout);
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
