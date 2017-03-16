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

ll dp[100][2][2][2];

string func(ll x) {
  if (x == 0) return "0";
  string res;
  while(x) {
    if (x&1) res += '1';
    else res += '0';
    x>>=1;
  }
  reverse(ALL(res));
  return res;
}

ll solve() {
  ll A,B,C;
  cin >> A >> B >> C;
  string a = func(A);
  string b = func(B);
  string c = func(C);
  int n = max({a.size(), b.size(), c.size()});
  a = string(n-a.size(),'0') + a;
  b = string(n-b.size(),'0') + b;
  c = string(n-c.size(),'0') + c;
  memset(dp,0,sizeof(dp));
  dp[0][0][0][0] = 1;
  REP(i,n) {
    REP(l1,2) {
      REP(l2,2) {
        REP(l3,2) {
          REP(j,2) {
            if (j && !l1 && a[i]=='0') continue;
            REP(k,2) {
              if (k && !l2 && b[i]=='0') continue;
              if ((j&k) && !l3 && c[i]=='0') continue;
              int t1 = l1||j<a[i]-'0';
              int t2 = l2||k<b[i]-'0';
              int t3 = l3||(j&k)<c[i]-'0';
              dp[i+1][t1][t2][t3] += dp[i][l1][l2][l3];
            }
          }
        }
      }
    }
  }
  return dp[n][1][1][1];
}
int main() {
  int T;
  cin >> T;
  REP(cs,T) {
    ll ans = solve();
    printf("Case #%d: %lld\n", cs+1, ans);
  }  
}
