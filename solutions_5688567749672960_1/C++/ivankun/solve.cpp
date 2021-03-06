#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <cstring>
#include <bitset>
#include <deque>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define mp make_pair
#define pb push_back
#define bpc(a) __builtin_popcount(a)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define forn(i,n) for(int i=0;i<(n);++i)
#define X first
#define Y second
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }

const int mod = 1e9 + 7;
const int inf = 1e9;

ll powm(ll a,ll p,ll m){ll r=1 % m;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}

int dp[1000001];
ll p10[20] = {1};

ll rev(ll n)
{
    ll r = 0;
    while(n)
    {
        r = 10 * r + (n % 10);
        n /= 10;
    }
    return r;
}

int len(ll d)
{
    int l = 0;
    while(d)
        l++, d /= 10;
    return l;
}

ll calc(ll n)
{
    if(n <= 20)
        return n;
    int l = len(n);
    int s = (l + 1) / 2;
    ll suf = n % p10[s];
    if(suf > 1)
    {
        ll next = (n / p10[s]) * p10[s] + 1;
        return calc(rev(next)) + n - next + (n != rev(n));
    }
    return calc(n - 1) + 1;
}

int solve()
{
    ll n;
    cin >> n;
    return calc(n);
}

int main()
{
    dp[1] = 1;
    for(int i = 2; i <= 1000000; ++i)
        dp[i] = inf;
    for(int i = 1; i <= 1000000; ++i)
    {
        int r = 0, a = i;
        while(a)
        {
            r = 10 * r + (a % 10);
            a /= 10;
        }
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        dp[r] = min(dp[r], dp[i] + 1);
    }
    for(int i = 1; i < 14; ++i)
        p10[i] = 10ll * p10[i - 1];
    int t;
    scanf("%d", &t);
    forn(i, t)
        printf("Case #%d: %lld\n", i + 1, solve());
    return 0;
}
