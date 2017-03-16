#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin.sync_with_stdio(false);
    int T;
    cin >> T;

    for(int ct = 1; ct <= T; ct++)
    {
        string s;
        cin >> s;

        int ans = s.back() == '-';
        for(int i = 1; i < (int)s.size(); i++)
            ans += s[i] != s[i-1];
        cout << "Case #" << ct << ": " << ans << '\n';
    }

    return 0;
}
