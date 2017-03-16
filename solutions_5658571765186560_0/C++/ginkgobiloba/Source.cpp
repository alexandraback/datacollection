#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for (int t = 1; t <= cases; ++t)
    {
        bool can = false;
        int x, r, c;
        cin >> x >> r >> c;
        if (r > c) swap(r, c);
        if (x == 1) can = true;
        if (x == 2 && r*c % 2 == 0) can = true;
        if (x == 3 && (r == 2 && c == 3 || r == 3 && c == 3 || r == 3 && c == 4)) can = true;
        if (x == 4 && (r == 3 && c==4 || r == 4 && c == 4)) can = true;
        cout << "Case #" << t << ": ";
        if (can) cout << "GABRIEL";
        else cout << "RICHARD";
        cout << endl;
    }
    return 0;
}