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

int main()
{
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    int T;
    cin >> T;
    for (int Ti = 1 ; Ti <= T ; ++Ti)
    {
        cout << "Case #" << Ti << ": ";

        int n;
        cin >> n;
        if (n == 0)
        {
            cout << "INSOMNIA\n";
            continue;
        }
        else
        {
            int wascnt = 0;
            bool was[10];
            for (int i = 0 ; i < 10 ; ++i)
                was[i] = false;
            int m = n;
            while (true)
            {
                int cpn = n;
                while (cpn > 0)
                {
                    int dig = cpn % 10;
                    if (!was[dig])
                    {
                        ++wascnt;
                        was[dig] = true;
                    }
                    cpn /= 10;
                }
                if (wascnt == 10)
                {
                    cout << n << endl;
                    break;
                }
                n += m;
            }

        }
    }
    return 0;
}
