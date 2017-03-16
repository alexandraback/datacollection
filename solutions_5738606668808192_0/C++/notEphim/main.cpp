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

string proof = "3 4 5 6 7 8 9 10 11";

int inc (vector< int > & cd, int & sum, const int n)
{
    ++cd.back ();
    ++sum;
    if (sum > n/2)
    {
        --sum;
        --cd.back ();
        int pos = cd.size () - 1;
        while (cd[pos] == 0)
            --pos;
        sum -= cd[pos];
        cd[pos] = 0;
        if (pos == 0)
            return 0;
        else
        {
            --pos;
            ++sum;
            ++cd[pos];
            return 1;
        }
    }
}

void decode (const vector< int > & cd, const int n)
{
    cout << "1";
    int gap = 0, pos = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        if (pos == cd.size () || gap < cd[pos])
        {
            cout << 1 - i % 2;
            ++gap;
        }
        else
        {
            cout << i % 2;
            gap = 0;
            ++pos;
        }
    }
    cout << "1";
}

int main()
{
    freopen ("c.in", "r", stdin);
    freopen ("c.out", "w", stdout);
    int T;
    cin >> T;
    for (int Ti = 1 ; Ti <= T ; ++Ti)
    {
        cout << "Case #" << Ti << ": ";

        cout << endl;
        int n, j;
        cin >> n >> j;
        n -= 2;
        assert(n % 2 == 0);
        int sum = 0;
        vector< int > cd (n/2, 0);
        for (int i = 0 ; i < j ; ++i)
        {
            decode (cd, n);
            cout << " " << proof << endl;
            inc (cd, sum, n);
        }
    }
    return 0;
}
