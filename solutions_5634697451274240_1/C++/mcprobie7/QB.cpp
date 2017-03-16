#include <stdio.h>
#include <iostream>

using namespace std;




int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("outputB.txt", "w", stdout);
    int nT;
    cin >> nT;
    for (int iT = 0; iT < nT; iT++)
    {
        string s;
        cin >> s;
        int n = s.length();
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '-')
            {
                ans++;
                for (int j = 0; j <= i; j++)
                    if (s[j] == '+') s[j] = '-'; else s[j] = '+';
            }
        }
        cout << "Case #" << iT + 1 << ": " << ans << endl;
    }
    return 0;

}
