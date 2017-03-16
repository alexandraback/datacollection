// {{{
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<int(n);++i)
template<class T>inline void check_min(T&a,T b){if(b<a)a=b;}
template<class T>inline void check_max(T&a,T b){if(a<b)a=b;}
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;
// }}}

map<string, int> mp;
inline int get_id(const string &s) {
  if (mp.count(s)) return mp[s];
  int n = SZ(mp);
  return mp[s] = n;
}

const int MAX_N = 2048;
VI ed[MAX_N];
int outd[MAX_N], ind[MAX_N];
bool lo[MAX_N], ro[MAX_N];

int rm[MAX_N], ts[MAX_N], stamp;
int augment(int u) {
  for (int v: ed[u]) {
    if (ts[v] == stamp) continue;
    ts[v] = stamp;
    if (rm[v] == -1 || augment(rm[v])) {
      rm[v] = u;
      return 1;
    }
  }
  return 0;
}

int solve() {
  mp.clear();
  int n;
  cin >> n;
  fill(ed, ed + MAX_N, VI());
  fill(outd, outd + MAX_N, 0);
  fill(ind, ind + MAX_N, 0);
  REP (i, n) {
    string a, b;
    cin >> a >> b;
    int x = get_id(a);
    int y = get_id(b);
    ed[x].PB(y);
    ++outd[x], ++ind[y];
  }
  fill(rm, rm + MAX_N, -1);
  REP (i, SZ(mp)) {
    ++stamp;
    augment(i);
  }
  fill(lo, lo + MAX_N, false);
  fill(ro, ro + MAX_N, false);
  int ans = 0;
  REP (i, SZ(mp)) {
    int j = rm[i];
    if (j == -1) continue;
    lo[j] = ro[i] = true;
    ++ans;
  }
  REP (i, SZ(mp)) {
    if (outd[i] && !lo[i]) ++ans;
    if (ind[i] && !ro[i]) ++ans;
  }
  return n - ans;
}

int main() {
  int n_case;
  cin >> n_case;
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %d\n", index, solve());
  }
  return 0;
}
