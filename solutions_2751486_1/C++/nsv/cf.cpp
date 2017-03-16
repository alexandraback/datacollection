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

string vv = "aeiou";

bool check(char ch)
{
    forn(i, vv.length())
        if (ch == vv[i])
            return false;
    return true;
}

LL solve(const string &s, int len)
{
    string t = string(len, '1') + "#" + s;
    for (int i = len + 1; i < t.length(); ++i)
        t[i] = check(t[i]) + '0';


    const int n = t.size();
    vi p(n);
    for (int i = 1; i < n; ++i)
    {
        int q = p[i - 1];
        while (q > 0 && t[i] != t[q])
            q = p[q - 1];
        if (t[i] == t[q])
            ++q;
        p[i] = q;
    }

    forn(i, n)
        p[i] = p[i] == len;

    LL ans = 0;
    int last = -1;
    forn(i, s.length())
    {
        int j = i + len + 1;
        if (p[j])
            last = i;
        if (last != -1)
            ans += last - len + 2;
    }
    return ans;
}

int main()
{
    START
    // freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    forn(i, t)
    {
        string s; int n;
        cin >> s >> n;
        cout << "Case #" << i + 1 << ": " << solve(s, n) << endl;
    }

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