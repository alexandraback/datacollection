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

deque< char > answer;

int main()
{
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    int T;
    cin >> T;
    for (int Ti = 1 ; Ti <= T ; ++Ti)
    {
        cout << "Case #" << Ti << ": ";

        answer.clear ();
        string s;
        cin >> s;
        char mx = 'A' - 1;
        for (int i = 0 ; i < s.size () ; ++i)
        {
            mx = max (mx, s[i]);
            if (mx == s[i])
            {
                answer.push_front (s[i]);
            }
            else
            {
                answer.push_back (s[i]);
            }
        }
        for (deque< char > :: iterator it = answer.begin () ; it != answer.end () ; ++it)
        {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}
