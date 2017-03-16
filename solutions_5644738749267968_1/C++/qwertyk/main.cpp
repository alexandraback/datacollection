#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int i, t;
int j, n, wp, dwp;
int first, last, m;

double *nblocks, *kblocks;

int main()
{
    freopen("D-large.in", "r", stdin);
    freopen("output.out", "w", stdout);

    cin >> t;

    for(i = 1; i <= t; ++i)
    {
        cin >> n;
        nblocks = new double[n];
        kblocks = new double[n];

        for(j = 0; j < n; ++j)
            cin >> nblocks[j];
        for(j = 0; j < n; ++j)
            cin >> kblocks[j];

        sort(nblocks, nblocks + n);
        sort(kblocks, kblocks + n);

        wp = 0;
        first = 0;
        last = n - 1;
        for(j = n - 1; j >= 0; --j)
        {
            if(nblocks[j] > kblocks[last])
            {
                ++first;
                ++wp;
            }
            else
            {
                --last;
            }
        }

        for(m = 0;;)
        {
            dwp = 0;
            for(j = m; j < n; ++j)
                if(nblocks[j] > kblocks[j - m]) ++dwp;
            if(dwp + m == n) break;
            else ++m;
        }

        //for(j = 0; j < n; ++j)
        //    cout << nblocks[j] << " and " << kblocks[j] << endl;

        cout << "Case #" << i << ": " << dwp << " " << wp << endl;

        delete [] nblocks;
        delete [] kblocks;
    }

    return 0;
}
