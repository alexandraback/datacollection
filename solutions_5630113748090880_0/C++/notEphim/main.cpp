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

int check[3000];

int main()
{
    freopen ("b.in", "r", stdin);
    freopen ("b.out", "w", stdout);
    int T;
    cin >> T;
    for (int Ti = 1 ; Ti <= T ; ++Ti)
    {
        cout << "Case #" << Ti << ": ";

        for (int i = 0 ; i < 3000 ; ++i)
        {
            check[i] = 0;
        }
        int n;
        cin >> n;
        for (int i = 0 ;  i < 2 * n - 1 ; ++i)
        {
            for (int j = 0 ; j < n ; ++j)
            {
                int h;
                cin >> h;
                ++check[h];
            }
        }
        for (int i = 0 ; i < 3000 ; ++i)
        {
            if (check[i] % 2 != 0)
            {
                cout << i << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
