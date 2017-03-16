#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)
#define forin(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> inline bool Min(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> inline bool Max(T &a, T b) { return a < b ? (a = b, true) : false; }

inline int    ni() { int    a; scanf("%d",   &a); return a; } // next_int();
inline ll     nl() { ll     a; scanf("%lld", &a); return a; } // next_long();
inline double nd() { double a; scanf("%lf",  &a); return a; } // next_double();

inline void pi(int    a) { printf ( "%d ",      a); }
inline void pl(ll     a) { printf ( "%lld ",    a); }
inline void pd(double a) { printf ( "%.12lf ",  a); }
///////////////////////////////////////////////////////////////////////////////

void solve(int test)
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    
    map<pii, int> ab, ac, bc;
    
    vector<pair<int, pii>> xs;
    
    for ( int ia = 1; ia <= a; ia++ )
    {
        for ( int ib = 1; ib <= b; ib++ )
        {
            for ( int ic = 1; ic <= c; ic++ )
            {
                pii AB = {ia, ib};
                pii AC = {ia, ic};
                pii BC = {ib, ic};
                
                if ( ab[AB] < k and ac[AC] < k and bc[BC] < k )
                {
                    xs.push_back({ia, {ib, ic}});
                    ab[AB]++;
                    ac[AC]++;
                    bc[BC]++;
                }
            }
        }
    }
    
    cout << "Case #" << test << ": " << xs.size() << "\n";
    
    for ( auto v : xs )
        cout << v.fi << " " << v.se.fi << " " << v.se.se << "\n";
    
}

void solve()
{
    int t;
    cin >> t;
    
    forn(i, t) solve(i+1);
}

int main()
{
#define GCJ

    
#ifdef LOCAL
#ifdef GCJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif
#endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    srand((int)clock());
    
    solve();
    
    return 0;
}