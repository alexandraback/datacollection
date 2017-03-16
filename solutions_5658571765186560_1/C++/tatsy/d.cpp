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

int X, R, C;

bool check(int r, int c) {
    if (X == 1) return true;
    if (X == 2) return r % 2 == 0;
    if (X == 3) return r % 3 == 0 && c != 1;
    if (X == 4) {
        return (r % 4 == 0 && c >= 3) || (r >= 4 && r % 2 == 0 && c >= 4 && c % 2 == 0);
    }
    if (X == 5) {
        return (r % 5 == 0 && c >= 3);
    }
    if (X == 6) {
        return (r % 6 == 0 && c >= 4) || (r >= 6 && r % 3 == 0 && c >= 4 && c % 2 == 0);
    }
    return false;
}

bool solve() {
    return check(R, C) || check(C, R);
}

void coding() {
    int T;
    cin >> T;
    REPA(t,1,T) {
        cin >> X >> R >> C;
        printf("Case #%d: %s\n", t, solve() ? "GABRIEL" : "RICHARD");
    } 
}

#define _LOCAL_TEST 2

int main() {
#if _LOCAL_TEST == 0
	clock_t startTime = clock();
	freopen("d.in", "r", stdin);
#elif _LOCAL_TEST == 1
	freopen("../input/D-small-attempt1.in", "r", stdin);
    freopen("../input/D-small1.out", "w", stdout);
#elif _LOCAL_TEST == 2
	freopen("../input/D-large.in", "r", stdin);
    freopen("../input/D-large.out", "w", stdout);
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
