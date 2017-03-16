#include <iostream>
#include <math.h>

using namespace std;

inline long long sum(long long m, long long r)
{
    return 2 * m * r + m * (2 * m - 1);
}

void main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        long long r, s;
        cin >> r >> s;

        long long nl = 1, nt = (long long)((sqrt((2.0 * r - 1) * (2.0 * r - 1) + 8.0 * s) + 1 - 2.0 * r) / 4);
        long long m, ts = sum(nt, r);
        if (ts < s) {
            for (++nt; sum(nt, r) < s; ++nt);
            m = --nt;
        }
        else {
            for (; nl <= nt; )
            {
                m = (nl + nt) / 2;
                ts = sum(m, r);
                if (ts < s)
                    nl = m + 1;
                else
                    nt = m - 1;
            }
        }
        for (; sum(m, r) > s; --m);

        cout << "Case #" << t << ": " << m << endl;
    }
}
