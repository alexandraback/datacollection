#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test)
    {
        int x, r, c;
        cin >> x >> r >> c;
        if (r > c)
            swap(r, c);
        cout << "Case #" << test << ": ";
        if (x == 1)
            puts("GABRIEL");
        else if (x == 2)
            puts(r * c % 2 == 0 ? "GABRIEL" : "RICHARD");
        else if (x == 3)
            puts(r * c % 3 == 0 && r >= 2 ? "GABRIEL" : "RICHARD");
        else if (x == 4)
            puts(r * c % 4 == 0 && r >= 3 && c == 4 ? "GABRIEL" : "RICHARD");
        /*else if (r * c % x != 0 || x >= 7 || x > max(r, c) || (x + 1) / 2 > min(r, c)
            || r * c == 2 * x)
            puts("RICHARD");
        else
            puts("GABRIEL");*/
    }
    return 0;
}