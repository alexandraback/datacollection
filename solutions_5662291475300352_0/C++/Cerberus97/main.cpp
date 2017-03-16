#include <iostream>
#include <fstream>

using namespace std;

long double d[2], m[2], s[2];

void order()
{
    if (s[0] > s[1])
    {
        swap (s[1], s[0]);
        swap (d[1], d[0]);
        swap (m[1], m[0]);
    }
}

int main()
{
    ifstream in ("in.txt");
    ofstream out ("out.txt");

    int t, n, h;

    in >> t;

    for (int j = 1; j <= t; ++j)
    {
        int ctr = 0, ans = 0;

        in >> n;

        for (int i = 0; i < n; ++i)
        {
            in >> d[ctr] >> h >> m[ctr];

            s[ctr] = 360 / m[ctr];

            ++ctr;

            while (h != 1)
            {
                d[ctr] = d[ctr - 1];
                m[ctr] = m[ctr - 1] + 1;
                s[ctr] = 360 / m[ctr];
                ++ctr;
                --h;
            }
        }

        order();

        if (d[0] <= d[1])
        {
            if ((360 - d[0]) / s[0] < (720 - d[1]) / s[1])
                ans = 0;

            else
                ans = 1;
        }

        else if (s[0] == s[1])
        {
            ans = 0;
        }

        else if (d[1] < d[0])
        {
            int overtake = (d[0] * s[0] - d[1] * s[0]) / (s[1] - s[0]);

            if (overtake >= 360 - d[0])
                ans = 0;

            else if ((360 - d[0]) / s[0] < (720 - d[1]) / s[1])
                ans = 0;

            else
                ans = 1;
        }

        out << "Case #" << j << ": " << ans << '\n';
    }

    return 0;


}
