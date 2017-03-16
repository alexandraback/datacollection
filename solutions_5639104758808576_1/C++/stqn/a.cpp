#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void input()
{
    cin >> n >> s;
}

void solve()
{
    int ans = 0, sum = 0;
    for (int i = 0; i <= n; ++i) {
        const int d = s[i] - '0';
        if (d >= 1 and sum < i) {
            ans = max(ans, i - sum);
        }
        sum += d;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        input();
        solve();
    }
}
