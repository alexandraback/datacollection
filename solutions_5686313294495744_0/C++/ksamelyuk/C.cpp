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
        int n;
        cin >> n;
        vector<string> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        int best = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            set<string> aa, bb;
            int curr = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    aa.insert(a[i]);
                    bb.insert(b[i]);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    continue;
                }
                if (aa.find(a[i]) != aa.end() && bb.find(b[i]) != bb.end()) {
                    ++curr;
                }
            }
            best = max(best, curr);
        }
        cout << "Case #" << test_index + 1 << ": " << best << "\n";
    }
    return 0;
}
