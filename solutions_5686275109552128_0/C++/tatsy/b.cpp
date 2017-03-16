#include <iostream>
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

#define REP(i,n) for(int i=0; i<n; i++)
#define REPA(i,s,e) for(int i=s; i<=e; i++)
#define REPD(i,s,e) for(int i=s; i>=e; i--)
#define SIZ(a) (Integer)(a).size()
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

int D;
int P[1011];

void solve() {
    int ma = 0;
    REP(i,D) ma = max(ma, P[i]);

    int ans = ma;
    for (int i = 1; i < ma; i++) {
        int val = i;
        for (int j = 0; j < D; j++) {
            val += (P[j] + i - 1) / i - 1;
        }
        ans = min(ans, val);
    }
    printf("%d\n", ans);
}

void coding() {
    int T;
    cin >> T;
    REPA(t,1,T) {
        cin >> D;
        REP(d,D) cin >> P[d];
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
    freopen("../input/B-small.out", "w", stdout);
#elif _LOCAL_TEST == 2
	freopen("../input/A-large.in", "r", stdin);
    freopen("../input/A-large.out", "w", stdout);
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
