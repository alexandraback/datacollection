/*
 * dnkywin's template
 */
#include <bits/stdc++.h>
using namespace std;

/* lol */
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef stringstream ss;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mset(t,v) memset((t),(v),sizeof(t))
#define clr(t) mset(t, 0)
#define print(a) cout << #a << ": " << a << endl;
#define print_arr(a,n) rep(_##i, n) cout << #a << "[" << _##i << "]: " << a[_##i] << endl

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define repr(i,n) for(int i=(n);--i>=0;)
#define rep2(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define repr2(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repe(i,l,r) for(int i=(l),_##i=(r);i<_##i;i<<=1)
#define forl(it, ll) for(auto it: ll)

#define vt(args...) vector<tuple<args>>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

#ifdef DEBUG
#define _(cmd) cmd
#else
#define _(cmd) 
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

int m, n;
void solve(void);
int main(){
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);
  int T;
  cin >> T;
  time_t start = clock();
  time_t cur;
  rep2(tt, 1, T + 1) {
    cout << "Case #" << tt << ": ";
    try {
      solve();
    } catch (...) {
      cerr << "Test Case " << tt << " failed." << endl;
      return 1;
    }
    cur = clock();
    if (cur > start + CLOCKS_PER_SEC) {
      cerr << "Test Case " << tt << " done after " << ((cur - start) * 1.0 / CLOCKS_PER_SEC) << "seconds\n";
    }

    fflush(stderr);
    fflush(stdout);
  }
  return 0;
}

/* end template */

const int maxn = 1005;
bool vis[maxn];
int nxt[maxn];
int deg[maxn];
int path[maxn];
vi cyc[maxn];
int q[maxn];
int cnum;

void dfs(int i) {
  if (deg[i] == 0) return;
  deg[i] = 0;
  cyc[cnum].pb(i);
  dfs(nxt[i]);
}

int best1(int cn) {
  int ret = 0;
  for (int x: cyc[cn]) ret = max(ret, path[x]);
  return ret + cyc[cn].size();
}

int best2(int cn) {
  int ret = 0;
  int k = cyc[cn].size();
  rep(i, k) {
    ret = max(ret, path[cyc[cn][i]] + path[cyc[cn][(i + 1) % k]]);
  }
  return ret + k;
}

void solve() {
  /* %%% */
  memset(vis, 0, sizeof(vis));
  memset(deg, 0, sizeof(deg));
  memset(path, 0, sizeof(path));
  rep(i, maxn) cyc[i].clear();
  cin >> n;
  rep(i, n) {
    cin >> nxt[i];
    nxt[i]--;
    deg[nxt[i]]++;
  }
  int lo = 0, hi = 0;
  rep(i, n) {
    if (deg[i] == 0) q[hi++] = i;
  }
  while(lo < hi) {
    int t = q[lo++];
    deg[nxt[t]]--;
    if (deg[nxt[t]] == 0)
      q[hi++] = nxt[t];
    path[nxt[t]] = max(path[nxt[t]], 1 + path[t]);
  }
  cnum = 0;
  rep(i, n) {
    if (deg[i]) {
      dfs(i);
      cnum++;
    }
  }
  /*
  rep(i, cnum) {
    cout << "CYCLE " << i + 1 << ":";
    for (int x: cyc[i]) cout << " " << x + 1;
    cout << endl;
  }
  */
  int ans = 0;
  rep(i, cnum) ans = max(ans, (int)cyc[i].size());
  int ans2 = 0;
  rep(i, n) {
    if (cyc[i].size() == 2) {
      ans2 += best2(i);
    }
  }
  ans = max(ans, ans2);
  cout << ans << endl;
}


