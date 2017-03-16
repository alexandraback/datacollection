//{ ************[       Template       ]************
using namespace std;
//{ ************[      C headers       ]************
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ ************[     C++ headers      ]************
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
//}
//{ ************[        Loops         ]************
#define forab(i, a, b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i, n) forab (i, 0, (n) - 1)
#define For(i, n) forab (i, 1, n)
#define rofba(i, a, b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i, n) rofba (i, 0, (n) - 1)
#define rof(i, n) rofba (i, 1, n)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ ************[   Floating points    ]************
#define EPS DBL_EPSILON
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}
//}

int main () {
#ifdef IOfromFile
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    For (cs, t) {
        int x, y;
        cin >> x >> y;
        cout << "Case #" << cs << ": ";
        char xa = 'W', xb = 'E';
        if (x < 0) swap (xa, xb);
        x = abs (x);
        rep (i, x) cout << xa << xb;

        char ya = 'S', yb = 'N';
        if (y < 0) swap (ya, yb);
        y = abs (y);
        rep (i, y) cout << ya << yb;
        cout << endl;
    }
	return 0;
}
