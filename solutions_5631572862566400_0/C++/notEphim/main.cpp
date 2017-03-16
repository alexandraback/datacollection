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

int fr[1005];
int cl[1005];
int cfr[1005];
int until[1005];

int main()
{
    freopen ("c.in", "r", stdin);
    freopen ("c.out", "w", stdout);
    int T;
    cin >> T;
    for (int Ti = 1 ; Ti <= T ; ++Ti)
    {
        cout << "Case #" << Ti << ": ";

        int n;
        cin >> n;
        for (int i = 0 ; i < n ; ++i)
        {
            cin >> fr[i];
            --fr[i];
        }
        int path[1005];
        for (int i = 0 ; i < n ; ++i)
        {
            path[0] = i;
            for (int i = 0 ; i < n ; ++i)
            {
                path[i + 1] = fr[path[i]];
            }
            cl[i] = 1;
            for ( ; path[n - cl[i]] != path[n] ; ++cl[i]);
            for (int j = n - cl[i] ; j >= 0 && path[j] == path[j + cl[i]] ; --j)
            {
                cfr[i] = path[j];
                until[i] = j;
            }
        }
        int piece[1005];
        for (int i = 0 ; i < n ; ++i)
            piece[i] = 0;
        for (int i = 0 ; i < n ; ++i)
        {
            if (cl[i] > 2)
            {
                if (cfr[i] == i)
                    piece[i] = cl[i];
                else
                    piece[i] = 0;
            }
            else
            {
                if (cfr[i] == i)
                {
                    piece[i] = max (piece[i], 1);
                }
                else
                {
                    piece[i] = 0;
                    piece[cfr[i]] = max (piece[cfr[i]], 1 + until[i]);
                }
            }
        }
        int best2 = 0;
        for (int i = 0 ; i < n ; ++i)
        {
            if (cl[i] == 2)
                best2 += piece[i];
        }
        for (int i = 0 ; i < n ; ++i)
        {
            best2 = max (best2, piece[i]);
        }
        cout << best2 << endl;
    }
    return 0;
}
