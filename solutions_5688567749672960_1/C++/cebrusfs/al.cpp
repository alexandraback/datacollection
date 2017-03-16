// @author cebrusfs
// headers {{{
#include<bits/stdc++.h>
using namespace std;
// }}}
// macros {{{
#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(x) (sort(ALL(x)), ((x).erase(unique(ALL(x)), (x).end())))
#define MS(x, v) std::fill(ALL(x), (v));


#define IOS ios_base::sync_with_stdio(false)

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)

#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)

#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
#define MP make_pair
#define F first
#define S second

typedef vector<int> VI;
#define PB push_back
#define PF push_front

#define PPB pop_back
#define PPF pop_front


// C++11
#if __cplusplus >= 201103L
#define MT make_tuple
typedef tuple<int, int> TII;
#endif

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;
// }}}

#define MAX 17
#define INF (1e17)


long long lcost[MAX] =
{
    1,
    9, 19,
    109, 199,
    1099, 1999,
    10999, 19999,
    109999, 199999,
    1099999, 1999999,
    10999999, 19999999,
    109999999, 199999999
};

long long rev(long long n)
{
    auto s = to_string(n);
    reverse(ALL(s));
    sscanf(s.data(), "%lld", &n);
    return n;
}

string srev(string s)
{
    reverse(ALL(s));
    return s;
}

long long solve3(string ls, string rs)
{
    ll l, r;
    assert(rs.size());
    //fprintf(stderr, "%s | %s\n", ls.data(), rs.data());
    sscanf(ls.data(), "%lld", &l);
    sscanf(rs.data(), "%lld", &r);

    // rev 2
    ll a = (l - 1) + 2 + r;
    //rev 1
    ll b = l + 1 + (r - 1);

    if (SZ(ls) == 0)
        return INF;

    if (l == 0 or r == 0) return 1e18;

    //fprintf(stderr, "%lld - 1 + 2 + %lld = %lld\n", l, r, a);
    //fprintf(stderr, "%lld + 1 + (%lld - 1) = %lld\n", l, r, b);

    // rev 0
    if (l == 1) return r;

    return min(a, b);
}

long long solve2(string s)
{
    ll ans = INF;
    for (int i = 0; i < SZ(s); ++i)
    {
        auto ls = srev(s.substr(0, i));
        auto rs = s.substr(i);
        ans = min(ans, solve3(ls, rs));
    }
    return ans;
}

long long count(long long n)
{
    auto s = to_string(n);
    int nl = s.size();

    ll ans = lcost[nl - 1];

    ll a = solve2(s);
    ll b = solve2(srev(s)) + 1;
    s[0] -= 1;

    ll c;
    sscanf(s.data(), "%lld", &c);

    ll ans2 = INF;
    ans2 = min(a, ans2);
    ans2 = min(b, ans2);
    ans2 = min(c, ans2);
    return ans + ans2;
}

void solve(int id)
{
    fprintf(stderr, "case %d\n", id);
    ll n;
    scanf("%lld", &n);
    ll a = count(n);
    ll b = count(n - 1) + 1;
    printf("Case #%d: %lld\n", id, min(a, b));
}

int main()
{
    for (int i = 1; i < MAX; ++i)
        lcost[i] += lcost[i - 1];

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i)
        solve(i);
}

