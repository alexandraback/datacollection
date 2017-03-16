#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("B-small-attempt4.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int x, y;
        string s = "";
        cin >> x >> y;
        int k = 1;
        while (abs(x) - abs(abs(x) - k) > 0 || abs(y) - abs(abs(y) - k) > 0)
        {
            if (abs(x) - abs(abs(x) - k) > abs(y) - abs(abs(y) - k))
            {
                if (x > 0)
                {
                    x -= k;
                    s += 'E';
                    k++;
                }
                else if (x < 0)
                {
                    x += k;
                    s += 'W';
                    k++;
                }
                continue;
            }
            if (abs(y) - abs(abs(y) - k) >abs(x) - abs(abs(x) - k))
            {
                if (y > 0)
                {
                    y -= k;
                    s += 'N';
                    k++;
                }
                else if (y < 0)
                {
                    y += k;
                    s += 'S';
                    k++;
                }
                continue;
            }
            if (abs(y) - abs(abs(y) - k)  == abs(x) - abs(abs(x) - k))
            {
                if (abs(y) > abs(x))
                {
                if (y > 0)
                {
                    y -= k;
                    s += 'N';
                    k++;
                }
                else if (y < 0)
                {
                    y += k;
                    s += 'S';
                    k++;
                }
                continue;
                }
                else
                {
                if (x > 0)
                {
                    x -= k;
                    s += 'E';
                    k++;
                }
                else if (x < 0)
                {
                    x += k;
                    s += 'W';
                    k++;
                }
                continue;
                }
            }
        }
        while (x != 0 || y != 0)
        {
            if (x > 0)
            {
                x += k;
                s += 'W';
                k++;
                x -= k;
                s += 'E';
                k++;
            }
            if (x < 0)
            {
                x -= k;
                s += 'E';
                k++;
                x += k;
                s += 'W';
                k++;
            }
            if (y < 0)
            {
                y -= k;
                s += 'N';
                k++;
                y += k;
                s += 'S';
                k++;
            }
            if (y > 0)
            {
                y += k;
                s += 'S';
                k++;
                y -= k;
                s += 'N';
                k++;
            }
        }
        cout << "Case #" << q + 1 << ": " << s << endl;
    }
    return 0;
}
