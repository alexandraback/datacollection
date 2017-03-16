#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;
typedef unsigned int uint;

uint v[10000];
uint e, r, n;
uint m[10000][10000];

uint solve(int h, int t, uint se, uint le)
{
    if (h >= t)
        return 0;

    int mpos = m[h][t-1];

    uint ee = se + (mpos - h) * r;
    if (ee > e)
        ee = e;

    uint lle = (t - mpos) * r;

    uint te = (lle >= le ? ee : ee + lle - le);
    uint s = 0;
    assert((int)te >= 0);
    if ((int)te < 0)
        s = 0;
    else
        s = te * v[mpos];

    return s + solve(h, mpos, se, ee) + solve(mpos + 1, t, ee - te + r, le);
}

void main()
{
    uint T = 0;
    cin >> T;
    for (uint ti = 1; ti <= T; ++ti)
    {
        cin >> e >> r >> n;
        for (uint i = 0; i < n; ++i)
            cin >> v[i];

        if (r > e)
            r = e;

        memset(m, 0xFF, sizeof(m));
        for (uint j = 0; j < n; ++j)
        {
            m[j][j] = j;
            for (uint i = j + 1; i < n; ++i)
            {
                if (v[i] > v[m[j][i-1]])
                    m[j][i] = i;
                else
                    m[j][i] = m[j][i-1];
            }
        }

        cout << "Case #" << ti << ": " << solve(0, n, e, 0) << endl;
    }
}
