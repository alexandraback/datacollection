#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int flipnumber(int x) {
    int num = 0;
    queue<int> stk;
    while (x) {
        stk.push(x % 10);
        x /= 10;
    }
    while (!stk.empty()) {
        num *= 10;
        num += stk.front();
        stk.pop();
    }
    return num;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, inp;
    cin >> tc;
    for (int a = 1; a <= tc; ++a) {
        int dp[1000005];
        fill(dp, dp + 1000000, 1e9);
        pair<int, int> top;
        cin >> inp;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
        que.push(make_pair(1, 1));
        while (!que.empty()) {
            top = que.top();
            que.pop();
            if (dp[top.second] <= top.first) continue;
            dp[top.second] = top.first;
            if (top.second < inp)
                que.push(make_pair(top.first + 1, top.second + 1));
            que.push(make_pair(top.first + 1, flipnumber(top.second)));
        }
        cout << "Case #" << a << ": " << dp[inp] << "\n";
    }
    return 0;
}