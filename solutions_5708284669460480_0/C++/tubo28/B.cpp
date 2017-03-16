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

int cnt(string have, string target){
    int res = 0;
    rep(i,have.size()-target.size()+1){
        if(have.substr(i,target.size())==target) res++;
    }
    return res;
}

double solve(string keys, string target, int S){
    ll pat = 1;
    rep(i,S) pat *= keys.size();
    ll mx = 0, sum = 0;
    rep(mask,pat){
        string r(S,' ');
        int t = mask;
        rep(i,S){
            r[i] = keys[t%keys.size()];
            t/=keys.size();
        }
        ll c = cnt(r,target);
        sum += c;
        mx = max(mx,c);
    }
    return (double)mx-(double)sum/pat;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    signed T;
    cin >> T;
    rep(i,T){
        int K,L,S;
        cin >> K >> L >> S;
        string keys; cin >> keys;
        string target; cin >> target;
        double ans = solve(keys, target, S);
        printf("Case #%d: %lf\n",(int)i+1,ans);
    }
}
