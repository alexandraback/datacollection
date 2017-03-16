#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int u = 0; u < t; u++)
    {
        long long x, y;
        cin >> x >> y;
        cout << "Case #" << u + 1 << ": ";
        long long X = 0, Y = 0, l = 1;
        int k = 0;
        while (X != x)
        {
            if (k == 0) {
                X += l;
                cout << "E";
            }
            else {
                X -= l;
                cout << "W";
            }
            l++;
            k = (k + 1) % 2;
        }
        if (Y == y)
        {
            cout << endl;
            continue;
        }
        k = 0;
        if (y > 0)
        {
            k = 1;
        }
        while (y != Y)
        {
            if (k == 1)
            {
                Y -= l;
                cout << "S";
            }
            else
            {
                Y += l;
                cout << "N";
            }
            l++;
            k = (k + 1) % 2;
        }
        cout << endl;
    }
    return 0;
}
