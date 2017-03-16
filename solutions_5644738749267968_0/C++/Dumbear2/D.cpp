/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

int t, n;
double x[1024], y[1024];

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lf", &x[i]);
    for (int i = 0; i < n; ++i)
        scanf("%lf", &y[i]);
    sort(x, x + n);
    sort(y, y + n);
    int s1 = 0, s2 = 0;
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
        if (x[i] > y[l]) {
            ++s1;
            ++l;
        } else {
            --r;
        }
    }
    set<double> s(y, y + n);
    // reverse(x, x + n);
    // random_shuffle(x, x + n);
    for (int i = 0; i < n; ++i) {
        if (s.upper_bound(x[i]) == s.end()) {
            ++s2;
            s.erase(s.begin());
        } else {
            s.erase(s.upper_bound(x[i]));
        }
    }
    printf("Case #%d: %d %d\n", ++t, s1, s2);
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
