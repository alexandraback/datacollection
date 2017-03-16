//#define LARGE
#define SMALL

#include <iostream>
#include <string>

using namespace std;

int it, tt;

string s;
int i, pe, qe;
long long p, q, n;

int main()
{
#if defined(LARGE)
    freopen("../A-large.in", "r", stdin);
    freopen("../A-large.out", "w", stdout);
#elif defined(SMALL)
    freopen("../A-small-attempt0.in", "r", stdin);
    freopen("../A-small.out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif

    cin >> tt;

    for(it = 1; it <= tt; ++it)
    {
        cin >> s;
        pe = s.find_first_of('/');
        qe = s.length();

        p = 0;
        for(i = 0; i < pe; ++i)
        {
            p *= 10;
            p += (long long) (s[i] - '0');
        }
        q = 0;
        for(i = pe + 1; i < qe; ++i)
        {
            q *= 10;
            q += (long long) (s[i] - '0');
        }

        n = q; 
        while(!(n & 1))
        {
            n >>= 1;
        }

        if(p % n)
        {
            cout << "Case #" << it << ": impossible" << endl;
            continue;
        }

        p /= n;
        q /= n;
        for(i = 0; p < q; q >>= 1, ++i);

        cout << "Case #" << it << ": " << i << endl;
    }

    return 0;
}
