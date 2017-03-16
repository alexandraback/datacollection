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

bool good(char c)
{
    forn(i, vv.size())
        if (c == vv[i])
            return true;
    return false;
}

bool check(const string &s, int n)
{
    //dbg(s);
    int cnt = 0;
    forn(i, s.length())
    {
        if (!good(s[i]))
            ++cnt;
        else
        {
            if (cnt >= n)
                return true;
            cnt = 0;
        }
    }
    return cnt >= n;
}

int solve(const string &s, int n)
{
    //dbg(s);
    int cnt = 0;
    for (int l = 0; l < s.length(); ++l)
        for (int r = l; r < s.length(); ++r)
            cnt += check(s.substr(l, r - l + 1), n);
    return cnt;
}

int main()
{
    START
    // freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        string s;
        int n;
        cin >> s >> n;
        cout << "Case #" << i << ": " << solve(s, n) << endl;
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