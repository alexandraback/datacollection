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

int N;
vi initial;
vi key;
vvi inside;
bool dose_memo[1<<20];
bool memo[1<<20];

bool can_open(int A, int T){//{{{
    int cnt[210] = {};
    repsz(i, initial) ++cnt[initial[i]];
    rep(i, N) if(A>>i&1){
        --cnt[key[i]];
        repsz(j, inside[i]) ++cnt[inside[i][j]];
    }
    return cnt[key[T]] > 0;
}//}}}

vi result;
bool dfs(int A){//{{{
    if(dose_memo[A]) return memo[A];
    dose_memo[A] = true;
    if(A == (1<<N)-1) return memo[A] = true;
    rep(i, N) if(!(A>>i&1)) if(can_open(A, i)){
        if(dfs(A|(1<<i))){
            result.pb(i);
            return memo[A] = true;
        }
    }
    return memo[A] = false;
}//}}}

void init(){//{{{
    initial.clear(); key.clear(); inside.clear();
    result.clear();
    rep(A, 1<<20) dose_memo[A] = false;
}//}}}

void check(){
    int cnt[210] = {};
    repsz(k, initial) ++cnt[initial[k]];
    repsz(i, result){
        assert(cnt[key[result[i]]] > 0);
        --cnt[key[result[i]]];
        repsz(j, inside[result[i]]) ++cnt[inside[result[i]][j]];
    }
}

void solve(){
    int K;
    cin >> K >> N;
    initial.resize(K);
    rep(i, K) cin >> initial[i];

    key.resize(N); inside.resize(N);
    rep(i, N){
        cin >> key[i];
        int m; cin >> m;
        inside[i].resize(m);
        rep(j, m) cin >> inside[i][j];
    }

    if(dfs(0)){
        reverse(all(result));
        check();
        repsz(i, result){
            if(i) cout << " ";
            cout << result[i] + 1;
        }
        cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
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
        init();
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
    return 0;
}
/* vim:set foldmethod=marker commentstring=//%s : */
