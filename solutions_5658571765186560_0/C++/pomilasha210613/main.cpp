#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("aaa.in", "r", stdin);
    freopen("aaa.out","w",stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        int x, r, w;
        cin >> x >> r >> w;
        if (r > w)
            swap(r, w);
        if (r * w % x != 0)
        {
            cout << "RICHARD\n";
            continue;
        }
        if (x == 1 || x == 2)
            cout << "GABRIEL\n";
        if (x == 3)
        {
            if (r == 1)
                cout << "RICHARD\n";
            else cout << "GABRIEL\n";
        }
        if (x == 4)
        {
            if (r < 3)
                cout << "RICHARD\n";
            else cout << "GABRIEL\n";
        }
    }
    return 0;
}
