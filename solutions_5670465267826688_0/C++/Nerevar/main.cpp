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

const int mul[4][4] = {
    {1, 2, 3, 4},
    {2, -1, 4, -3},
    {3, -4, -1, 2},
    {4, 3, -2, -1}
};

int sign(int x) {
    return x > 0 ? 1 : -1;
}

int doMul(int x, int y) {
    return sign(x) * sign(y) * mul[abs(x) - 1][abs(y) - 1];
}

int encode(char c) {
    if (c == '1') return 1;
    if (c == 'i') return 2;
    if (c == 'j') return 3;
    return 4;
}

void solveCase(int tc) {
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    int len, rep;
    cin >> len >> rep;
    string pattern;
    cin >> pattern;
    string s;
    forn(i, rep) s += pattern;
    int n = s.size();
    vector<int> a(n);
    forn(i, n) a[i] = encode(s[i]);
    vector<int> suffix(n);
    for (int i = 0; i < n; i++) {
        int r = a[i];
        for (int j = i + 1; j < n; j++) r = doMul(r, a[j]);
        suffix[i] = r;
    }
    int r1 = 1;
    for (int i = 0; i < n; i++) {
        r1 = doMul(r1, a[i]);
        if (r1 != 2) continue;
        int r2 = 1;
        for (int j = i + 1; j < n - 1; j++) {
            r2 = doMul(r2, a[j]);
            if (r2 == 3 && suffix[j + 1] == 4) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
