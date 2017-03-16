#include <bits/stdc++.h>
using namespace std;

int TT;
int dp[3000];

int main() {
    cin >> TT;
    for(int T = 1; T <= TT; ++T) {
        int n;
        cin >> n;
        fill(dp, dp + 3000, 0);
        for(int i = 0; i < 2 * n - 1; ++i) {
            for(int j = 0; j < n; ++j) {
                int z;
                cin >> z;
                dp[z]++;
            }
        }
        vector<int> ans;
        for(int i = 0; i < 3000; ++i) {
            if(dp[i] % 2) {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size() != n) cerr << "WRONG!!!" << endl;

        cout << "Case #" << T << ": ";
        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i];
            if(i != ans.size()-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
