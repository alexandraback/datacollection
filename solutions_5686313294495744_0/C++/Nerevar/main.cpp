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
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    forn(i, n) cin >> a[i] >> b[i];
    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        set<string> sa, sb;
        int size = 0;
        forn(i, n) {
            if (mask & (1 << i)) {
                size++;
            } else {
                sa.insert(a[i]);
                sb.insert(b[i]);
            }
        }
        bool ok = true;
        forn(i, n) {
            if (mask & (1 << i)) {
                if (!sa.count(a[i]) || !sb.count(b[i])) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            ans = max(ans, size);
        }
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
