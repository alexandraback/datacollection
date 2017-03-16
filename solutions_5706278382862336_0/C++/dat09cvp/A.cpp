#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define lfo(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define rfo(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define lfoe(i,v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define st first
#define nd second
#define pb push_back
#define sz(s) (int)(s.size())

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
typedef long long ll;
typedef pair<ll,ll> II;
const int oo=int(1e9)+7;
const int dx[]={1,0,0,-1};
const int dy[]={0,-1,1,0};
const int N=int(1e6)+10;

int tc,n,ans;
ll a,b;
char ch;
map<II,int> mp;

int deg(II a){
    if (a.first==0ll || a.second==a.first) return 0;
    int d=__gcd(a.first,a.second);
    if (d!=0) {a.first/=d;a.second/=d;}
    if (mp[a]>40) return 41;
    mp[a]=41;
    II b=a;
    int cnt=0;
    while (a.first<a.second) {a.first*=2;cnt++;}
    if (cnt>40) return 41;
    int prv=deg(II(a.first-a.second,a.second));
    if (prv>40) return 41;
    if (cnt+prv>40) return 41;
    mp[b]=cnt;
    return cnt;
}

int main(){
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    cin>>tc;
    lfo(tt,1,tc){
        printf("Case #%d: ",tt);
        cin>>a>>ch>>b;
        if (a==0) {puts("impossible");continue;}
        ans=deg(II(a,b));
        if (ans>40) {puts("impossible");continue;}
        printf("%d\n",ans);
        //puts("");
    }
    return 0;
}
