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

string str;
vector <long long> v;
vector <long long> :: iterator temp;

inline bool check (char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    return false;
}

int main () {
#ifdef IOfromFile
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
    long long t;
    cin >> t;
    For (cs, t) {
        long long n, ans = 0, cnt = 0;
        cin >> str >> n;
        long long len = str.size ();
        v.clear ();

        rep (i, len) {
            if (check (str [i])) {
                cnt = 0;
                continue;
            }
            ++cnt;
            if (cnt == n) {
                v.push_back (i);
                --cnt;
            }
        }

        rep (i, len) {
            long long idx = i + n - 1;
            temp = lower_bound (v.begin (), v.end (), idx);
            if (temp == v.end ()) continue;
            long long pos = *temp;
            ans += (len - pos);
        }

        cout << "Case #" << cs << ": " << ans << endl;
    }
	return 0;
}
