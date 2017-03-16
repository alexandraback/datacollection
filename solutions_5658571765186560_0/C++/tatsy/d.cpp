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

bool solve() {
    if (X == 1) return true;

    if (X == 2) {
        return (R % 2 == 0 || C % 2 == 0);
    }

    if (X == 3) {
        return (R % 3 == 0 && C != 1) || (C % 3 == 0 && R != 1);
    }

    if (X == 4) {
        return (R == 4 && C == 4) || (R == 4 && C == 3) || (R == 3 && C == 4);
    }
    return false;
}

void coding() {
    int T;
    cin >> T;
    REPA(t,1,T) {
        cin >> X >> R >> C;
        printf("Case #%d: %s\n", t, solve() ? "GABRIEL" : "RICHARD");
    } 
}

#define _LOCAL_TEST 1

int main() {
#if _LOCAL_TEST == 0
	clock_t startTime = clock();
	freopen("d.in", "r", stdin);
#elif _LOCAL_TEST == 1
	freopen("../input/D-small-attempt1.in", "r", stdin);
    freopen("../input/D-small.out", "w", stdout);
#elif _LOCAL_TEST == 2
	freopen("../input/B-large.in", "r", stdin);
    freopen("../input/B-large.out", "w", stdout);
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
