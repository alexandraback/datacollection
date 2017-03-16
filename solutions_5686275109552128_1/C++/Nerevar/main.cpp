#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string.h>
#include <queue>
#include <cstdio>
#include <cassert>
#include <deque>
#include <stack>
#include <utility>
#include <numeric>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define forv(i, v) forn(i, v.size())

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
vector<int> p;

bool can(int s, int t) {
    int ts = t - s;
    forn(i, n) {
        s -= (p[i] - 1) / ts;
    }
    return s >= 0;
}

bool can(int t) {
    for (int s = 0; s < t; s++) {
        if (can(s, t)) return true;
    }
    return false;
}

void solveCase(int tc) {
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    cin >> n;
    p = vector<int>(n);
    forn(i, n) cin >> p[i];
    int lf = 1, rg = 1000;
    while (rg - lf > 1) {
        int mid = (lf + rg) / 2;
        if (can(mid)) {
            rg = mid;
        } else {
            lf = mid + 1;
        }
    }
    for (int t = lf; t <= rg; t++) {
        if (can(t)) {
            cout << t << endl;
            return;
        }
    }
    throw;
}

int main() {
#ifdef NEREVAR_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc; cin >> tc;
    forn(it, tc) solveCase(it + 1);
    return 0;
}
