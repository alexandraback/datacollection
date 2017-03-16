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

// int dp[1<<10][1<<10];

// int C,W;
// int rec(int yes, int no){
//     int ym = 1000;
//     int yM = 0;
//     if(
//     rep(i,C){
//         if(yes>>i&1){
//             ym = min<int>(ym,i);
//             yM = max<int>(yM,i);
//         }
//     }
//     int ans = 0;
//     loop(i,ym,yM+1){
//         if(no>>i&1) return -1;
//     }
// }

// int solve(int C, int W){

// }

int solve(int C, int W){
    int ans = C/W-1+W;
    if(C%W==0){
        ans = max(ans, C/W+W-1);
    } else {
        ans = max(ans, C/W+W);
    }
    return ans;
}

int solve(int R, int C, int W){
    int ans = C/W*(R-1) + solve(C,W);
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    signed T;
    cin >> T;
    rep(i,T){
        int R,C,W;
        cin >> R >> C >> W;
        int ans = solve(R,C,W);
        printf("Case #%d: %d\n",(int)i+1,ans);
    }
}
