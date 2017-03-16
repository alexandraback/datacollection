#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define all(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long uli;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const int P = 1e9 + 7, Q = 1e9 + 9;
const int base = 41;
const double PI = 3.141592653589793238;
const double eps = 1e-7;

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif // DEBUG

#ifdef DEBUG
#define END {cout << endl; return main ();}
#else
#define END return 0
#endif

ll kpow[105];

int main()
{
    freopen ("d.in", "r", stdin);
    freopen ("d.out", "w", stdout);
    int T;
    cin >> T;
    for (int Ti = 1 ; Ti <= T ; ++Ti)
    {
        cout << "Case #" << Ti << ": ";

        int k, c, s;
        cin >> k >> c >> s;
        if (c * s < k)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        else if (k == 1)
        {
            cout << "1\n";
            continue;
        }
        else
        {
            kpow[0] = 1;
            for (int i = 1 ; i <= c ; ++i)
            {
                kpow[i] = kpow[i - 1] * ll (k);
            }
            int pw = c - 1;
            ll res = 0;
            for (int i = 0 ; i < k ; ++i)
            {
                res += ll(i) * kpow[pw];
                --pw;
                if (pw == -1)
                {
                    cout << res + 1 << ' ';
                    res = 0;
                    pw = c - 1;
                }
            }
            if (pw != c - 1)
                cout << res + 1 << endl;
            else
                cout << endl;
        }
    }
    return 0;
}
