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
typedef vector<ll> vi;
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

bool solve(){
    ll e, r, n;
    cin >> e >> r >> n;
    vi v(n);
    rep(i, n) cin >> v[i];

    vector<pii> tmp;
    rep(i, n) tmp.pb(mp(v[i], i));
    sort(rall(tmp));

    vi restA(n), restB(n), use(n);
    rep(i, n) restA[i] = e;
    rep(i, n) restB[i] = 0;
    rep(i, n) use[i] = 0;
    rep(i, n){
        ll ni = tmp[i].snd;
        use[ni] = restA[ni] - restB[ni];
        //cout << ni << ": " << use[ni] << " = " << restA[ni] << " - " << restB[ni] << endl;
        restB[ni] += use[ni];
        for(int j = ni; j < n-1; ++j){
            restA[j+1] = min(restA[j] - use[j] + r, e);
        }
        for(int j = ni; j > 0; --j){
            maxeq(restB[j-1], max(restB[j] - r, 0LL));
            //if(i == 1) cout << restB[j] << endl;
        }
    }
    ll res = 0;
    rep(i, n){
        //cout << use[i] << ", ";
        res += use[i] * v[i];
    }
    //cout << endl;
    cout << res << endl;
    return true;
}
int main(){
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
// vim:set foldmethod=marker commentstring=//%s:
