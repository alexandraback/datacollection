//bcw0x1bd2 {{{
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define SZ(x) ((int)((x).size()))
#define ALL(x) begin(x),end(x)
#define REP(i,x) for (int i=0; i<(x); i++)
#define REP1(i,a,b) for (int i=(a); i<=(b); i++)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

#ifdef DARKHH
#define FILEIO(name)
#else
#define FILEIO(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#endif

#ifdef DARKHH
template<typename Iter>
ostream& _out(ostream &s, Iter b, Iter e) {
    s << "[ ";
    for ( auto it=b; it!=e; it++ ) s << *it << " ";
    s << "]";
    return s;
}
template<typename A, typename B>
ostream& operator << (ostream &s, const pair<A,B> &p) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator << (ostream &s, const vector<T> &c) { return _out(s,ALL(c)); }
template<typename T, size_t N>
ostream& operator << (ostream &s, const array<T,N> &c) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator << (ostream &s, const set<T> &c) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator << (ostream &s, const map<A,B> &c) { return _out(s,ALL(c)); }
#endif
// }}}
// Let's Fight! ~OAO~~

int N,F[1024];

void input() {
  cin >> N;
  REP(i,N) {
    cin >> F[i];
    F[i]--;
  }
}

int next(int i, int k) {
  return (i+1)%k;
}
int prev(int i, int k) {
  return (i-1+k)%k;
}
void solve() {
  int ans = 0;
  int per[10];
  REP(i,10) per[i] = i;
  do {
    REP1(len,ans+1,N) {
      int fail = 0;
      REP(ii,len) {
        int i = per[ii];
        if (per[prev(ii,len)] != F[i] and per[next(ii,len)] != F[i]) {
          fail = 1;
          break;
        }
      }
      if (!fail) {
        ans = len;
      }
    }
  } while (next_permutation(per,per+N));
  cout << ans << endl;
}
int main() {
  IOS;
  int nT;
  cin >> nT;
  REP1(cas,1,nT) {
    input();
    cout << "Case #" << cas << ": ";
    solve();
  }

  return 0;
}

