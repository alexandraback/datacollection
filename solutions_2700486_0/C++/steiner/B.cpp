#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<vector<long double> > c;

int64 _abs(int64 x) {
    if (x < 0)
        return -x;
    return x;
}

void solve() {
    int64 n, x, y;
    cin >> n >> x >> y;
    int64 level = 0;
    while (n >= 4 * level + 1) {
        n -= 4 * level + 1;
        ++level;
    }
    if (x + y < 2 * level) {
        cout << "1" << endl;
        return;
    }
    if (x + y > 2 * level) {
        cout << "0" << endl;
        return;
    }
    if (y == 2 * level) {
        cout << "0" << endl;
        return;
    }
    if (y == 2 * level - 1 && n == 4 * level) {
        cout << "1" << endl;
        return;
    }
    long double ans = 0;
    if (y == 2 * level - 1) {
        for (int64 i = 2 * level; i <= n; ++i)
            ans += c[i - 1][2 * level - 1];
        ans *= 0.5;
        printf("%.10lf\n", (double) ans);
        return;
    }
    for (int64 i = y + 1; i <= 2 * level; ++i)
         if (n >= i)
             ans += c[n][i];
    printf("%.10lf\n", (double) ans); 
}

int main() {
    c.assign(21000, vector<long double> (21000, 0));
    c[0][0] = 1.0;
    for (int64 i = 1; i < 21000; ++i) {
        c[i][0] = 0.5 * c[i - 1][0];
        for (int64 j = 1; j < i; ++j)
            c[i][j] = 0.5 * (c[i - 1][j - 1] + c[i - 1][j]);
        c[i][i] = 0.5 * c[i - 1][i - 1];
        
    }
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
