#include <bits/stdc++.h>
using namespace std;

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
        string s;
        cin >> s;
        int ans = 0;
        int cur = 0;
        for(int i = 0; i <= n; ++i)
        {
            while (cur < i)
            {
                ++ans;
                ++cur;
            }
            cur += s[i] - '0';
        }
        cout << "Case #" << test <<": " << ans <<"\n";
    }

    return 0;
}
