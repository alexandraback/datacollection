#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <iomanip>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    std::ios_base::sync_with_stdio(false);
    int tests_count;
    cin >> tests_count;
    for (int test_index = 0; test_index < tests_count; ++test_index) {
        ll n, m;
        cin >> n >> m;
        if ((ll(1) << (n - 2)) < m) {
            cout << "Case #" << test_index + 1 << ": IMPOSSIBLE\n";
            continue;
        }
        vector< vector<int> > matr(n);
        for (int i = 0; i < n; ++i) {
            matr[i] = vector<int>(n, 0);
        }
        for (int i = 1; i + 1 < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                matr[i][j] = 1;
            }
        }
        int cnt = 0;
        --m;
        while (m) {
            ++cnt;
            if (m & 1) {
                matr[0][n - cnt - 1] = 1;
            }
            m >>= 1;
        }
        matr[0][n - 1] = 1;
        cout << "Case #" << test_index + 1 << ": POSSIBLE\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matr[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
