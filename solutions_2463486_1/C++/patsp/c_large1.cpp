#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <complex>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,start,end) for (int var=(start); var<=(end); ++var)
#define FORD(var,start,end) for (int var=(start); var>=(end); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector< vector<int> > VVI;
typedef vector< vector<bool> > VVB;

inline static bool isPalindrome(LL x) {
    LL revX = 0;
    LL tmpX = x;
    while (tmpX > 0) {
        revX = revX * 10 + (tmpX % 10);
        tmpX /= 10;
    }

    // cout << x << ", " << revX << "\n";

    return x == revX;
}

int main() {
    int nTests = 0;
    cin >> nTests;

    // vector<int> good(1001, 0);
    // FOR (i, 1, 1000) {
    //     if (i*i <= 1000) {
    //         good.at(i*i) = isPalindrome(i) && isPalindrome(i*i);
    //     }
    // }

    // FOR (i, 1, 1000) {
    //     good.at(i) += good.at(i-1);
    // }

    vector<LL> sortedFairAndSquare;
    for (LL i = 1; i <= 10000000; ++i) {
        if (isPalindrome(i) && isPalindrome(i*i)) {
            // cout << i << "\n";
            // cout << i*i << "\n";
            sortedFairAndSquare.PB(i*i);
        }
    }

    FOR (test, 1, nTests) {
        LL a = 0; LL b = 0; cin >> a >> b;

        cout << "Case #" << test << ": ";
        //cout << good.at(b) - good.at(a-1) << "\n";

        vector<LL>::iterator left = lower_bound(ALL(sortedFairAndSquare), a);
        vector<LL>::iterator right = upper_bound(ALL(sortedFairAndSquare), b);
        cout << distance(left, right) << "\n";
    }

    return 0;
}
