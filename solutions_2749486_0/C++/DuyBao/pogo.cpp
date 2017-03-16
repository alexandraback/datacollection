#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int nTest = 0;
    cin >> nTest;
    for (int test = 1; test <= nTest; ++test)
    {
        int x, y;
        cin >> x >> y;
        cout << "Case #" << test << ": ";

        int ax = abs(x);
        int ay = abs(y);
        for (int i = 0; i < ax; ++i)
        {
            if (x > 0)
                cout << "WE";
            else
                cout << "EW";
        }
        for (int i = 0; i < ay; ++i)
        {
            if (y > 0)
                cout << "SN";
            else
                cout << "NS";
        }
        cout << endl;
    }
    return 0;
}
