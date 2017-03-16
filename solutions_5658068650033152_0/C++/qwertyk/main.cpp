//#define LARGE
#define SMALL

#include <iostream>

using namespace std;

int it, tt;

int n, m, k, t, x, y;

int main()
{
#if defined(LARGE)
    freopen("../C-large.in", "r", stdin);
    freopen("../C-large.out", "w", stdout);
#elif defined(SMALL)
    freopen("../C-small-attempt0.in", "r", stdin);
    freopen("../C-small.out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif

    cin >> tt;

    for(it = 1; it <= tt; ++it)
    {
        cin >> n >> m >> k;

        if(n < 3 || m < 3 || k < 5)
        {
            cout << "Case #" << it << ": " << k << endl;
            continue;
        }

        if(n > m)
        {
            t = m;
            m = n;
            n = t;
        }

        for(x = 1; x*x - 4 < k && x < n; ++x);
        for(y = x; y*x - 4 < k && y < m; ++y);

        if(k >= n*m - 4)
        {
            t = 2*(n + m) + k - n*m - 4;
        }
        else if(k > x*y - 4)
        {
            t = 2*(x+y) - 7;
        }
        else if(k == x*y - 4)
        {
            t = 2*(x+y) - 8;
        }
        else if(k > (x-1)*y - 4)
        {
            t = 2*(x+y) - 9;
        }
        else
        {
            t = 2*(x+y) - 10;
        }

        cout << "Case #" << it << ": " << t << endl;
    }

    return 0;
}
