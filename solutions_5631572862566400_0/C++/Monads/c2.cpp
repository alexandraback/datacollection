#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll maxn = 1210,maxm = 22;
ll Test,n,ans;
ll a[maxn],vs[maxm],opt[maxm],cnt,b[maxn];
set<ll> s[maxn];

template<class T>
inline void get(T &n) {
    char c = getchar();
    while (c!='-' && (c<'0' || c>'9')) c = getchar();
    n = 0; T s = 1; if (c=='-') s = -1,c = getchar();
    while (c>='0' && c<='9') n*=10,n+=c-'0',c=getchar();
    n *= s;
}

void hungary(ll x) {
    b[++cnt] = x; vs[x] = 1;
    if (vs[a[x]]) {
        if (a[x] == b[1] || a[x] == b[cnt-1]) {
            if (ans < cnt) ans = cnt;
        }
        if (a[x] == b[cnt-1]) {
            for (ll i = 1;i <= n; i++) if (!vs[i]) hungary(i);
        }
    }
    else hungary(a[x]);
    --cnt;
    vs[x] = 0;
}

int main() {
    get(Test);
    for (ll Ti = 1;Ti <= Test; Ti++) {
        get(n);
        for (ll i = 1;i <= n; i++) get(a[i]);
        ans = 0;
        for (ll i = 1;i <= n; i++) {
            memset(vs,0,sizeof vs); memset(opt,0,sizeof opt);
            cnt = 0;
            hungary(i);
        }
        printf("Case #%lld: %lld\n",Ti,ans);
    }

}
