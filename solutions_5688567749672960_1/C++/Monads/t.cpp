#include<bits/stdc++.h>
#define sz(x) int((x).size())

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> PII;
typedef std::pair<ll,ll> PLL;

template<class T> inline T pr(T x) { return --x; }
template<class T> inline T nx(T x) { return ++x; }

const ll maxn = 20;
ll n,a[maxn],ans,len,b[maxn];

int main() {
    ll i,j,k,t,tt,T,Test,flag;
    scanf("%lld",&Test);
    for (T=1; T<=Test; ++T) {
        scanf("%lld",&n);
        if (n%10==0) --n,flag = true;
        else flag = false;
        ans = n;
        len = 0; t = n;
        while (t) b[++len] = t%10,t/=10;
        reverse(b+1,b+len+1);
        for (i=2; i<len; ++i) {
            a[1] = 1; for (j=2; j<=i/2; ++j) a[j] = 0;
            for (j=i/2+1; j<=i; ++j) a[j] = 9;
            t = tt = 0;
            for (j=1; j<=i; ++j) t = t*10 + a[j];
            for (j=i; j>=1; --j) tt = tt*10 + a[j];
            if (tt>t) ans -= tt-t-1;
        }
        a[1] = 1;
        for (j=2; j<=len/2; ++j) a[j] = 0;
        for (j=len/2+1; j<=len; ++j) a[j] = b[len-j+1];
        t = tt = 0;
        for (j=1; j<=len; ++j) t = t*10 + a[j];
        for (j=len; j>=1; --j) tt = tt*10 + a[j];
        if (tt>t) ans -= tt-t-1;
        if (flag) ++ans;
        printf("Case #%lld: %lld\n",T,ans);
    }

    return 0;
}
