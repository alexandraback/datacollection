#if 1
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "problem"

LL vals[40] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001};

int solve()
{
    LL a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = 0; i < 40; ++i)
        if (a <= vals[i] && vals[i] <= b)
            ++cnt;
    return cnt;
}

bool ispal(LL x)
{
    if (x == -1)
        return false;

    vi v;
    while (x)
    {
        int c = x % 10;
        v.pb(c);
        x /= 10;
    }

    vi r = v;
    reverse(all(r));
    return v == r;
}

void gen()
{
    vector<LL> vals;
    for (LL i = 1; i <= 1e7 + 100; ++i)
    {
        if (ispal(i))
        {
            LL i2 = i * i;
            if (ispal(i2))
                vals.pb(i2);
        }
    }

    dbg(vals.size())
    dbg(vals);
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < vals.size(); ++i)
        cout << vals[i] << ", ";
    exit(0);
}

int main()
{
    // gen();
    START
    // freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
        printf("Case #%d: %d\n", i + 1, solve());

    END
    return 0;
}
/*******************************************
1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004

1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002

1 1
4 2
9 3
121 11
484 22
10201 101
12321 111
14641 121
40804 202
44944 212
1002001 1001
1234321 1111
4008004 2002

*******************************************/

template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
    forn(i, v.size())
        is >> v[i];
    return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
    forn(i, v.size())
        os << v[i] << " ";
    return os;
}
#endif