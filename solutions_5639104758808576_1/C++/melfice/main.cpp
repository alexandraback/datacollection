#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        int k;
        cin >> k;
        string s;
        cin >> s;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i <= k; i++)
        {
            ans = max(ans, i - sum);
            sum += s[i] - '0';
        }
        cout << ans << "\n";
    }

}
