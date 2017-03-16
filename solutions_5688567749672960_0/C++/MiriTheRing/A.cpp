#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
 
const ll oo = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-9;
 
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = ll(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) { if(1) fprintf(stderr, __VA_ARGS__); }
#define DBGDO(X) { if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; }
 
#define Nmax (1000000)

ll reverse(ll x){
  ll res = 0;
  ll cur = 1;
  while(cur < x){
    cur *= 10;
  }
  cur /= 10;
  while(x){
    res += (x%10)*cur;
    cur /= 10;
    x /= 10;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<ll> ans(Nmax+1, oo);
  ans[0] = 0;
  FOR(i,1,Nmax+1){
    ans[i] = min(ans[i], ans[i-1]+1);
    if(reverse(i) > i){
      ans[reverse(i)] = min(ans[reverse(i)], ans[i] + 1);
    }
  }
  ll TC;
  cin >> TC;
  FOR(tc, 1, TC+1){
    int N;
    cin >> N;
    cout << "Case #" << tc << ": " << ans[N] << endl;
  }
}
