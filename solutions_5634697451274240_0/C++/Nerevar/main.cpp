#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>

typedef long long ll;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())

using namespace std;

void solveCase(int tc) {
    printf("Case #%d: ", tc);
    cerr << tc << endl;
    string s;
    cin >> s;
    s += '+';
    int ans = 0;
    for (int i = 0; i < (int)s.size() - 1; i++) {
        if (s[i] != s[i + 1]) ans++;
    }
    cout << ans << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc; cin >> tc;
    forn(it, tc) solveCase(it + 1);
    return 0;
}
