#include <bits/stdc++.h>
using namespace std;

const int N = 1024;

int n, a[N];

void input()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

int solve(int k)
{
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += (a[i] - 1) / k;
    }
    return ret + k;
}

void solve()
{
    int ans = *max_element(a, a + n);
    for (int k = 1; k < ans; ++k) {
        ans = min(ans, solve(k));
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
