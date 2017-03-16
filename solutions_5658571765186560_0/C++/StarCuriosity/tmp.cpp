#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int T = 100;
    cin >> T;
    for(int test = 1; test <= T; ++test)
    {
        int x,r,c;
        cin >> x >> r >> c;
        if (r < c)
            swap(r,c);
        bool ans;
        if ( (r*c%x) != 0 || x > r)
        {
            ans = false;
        }
        else
        {
            if (x <= 2)
                ans = true;
            if (x == 3)
                ans = c > 1;
            if (x == 4)
            {
                ans = c > 2;
            }
            if (x == 5)
            {
                ans = c > 2 && (c > 3 || r > 5);
            }
            if (x == 6)
            {
                ans = c > 3;
            }
            if (x >= 7)
                ans = false;
        }
        cout << "Case #" << test << ": " << (ans? "GABRIEL" : "RICHARD") << "\n";
    }

    return 0;
}
