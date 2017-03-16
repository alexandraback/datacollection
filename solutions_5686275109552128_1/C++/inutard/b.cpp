#include <bits/stdtr1c++.h>

using namespace std;

int memo[1005][1005];
int dp(int a, int b) {
    if (a <= b) return 0;
    if (memo[a][b] != -1) return memo[a][b];
    
    int ans = 10000000;
    for (int k = 1; k < a; k++) {
        ans = min(ans, dp(k, b) + dp(a-k, b) + 1);
    }
    return memo[a][b] = ans;
}

int a[1005];
int main() {
    ios::sync_with_stdio(0);
    
    memset(memo, -1, sizeof memo);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        int d; cin >> d;
        for (int i = 0; i < d; i++) {
            cin >> a[i];
        }
        
        int ans = 10000000;
        for (int i = 1; i <= 1005; i++) {
            int s = 0;
            for (int j = 0; j < d; j++) {
                s += dp(a[j], i);
            }
            ans = min(ans, s+i);
        }
        cout << "Case #" << ca << ": " << ans << endl;
    }
	return 0;
}