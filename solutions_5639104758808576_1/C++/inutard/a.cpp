#include <bits/stdtr1c++.h>

using namespace std;

int sum[1005];
int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        int n; cin >> n;
        string s; cin >> s;
        
        for (int i = 0; i < n+1; i++) {
            sum[i] = s[i]-'0';
        }
        
        int ans = 0;
        for (int i = 1; i < n+1; i++) {
            sum[i] += sum[i-1];
            ans = max(ans, i-sum[i-1]);
        }
        cout << "Case #" << ca << ": " << ans << endl;
    }
	return 0;
}