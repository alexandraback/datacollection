#define ENABLE_MAIN 1
#if ENABLE_MAIN


#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <list>
#include <queue>
#include <numeric>
#include <iomanip>
#include <fstream>


using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<ll, ll> PLL;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;

const ll oo = 1LL << 60;
const int kNumMoves = 4;
const int kMoves[kNumMoves][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

#define FOR(i, n) for (int i = 0; i < int(n); ++i)
#define FORI(i, s, n) for (int i = s; i < int(n); ++i)
#define FORD(i, n) for (int i = n - 1; i >= 0; --i)
#define VALID(i, mx) (i >= 0 && i < mx)

string PrintCase(int i)
{     
    ostringstream os;
    os << "Case #" << (i + 1) << ": ";
    return os.str();
}
vi valid(10, 0);
char buf[100];

bool HasSqPalindrome(ll v)
{    
    if (v > 3)
    {
        int d;
        ll c = v;
        while (c)
        {
            d = c % 10;
            if (d > 2) return false;
            c /= 10;
        }
    }
    stringstream ss;
    ss << v;
    string s = ss.str();

    int d = s.size();
    FOR(i, d / 2) { if (s[i] != s[d - 1 - i]) return false; }
    ll vsq = v * v;
    stringstream sss;
    sss << vsq;
    s = sss.str();
    d = s.size();
    FOR(i, d / 2) { if (s[i] != s[d - 1 - i]) return false; }
    
    return true;
}

int main()
{
//     ofstream cout ("C-large-1.out");
//     ifstream cin ("C-large-1.in");

    vector<PLL> sq;
    valid[1] = valid[4] = valid[5] = valid[6] = valid[9] = 1;
    vl vals;
    
    FORI(i, 1, 100000002)
    {
        if (HasSqPalindrome(i))
        {
            sq.push_back(PLL(i, ll(i) * i));
            vals.push_back(ll(i) * i);
        }
    }

    int t;
    cin >> t;
    FOR(c, t)
    {
        ll a, b;

        cin >> a >> b;

        int idxL = lower_bound(vals.begin(), vals.end(), a) - vals.begin();
        int idxU = upper_bound(vals.begin(), vals.end(), b) - vals.begin();

        cout << PrintCase(c) << (idxU - idxL) << endl;
    }

//     cout << sq.size() << endl;
//     FOR(i, sq.size())
//         cout << sq[i].first << " " << sq[i].second << endl;
    return 0;
}
#endif