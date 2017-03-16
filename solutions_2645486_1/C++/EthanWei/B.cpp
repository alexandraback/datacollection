#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ulong;

uint v[10000];
uint e, r, n;
uint m[10000][10000];

ulong solve(int h, int t, ulong se, ulong le)
{
    if (h >= t)
        return 0;

    int mpos = m[h][t-1];

    ulong ee = se + (mpos - h) * (ulong)r;
    if (ee > e)
        ee = e;

    ulong lle = (t - mpos) * (ulong)r;

    ulong te = (lle >= le ? ee : ee + lle - le);
    ulong s = 0;
    assert((long long)te >= 0);
    if ((long long)te < 0)
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
