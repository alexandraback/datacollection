#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve()
{
    int x, r, c;
    cin >> x;
    cin >> r;
    cin >> c;
    if (r * c % x != 0)
        return 1;
    else if (x == 1)
        return 0;
    else if (x == 2)
        return 0;
    else if (x == r * c)
        return 1;
    else if(x == 3)
    {
        if (r < 3 && c < 3)
            return 1;
        else if (r == 1 || c == 1)
            return 1;
        else
            return 0;
    }
    else if (x == 4)
    {
        if (r == 1 || c == 1)
            return 1;
        else if (r < 4 && c < 4)
            return 1;
        else if (r == 2 || c == 2)
            return 1;
        else
            return 0;
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int s = solve();
        if (s)
            cout << "Case #" << i << ": " << "RICHARD" << endl;
        else
            cout << "Case #" << i << ": " << "GABRIEL" << endl;
    }
    return 0;
}
