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

bool check(string s, char pl)
{
    if (pl == 'X')
        sort(rall(s));
    else
        sort(all(s));
    bool r = s == string(4, pl) ||
             s.substr(0, 3) == string(3, pl) && s[s.length() - 1] == 'T';
    return r;
}

void solve(int test)
{
    vector<string> v(4);
    forn(i, 4)
        cin >> v[i];

    // horisontal
    vector<string> tokens = v;

    // vertical
    forn(i, 4)
    {
        string t;
        forn(j, 4)
            t += v[j][i];
        tokens.pb(t);
    }

    // diag1
    string t;
    forn(i, 4)
        t += v[i][i];
    tokens.pb(t);

    // diag2
    string d;
    forn(i, 4)
        d += v[i][4 - i - 1];
    tokens.pb(d);

    bool x = false;
    forn(i, tokens.size())
        if (check(tokens[i], 'X'))
            x = true;

    bool o = false;
    forn(i, tokens.size())
        if (check(tokens[i], 'O'))
            o = true;

    printf("Case #%d: ", test);
    if (x)
        puts("X won");
    else if (o)
        puts("O won");
    else
    {
        bool nc = false;
        forn(i, 4)
            forn(j, 4)
                if (v[i][j] == '.')
                    nc = true;

        if (nc)
            puts("Game has not completed");
        else
            puts("Draw");
    }
}

int main()
{
    START
    // freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
        solve(i + 1);

    END
    return 0;
}
/*******************************************
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