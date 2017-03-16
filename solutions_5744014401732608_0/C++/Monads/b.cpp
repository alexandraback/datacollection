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

const ll maxn = 55;
ll b,m,e[maxn][maxn],S,T,n,f[maxn];

int main() {
    ll i,j,k,t,tt,Test;
    get(Test);
    rep(Ti,1,Test) {
        memset(e,0,sizeof(e));
        memset(f,0,sizeof(f));
        get(b); get(m);
        n = 2;
        e[1][2] = 1;
        f[1] = f[2] = 1;
        while (f[n] < m) {
            ++n;
            rep(i,1,n-1) {
                e[i][n] = 1;
                f[n] += f[i];
            }
        }
        printf("Case #%lld: ",Ti);
        if (n > b) {
            puts("IMPOSSIBLE");
        }
        else {
            puts("POSSIBLE");
            tt = f[n] - m;
            dep(i,n-1,1) if (tt >= f[i]) {
                tt -= f[i];
                e[i][n] = 0;
            }
            rep(i,n,b-1) e[i][i+1] = 1;
            rep(i,1,b) {
                rep(j,1,b) printf("%d",e[i][j]);
                puts("");
            }
        }
    }

    return 0;
}
