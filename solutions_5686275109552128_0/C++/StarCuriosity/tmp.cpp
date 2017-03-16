#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a)
{
    int ans = 10000;
    for(int t = 1; t <= 1000; ++t)
    {
        int cur = 0;
        for(int i = 0; i < a.size(); ++i)
            if (a[i] > t)
                cur += (a[i] - 1)/t;
        ans = min(ans, t+cur);
    }
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int T = 0;
    cin >> T;
    for(int test = 1; test <= T; ++test)
    {
        int n = 0;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        cout << "Case #" << test << ": " << solve(a) << "\n";
    }

    return 0;
}
