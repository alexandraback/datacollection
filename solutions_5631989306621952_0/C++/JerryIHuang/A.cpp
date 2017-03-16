#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    string s, t;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    cin >> T;
    for (int K = 1; K <= T; K++)
    {
        cin >> s;
        t = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] + t > t + s[i])
                t = s[i] + t;
            else
                t = t + s[i];
        }
        cout << "Case #" << K << ": " << t << endl;
    }
    return 0;
}
