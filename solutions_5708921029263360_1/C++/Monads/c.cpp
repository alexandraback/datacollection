#include<bits/stdc++.h>
#define rep(i,s,t) for (ll i=(s); i<=(t); ++i)
#define dep(i,t,s) for (ll i=(t); i>=(s); --i)
#define i first
#define j second
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front
#define sz(x) ll((x).size())
#define p(i) (1LL<<((i)-1))
#define w(x,i) ((x)&p(i))
#define inf ll(~0u>>1)

using namespace std;

template<class T> inline T pr(T x) { return --x; }
template<class T> inline T nx(T x) { return ++x; }
template<class T> inline T sqr(T x) { return x*x; }

template<class T>
inline void get(T &n) {
    char c = getchar();
    while (c!='-' && (c<'0' || c>'9')) c = getchar();
    n = 0; T s = 1; if (c=='-') s = -1,c = getchar();
    while (c>='0' && c<='9') n*=10,n+=c-'0',c=getchar();
    n *= s;
}

typedef long long ll;
typedef pair<ll,ll> PII;

const ll maxn = 12;
ll j,p,s,K,f[maxn][maxn][maxn],a,b,c;

ll nx(ll x) {
    x += 1;
    if (x > s) x = 1;
    return x;
}

int main() {
    ll i,j,k,t,tt,Test;
    get(Test);
    rep(Ti,1,Test) {
        get(j); get(p); get(s); get(K);
        a = j; b = p; c = min(s,K);
        printf("Case #%lld: %lld\n",Ti,a*b*c);
        memset(f,0,sizeof(f));
        rep(k,1,c) {
            f[0][1][k] = nx(f[0][1][k-1]);
            rep(i,1,a) {
                f[i][1][k] = nx(f[i-1][1][k]);
                rep(j,2,b) f[i][j][k] = nx(f[i][j-1][k]);
            }
        }
        rep(i,1,a) rep(j,1,b) rep(k,1,c) {
            printf("%lld %lld %lld\n",i,j,f[i][j][k]);
        }
    }

    return 0;
}
