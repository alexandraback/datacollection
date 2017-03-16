#include <iostream>
#include <vector>

using namespace std;

char a[32][32];

int sgn(int x)
{
    return x > 0 ? 1 : x < 0 ? -1 : 0;
}

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        int h, w, d;
        cin >> h >> w >> d;

        int x, y;

        for (int i=0; i<h; i++)
        {
            cin >> a[i];

            for (int j=0; j<w; j++)
                if (a[i][j] == 'X')
                {
                    x = 2*i - 1;
                    y = 2*j - 1;
                }
        }

        int n = 2*(h-2);
        int m = 2*(w-2);

        vector<pair<int, int> > p;

        for (int i=-d; i<=d; i++)
            for (int j=-d; j<=d; j++)
            {
                if (i == 0 && j == 0)
                    continue;

                int xx = i & 1 ? n * (i+1) - 2*x : n * i;
                int yy = j & 1 ? m * (j+1) - 2*y : m * j;

                if (xx * xx + yy * yy > d * d * 4)
                    continue;

                bool f = false;

                for (int t=0; t<p.size(); t++)
                    if (p[t].first * yy - p[t].second * xx == 0 && sgn(p[t].first) == sgn(xx) && sgn(p[t].second) == sgn(yy))
                    {
                        f = true;
                        break;
                    }

                if (!f)
                    p.push_back(make_pair(xx, yy));
            }

        cout << "Case #" << tt << ": " << p.size() << endl;
    }

    return 0;
}
