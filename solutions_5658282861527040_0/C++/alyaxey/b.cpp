#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define sz(X) ((int)(X).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define FOR(i, a, n) for(int i=(a), __ ## i=(n); i<__ ## i; i++)
#define REP(I,N) FOR(I,0,N)
#define PR(X) cout<<#X<<" = "<<(X)<<" "
#define PRL cout<<endl
#define PRV(X) {cout<<#X<<" = {";REP(__prv,sz(X)-1)cout<<(X)[__prv]<<",";if(sz(X))cout<<*(X).end();cout<<"}"<<endl;}

template<class T> ostream &operator<<(ostream &os, vector<T> &vec)
{
    os << '{';
    REP(i, sz(vec))
    {
        os << vec[i];
        if (i + 1 != sz(vec) )
            os << ',';
    }
    os << '}';
    return os;
}

template<class T1, class T2> ostream &operator<<(ostream &os, pair<T1, T2> &par)
{
    os << '(' << par.X << ',' << par.Y << ')';
    return os;
}

typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : abs(x);
}

template<class T> T sqr(T x)
{
    return x * x;
}

template <class T>
inline void hash_combine(std::size_t& seed, const T& v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

namespace std
{
    template <class T, class P>
    struct hash<pair<T,P>>
    {
        size_t operator()(const pair<T,P> & p) const
        {
            size_t x = 0;
            hash_combine(x, p.X);
            hash_combine(x, p.Y);
            return x;
        }
    };
}

unordered_map<pair<pair<int, int>, int>, lint> s;

lint solve(int a, int b, int c, int t) {
    if(a <= 0 || b <= 0 || c <= 0)
        return 0;
    int m = 1 << (t + 1);
    a = min(a, m);
    b = min(b, m);
    c = min(c, m);
    if(a == m && b == m && c == m)
        return sqr(lint(m));
    auto key = mp(mp(a, b), c);
    auto it = s.find(key);
    if(it != s.end())
        return it->Y;
    int t2 = 1 << t;
    lint ans = 0;
    ans += solve(a, b, c, t - 1);
    ans += solve(a - t2, b, c, t - 1);
    ans += solve(a, b - t2, c, t - 1);
    ans += solve(a - t2, b - t2, c - t2, t - 1);
//    cerr << "f(" << a <<"," << b <<","<<c<<","<<t<<")="<<ans<<endl;
    return s[key] = ans;
}

void solve(int test)
{
    int a, b, c;
    cin >> a >> b >> c;
    lint ans = solve(a, b, c, 29);
    cout << "Case #" << test << ":";
    cout << fixed;
    cout << setprecision(8);
    cout << " ";
    cout << ans;
    cout << endl;
}

void pre()
{
}

int main()
{
    if (!freopen("1.in", "r", stdin))
    {
        cerr << "No input file" << endl;
        return 1;
    }
    if (!freopen("1.out", "w", stdout))
    {
        cerr << "Error creating output file" << endl;
        return 1;
    }
    ios::sync_with_stdio(false);
    pre();
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);
    for (int i = 1; i <= n; ++i)
    {
        solve(i);
    }
    return 0;
}
