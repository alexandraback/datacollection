#include <bits/stdc++.h>
using namespace std;

int main(void) {
    freopen("in.txt", "rt", stdin);
    freopen("test.txt", "wt", stdout);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc)
    {
        string s, t;
        cin >> s;
        int i;
        t += s[0];
        for(i = 1; s[i] != '\0'; ++i)
        {
            if(s[i] >= t[0])
                t = s[i] + t;
            else
                t = t + s[i];
        }
        cout << "Case #" << tc << ": ";
        cout << t << "\n";
    }
    return 0;
}
