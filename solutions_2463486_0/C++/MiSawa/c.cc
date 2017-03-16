#include <iostream>//{{{
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <utility>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <memory>
#include <sstream>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cassert>
#include <ctime>
#include <cctype>//}}}
#define REP(i,b,n) for(int i=(int)(b);i<(int)(n);++i)//{{{
#define rep(i,n) REP(i,0,n)
#define repsz(i,v) rep(i,sz(v))
#define let(v, x) typeof(x) v = (x)
#define foreach(i,v) for(let(i, (v).begin());i!=(v).end();i++)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) ((int)(x).size()) //}}}
static const int INF = 1<<25;
static const double EPS = 1e-5;
using namespace std;//{{{
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;//}}}
template<typename T> ostream& out(T b, T e, ostream& os=cout){ //{{{
    for(; b != e; ++b != e && os << ", ")os << *b; return os;
}
template<class T> T mineq(T &a, const T &b){ return a = min(a, b); }
template<class T> T maxeq(T &a, const T &b){ return a = max(a, b); } //}}}
template<typename T> T s_to(string s){ //{{{
    stringstream ss;
    T res;
    ss << s;
    ss >> res;
    return res;
} //}}}

inline ll isqrt(ll n){//{{{
    ll t, res=0, b=0x80000000LL, s = 31;
    do{
        if(n >= (t = (((res<<1) + b) << s--))){
            res += b;
            n -= t;
        }
    }while(b >>= 1);
    return res;
}//}}}
bool inRange(ll a, ll x, ll b){ //{{{
    return a <= x && x < b;
} //}}}

bool is_parindrome(ll n){
    ll _n = n;
    ll x = 0;
    while(n){
        x *= 10;
        x += n % 10;
        n /= 10;
    }
    return x == _n;
}

vector<ll> ans;
void pre(){
    ll mx = (ll)(1E14) + 10;
    for(ll i = 1; i*i < mx; ++i){
        if(is_parindrome(i) && is_parindrome(i*i)) ans.pb(i);
    }
}

void solve(){
    ll a, b;
    cin >> a >> b;
    ++b;
    int res = 0;
    repsz(i, ans) if(inRange(a, ans[i]*ans[i], b)) ++res;
    cout << res << endl;
}

int main(){
    pre();
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);
    cout.setf(ios::fixed); cout.precision(10);
    string s;
    getline(cin, s);
    int T = s_to<int>(s);
    rep(i, T){
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
    return 0;
}
/* vim:set foldmethod=marker commentstring=//%s : */
