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
    freopen ("b.in", "r", stdin);
    freopen ("b.out", "w", stdout);
    int T;
    cin >> T;
    for (int Ti = 1 ; Ti <= T ; ++Ti)
    {
        cout << "Case #" << Ti << ": ";

        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0 ; i < s.size () ; ++i)
        {
            if (i == 0 && s[i] == '-')
                ++ans;
            else if (s[i] == '-' && s[i - 1] == '+')
                ans += 2;
        }
        cout << ans << endl;
    }
    return 0;
}
