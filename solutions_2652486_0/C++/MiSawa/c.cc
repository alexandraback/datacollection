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

int r, n, m, k;
vi in;
vi st;
bool dfs(int i){
    if(i == 0){
        set<int> a;
        rep(A, 1<<n){
            int t = 1;
            rep(j, n) if(A>>j&1) t *= st[j];
            a.insert(t);
        }
        rep(j, k) if(!a.count(in[j])) return false;
        return true;
    }else{
        for(int x=2; x <= m; ++x){
            st.pb(x);
            if(dfs(i-1)) return true;
            st.pop_back();
        }
    }
    return false;
}
void solve2(){
    in.resize(k);
    rep(i, k) cin >> in[i];
    st.clear();
    dfs(n);
    rep(i, n) cout << st[i];
    cout << endl;
}
void solve(){
    cin >> r >> n >> m >> k;
    rep(i, r){
        solve2();
    }
}

int main(){
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);
    cout.setf(ios::fixed); cout.precision(10);
    string s;
    getline(cin, s);
    int T = s_to<int>(s);
    rep(i, T){
        cout << "Case #" << (i+1) << ":" << endl;
        solve();
    }
    return 0;
}
/* vim:set foldmethod=marker commentstring=//%s : */
