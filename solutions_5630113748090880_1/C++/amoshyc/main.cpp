#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cout << "Case #" << tc << ": ";

        int N; cin >> N;
        vector<int> cnt(2500 + 1, 0);
        for (int i = 0; i < 2 * N - 1; i++) {
            for (int j = 0; j < N; j++) {
                int inp; cin >> inp;
                cnt[inp]++;
            }
        }

        vector<int> ans;
        for (int i = 0; i <= 2500; i++) {
            if (cnt[i] % 2 != 0) {
                ans.push_back(i);
            }
        }

        for (size_t i = 0; i < ans.size(); i++) {
            if (i != 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}
