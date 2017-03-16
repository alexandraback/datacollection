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

bool Match(const string& s, int n) {
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        int d = n % 10;
        n /= 10;
        if (s[i] == '?') { continue; }
        if (s[i] - '0' != d) { return false; }
    }
    return n == 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int tests_count;
    cin >> tests_count;
    for (int test_index = 0; test_index < tests_count; ++test_index) {
        string s, t;
        cin >> s >> t;
        int best = 1000 * 1000 * 1000;
        int c_score = -1;
        int j_score = -1;
        for (int i = 0; i < 999; ++i) {
            for (int j = 0; j < 999; ++j) {
                if (!Match(s, i) || !Match(t, j)) {
                    continue;
                }
                if (abs(i - j) < best ||
                    abs(i - j) == best && i < c_score ||
                    abs(i - j) == best && i == c_score && j < j_score) {
                    best = abs(i - j);
                    c_score = i;
                    j_score = j;
                }
            }
        }
        string cs = to_string(c_score);
        string js = to_string(j_score);
        while (cs.size() != s.size()) {
            cs = "0" + cs;
        }
        while (js.size() != t.size()) {
            js = "0" + js;
        }
        cout << "Case #" << test_index + 1 << ": " << cs << ' ' << js << "\n";
    }
    return 0;
}
