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

int k, c, s;
ll get_witness(int a) {
  ll ret = 0;
  rep(i, c) {
    ret = ret * k;
    if (i + a < k) ret += i + a;
  }
  return ret + 1;
}
void solve() {
  /* %%% */
  cin >> k >> c >> s;
  if (s * c < k) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  vll nums;
  rep(i, s) {
    nums.pb(get_witness(i * c));
  }
  sort(all(nums));
  nums.erase(unique(all(nums)), nums.end());
  for (ll x: nums) cout << x << " ";
  cout << endl;
}
