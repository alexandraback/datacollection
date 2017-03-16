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

const int kM = 1 << 27;

int J, P, S, K;

struct Node {
    int jc, pc, sc;
};

vector<Node> a;

const int kN = 3;

int abm[kN][kN], acm[kN][kN], bcm[kN][kN];

vector< vector<int> > cache_res(11);

int main() {
    std::ios_base::sync_with_stdio(false);
    int tests_count;
    cin >> tests_count;
    for (int test_index = 0; test_index < tests_count; ++test_index) {
        a.clear();
        cin >> J >> P >> S >> K;
        bool max_test = J == 3 && P == 3 && S == 3;
        if (J == 3 && P == 3 && S == 3 && !cache_res[K].empty()) {
        vector<int> inds = cache_res[K];
        cout << "Case #" << test_index + 1 << ": " << inds.size() << "\n";
        for (int i = 0; i < inds.size(); ++i) {
            Node node = a[inds[i]];
            cout << node.jc + 1 << ' ' << node.pc + 1 << ' ' << node.sc + 1 << "\n";
        }
        continue;
        }
        for (int j = 0; j < J; ++j) {
            for (int p = 0; p < P; ++p) {
                for (int s = 0; s < S; ++s) {
                    a.push_back({j, p, s});
                }
            }
        }
        int n = a.size();
        vector<int> curr(kN);
        int best_res = -1;
        vector<int> inds = {};
        for (int mask = 0; mask < (1 << n); ++mask) {
            curr.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    curr.push_back(i);
                }
            }
            if (curr.size() <= inds.size()) {
                continue;
            }
            int ab = 0, ac = 0, bc = 0;
            memset(abm, 0, sizeof(abm));
            memset(acm, 0, sizeof(acm));
            memset(bcm, 0, sizeof(bcm));
            bool bad = false;
            for (int i = 0; i < curr.size(); ++i) {
                Node node = a[curr[i]];
                int jc = node.jc, pc = node.pc, sc = node.sc;
                int mx = max(max(++abm[jc][pc], ++acm[jc][sc]), ++bcm[pc][sc]);
                if (mx > K) {
                    bad = true;
                    break;
                }
            }
            if (!bad && curr.size() > inds.size()) {
                inds = curr;
            }
        }
        if (max_test) {
            cache_res[K] = inds;
        }
        cout << "Case #" << test_index + 1 << ": " << inds.size() << "\n";
        for (int i = 0; i < inds.size(); ++i) {
            Node node = a[inds[i]];
            cout << node.jc + 1 << ' ' << node.pc + 1 << ' ' << node.sc + 1 << "\n";
        }
        // cout << "\n";
    }
    return 0;
}
