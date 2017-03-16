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

long long rev(long long n)
{
    auto s = to_string(n);
    reverse(ALL(s));
    sscanf(s.data(), "%lld", &n);
    return n;
}

map<long long, long long> mp;
long long build(long long n)
{
    queue<long long> q;

    auto P = [&](long long val, long long cost)
    {
        if (mp.count(val))
            return;

        mp[val] = cost;
        q.push(val);
    };

    mp[1] = 1;
    q.push(1);
    while (not q.empty())
    {
        ll a = q.front();
        q.pop();
        auto cost = mp[a];

        if (a == n)
            return cost;

        P(a + 1, cost + 1);
        P(rev(a), cost + 1);
    }
    return -1;
}

void solve(int id)
{
    long long n;
    scanf("%lld", &n);
    printf("Case #%d: %lld\n", id, mp[n]);
}

int main()
{
    build(1000000);

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i)
        solve(i);

}

