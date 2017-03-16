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
        int n;
        cin >> n;
        int p[n];
        for(int i = 0; i < n; i++)
            cin >> p[i];
        int ans = 1e9;
        for(int h = 1; h < 2000; h++)
        {
            int cur = h;
            for(int i = 0; i < n; i++)
                if(p[i] > h)
                    cur += (p[i] - 1) / h;
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }

}
