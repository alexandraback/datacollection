#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int a, cnt, i, j, t, x, x1, y, y1;
    string res;
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> x; cin >> y;
        res = "";
        if (x > 0)
        {
            res = res + "E";
            for (i = 1; i < x; i++) res += "WE";
        }
        if (x < 0)
        {
            res = res + "W";
            for (i = 1; i < (-x); i++) res += "EW";
        }
        if (y > 0)
        {
            for (i = 0; i < y; i++) res += "SN";
        }
        if (y < 0)
        {
            for (i = 0; i < (-y); i++) res += "NS";
        }
        cout << "Case #" << cnt << ": " << res << endl;
        /*x1 = 0; y1 = 0;
        for (i = 0; i < res.length(); i++)
        {
            if (res[i] == 'N') y1 += (i + 1);
            if (res[i] == 'S') y1 -= (i + 1);
            if (res[i] == 'E') x1 += (i + 1);
            if (res[i] == 'W') x1 -= (i + 1);
        }
        cout << x1 << " " << y1 << endl;*/
    }
    return 0;
}
