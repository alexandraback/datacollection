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

vector<int> order;
string s[50];
int g[50][50];

string solve() {
  int n,m;
  cin >> n >> m;
  REP(i,n) cin >> s[i];
  order.resize(n);
  iota(ALL(order),0);
  sort(ALL(order), [&](int i, int j) {return s[i]<s[j];});
  memset(g,0,sizeof(g));
  REP(i,m) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    g[a][b]=g[b][a]=1;
  }
  ll used = 0;
  string ans;
  vector<int> v;
  REP(i,n) {
    REP(j,n) {
      int id = order[j];
      if (used>>id&1) continue;
      vector<int> tmp(v);
      while(tmp.size()) {
        if (g[id][tmp.back()]) {
          break;
        } else tmp.pop_back();
      }
      if (i && tmp.size() == 0) continue;
      tmp.push_back(id);
      queue<int> Q;
      vector<int> visited(n);
      FOR(it, tmp) {
        visited[*it] = 1;
        Q.push(*it);
      }
      int cnt = i-(tmp.size()-1);
      while(!Q.empty()) {
        int p = Q.front(); Q.pop();
        cnt++;
        REP(k,n) {
          if (!g[p][k]) continue;
          if (visited[k] || (used>>k&1)) continue;
          visited[k] = 1;
          Q.push(k);
        }
      }
      if (cnt == n) {
        v = tmp;
        ans += s[id];
        used |= 1LL<<id;
        break;
      }
    }
  }
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
