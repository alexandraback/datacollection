#define _CRT_SECURE_NO_WARNINGS
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
//#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define all(c) (c).begin(), (c).end()
#define loop(i,a,b) for(ll i=a; i<ll(b); i++)
#define rep(i,b) loop(i,0,b)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
template<class T> ostream & operator<<(ostream & os, vector<T> const &);
template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":" ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream & os, tuple<T...> const & t){ _ot<0>(os, t); return os; }
template<class T, class U> ostream & operator<<(ostream & os, pair<T,U> const & p){ return os << "(" << p.first << ", " << p.second << ") "; }
template<class T> ostream & operator<<(ostream & os, vector<T> const & v){ rep(i,v.size()) os << v[i] << (i+1==(int)v.size()?"":" "); return os; }
template<class T> inline bool chmax(T & x, T const & y){ return x<y ? x=y,true : false; }
template<class T> inline bool chmin(T & x, T const & y){ return x>y ? x=y,true : false; }
#ifdef DEBUG
#define dump(...) (cerr << #__VA_ARGS__ << " = " << mt(__VA_ARGS__) << " [" << __LINE__ << "]" << endl)
//#define dump(x) (cerr << #__VA_ARGS__ << " = " << x << " [" << __LINE__ << "]" << endl)
#else
#define dump(...)
#endif
// ll const mod = 1000000007;
// ll const inf = 1LL<<60;

ll solve(int C, vector<int> X, int V){
    dump(X);
    int D = X.size();
    vector<int> have(V+1);
    vector<int> ok(V+1);
    rep(i,X.size()) have[X[i]] = true;
    ok[0] = true;
    rep(i,X.size()){
        for(int j=V;j>=0;j--){
            if(j-X[i] >= 0 && ok[j-X[i]]){
                ok[j] = true;
            }
        }
    }
    vi add;
    dump(ok);
    loop(i,1,V+1){
        if(have[i] || ok[i]) continue;
        add.pb(i);
        for(int j=V;j>=0;j--){
            if(j-i >= 0 && ok[j-i]){
                ok[j] = true;
            }
        }
    }
    return add.size();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    signed T;
    cin >> T;
    rep(i,T){
        int C,D,V;
        cin >> C >> D >> V;
        vector<int> X(D);
        rep(i,D) cin >> X[i];
        ll ans = solve(C,X,V);
        printf("Case #%d: %lld\n",(int)i+1,ans);
    }
}
