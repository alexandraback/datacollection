#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s[110];
    int p[110];
    int c[110];
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        p[i] = 0;
    }
    while (p[0] < s[0].length())
    {
        char ch = s[0][p[0]];
        for (int i = 0; i < n; ++i) c[i] = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i][p[i]] != ch)
            {
                cout << "Fegla Won" << endl;
                return;
            }
            while (p[i] < s[i].length() && s[i][p[i]] == ch)
            {
                ++p[i];
                ++c[i];
            }
        }
        sort(c, c + n);
        int x = c[n / 2];
        for (int i = 0; i < n; ++i)
        {
            count += abs(c[i] - x);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (p[i] < s[i].length())
        {
            cout << "Fegla Won" << endl;
            return;
        }
    }
    cout << count << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
