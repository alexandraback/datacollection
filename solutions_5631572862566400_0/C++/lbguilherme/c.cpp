#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int bff[n];
    vector<int> kids(n);
    for (int i = 0; i < n; ++i) {
        kids[i] = i;
        cin >> bff[i];
        bff[i] -= 1;
    }
    int best = 1;
    do {
        for (int sz = best + 1; sz <= n; ++sz) {
            bool valid = true;
            for (int i = 0; i < sz; ++i) {
                int b = bff[kids[i]];
                if (kids[(i + 1) % sz] != b && kids[(sz + i - 1) % sz] != b) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                best = max(best, sz);
            }
        }
    } while (next_permutation(kids.begin(), kids.end()));
    cout << best << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
    }
}
