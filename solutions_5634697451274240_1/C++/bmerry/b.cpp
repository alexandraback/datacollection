#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        string cakes;
        cin >> cakes;
        reverse(cakes.begin(), cakes.end());
        char prev = '+';
        int ans = 0;
        for (char c : cakes)
        {
            if (c != prev)
            {
                ans++;
                prev = c;
            }
        }
        cout << "Case #" << cas + 1 << ": " << ans << '\n';
    }
}
