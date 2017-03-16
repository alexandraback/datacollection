#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
#define tpl(...) make_tuple(__VA_ARGS__)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int,int> pii;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
  os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
  os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<int N,class Tuple> void out(ostream&,const Tuple&) {}
template<int N,class Tuple,class,class ...Ts> void out(ostream &os,const Tuple &t) {
	if(N)os<<","; os<<get<N>(t); out<N+1,Tuple,Ts...>(os,t);
}
template<class ...Ts> ostream& operator<<(ostream &os, const tuple<Ts...> &t) {
  os<<"("; out<0,tuple<Ts...>,Ts...>(os,t); os<<")"; return os;
}
template<class T>void output(T *a, int n) {REP(i,n){if(i)cout<<",";cout<<a[i];}cout<<endl;}
template<class T>void output(T *a, int n,int m) { REP(i,n) output(a[i],m);}

string dp[1<<8][8][8];
string s[8];
vector<int> g[8];

string solve() {
  int n,m;
  cin >> n >> m;
  REP(i,n) cin >> s[i];
  REP(i,n) g[i].clear();
  REP(i,m) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  REP(S,1<<n)REP(i,n)REP(j,n)dp[S][i][j]="-1";
  REP(i,n) dp[1<<i][i][i] = s[i];
  typedef bitset<5> Bit;
  REP(S,1<<n) {
    int pc = __builtin_popcount(S);
    REP(tT,1<<pc) {
      int cnt = 0;
      int T = 0;
      REP(i,n) {
        if (S>>i&1) {
          if (tT>>cnt&1) {
            T |= 1<<i;
          }
          cnt++;
        }
      }
      int U = S^T;
      // cout << tpl(Bit(S),Bit(T),Bit(U)) << endl;
      REP(i,n) {
        if (!(T>>i&1)) continue;
        REP(j,n) {
          if (!(T>>i&1)) continue;
          if (dp[T][i][j] == "-1") continue;
          FOR(it, g[j]) {
            if (dp[U][*it][*it] == "-1") continue;
            if (dp[S][i][j] == "-1") dp[S][i][j] = dp[T][i][j] + dp[U][*it][*it];
            else chmin(dp[S][i][j], dp[T][i][j] + dp[U][*it][*it]);
          }
          if (dp[S][i][j] != "-1") {
            if (dp[S][i][i] == "-1") dp[S][i][i] = dp[S][i][j];
            else chmin(dp[S][i][i], dp[S][i][j]);
            // cout << dp[S][i][i] << endl;
          }
        }
      }
    }
  }
  string ans = dp[(1<<n)-1][0][0];
  REP(i,n) chmin(ans,dp[(1<<n)-1][i][i]);
  return ans;
}
int main() {
  int T;
  cin >> T;
  REP(cs,T) {
    string ans = solve();
    printf("Case #%d: ", cs+1);
    cout << ans << endl;
  }  
}
