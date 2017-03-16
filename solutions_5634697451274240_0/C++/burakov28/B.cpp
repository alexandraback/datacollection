#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;


int main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        cout << "Case #" << q + 1 << ": ";

        string s;
        cin >> s;

        vector < int > dp[2];
        dp[0].resize(s.size());
        dp[1].resize(s.size());

        if (s[0] == '-') {
            dp[0][0] = 0;
            dp[1][0] = 1;
        }
        else {
            dp[0][0] = 1;
            dp[1][0] = 0;
        }
        for (int i = 1; i < (int) s.size(); ++i) {
            if (s[i] == '-') {
                dp[0][i] = dp[0][i - 1];
                dp[1][i] = dp[0][i - 1] + 1;
            }
            else {
                dp[0][i] = dp[1][i - 1] + 1;
                dp[1][i] = dp[1][i - 1];
            }
        }
        cout << dp[1][s.size() - 1] << endl;
    }
    return 0;
}