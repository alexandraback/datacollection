#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

const int N = 1000000;

int dp[N + 5];

inline int rev(int n) {
    int res = 0;
    while (n) {
        res = 10 * res + n % 10;
        n /= 10;
    }
    return res;
}

int t, n;
int cas = 1;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(false);
    for (int i = 1; i <= N; i++) {
        dp[i] = -1;
    }
    q.push(1);
    dp[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int y = x + 1;
        if (y <= N && dp[y] == -1) {
            dp[y] = dp[x] + 1;
            q.push(y);
        }
        y = rev(x);
        if (y <= N && dp[y] == -1) {
            dp[y] = dp[x] + 1;
            q.push(y);
        }
    }
    freopen("dat.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        cout << "Case #" << cas++ << ": " << dp[n] << "\n";
    }
}
