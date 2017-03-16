#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; ++testCase) {
        int n;
        cin >> n;
        vector<pair<string, string>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        int ans = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            bitset<16> b(mask);
            set<string> fst;
            set<string> snd;
            int cnt_1 = 0;
            for (int i = 0; i < n; ++i) {
                if (b[i] == 1) {
                    cnt_1++;
                }
            }
            if (cnt_1 < ans) {
                continue;
            }
            for (int i = 0; i < n; ++i) {
                if (b[i] == 0) {
                    fst.insert(a[i].first);
                    snd.insert(a[i].second);
                }
            }
            bool all_ok = true; // as if
            for (int i = 0; i < n; ++i) {
                if (b[i] == 1) {
                    if (fst.find(a[i].first) == fst.end() ||
                        snd.find(a[i].second) == snd.end()) {
                        all_ok = false;
                        break;
                    }
                }
            }
            if (all_ok && cnt_1 > ans) {
                ans = cnt_1;
            }
        }
        cout << "Case #" << testCase << ": " << ans << endl;
    }
    return 0;
}
