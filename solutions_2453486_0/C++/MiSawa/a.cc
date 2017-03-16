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
#define sz(x) ((int)(x).size())
#define out(v) copy(all(v), ostream_iterator<typeof((v)[0])>(cout, " ")); cout << endl; //}}}
static const int INF = 1<<25;
static const double EPS = 1e-5;
using namespace std;//{{{
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;//}}}
template<class T> T mineq(T &a, const T &b){ return a = min(a, b); }
template<class T> T maxeq(T &a, const T &b){ return a = max(a, b); }
template<typename T> T s_to(string s){ //{{{
    stringstream ss;
    T res;
    ss << s;
    ss >> res;
    return res;
} //}}}

bool won(vector<string> board, char c){
    bool flg;

    // check '\'
    flg = true;
    rep(i, 4) if(board[i][i] != c && board[i][i] != 'T') flg = false;
    if(flg) return true;

    // check '/'
    flg = true;
    rep(i, 4) if(board[i][3-i] != c && board[i][3-i] != 'T') flg = false;
    if(flg) return true;

    // check '-'
    rep(i, 4){
        flg = true;
        rep(j, 4) if(board[i][j] != c && board[i][j] != 'T') flg = false;
        if(flg) return true;
    }

    // check '|'
    rep(j, 4){
        flg = true;
        rep(i, 4) if(board[i][j] != c && board[i][j] != 'T') flg = false;
        if(flg) return true;
    }
    return false;
}

void solve(){
    vector<string> board(4);
    rep(i, 4) cin >> board[i];
    if(won(board, 'O')){
        cout << "O won" << endl;
    }else if(won(board, 'X')){
        cout << "X won" << endl;
    }else{
        bool fin = true;
        rep(i, 4) rep(j, 4) if(board[i][j] == '.') fin = false;
        if(fin){
            cout << "Draw" << endl;
        }else{
            cout << "Game has not completed" << endl;
        }
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
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
    return 0;
}
/* vim:set foldmethod=marker commentstring=//%s : */
