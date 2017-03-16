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
 
#define Nmax (10000000)

map<ll,ll> in;

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

ll find(ll todo){
  auto it = in.upper_bound(todo);
  if(it == in.begin()){
    return todo;
  }
  it--;
  if(it->second == -1){
    it->second = find(reverse(it->first)) + 1;
  }
  return it->second + (todo - it->first);
}

bool awesome(ll i){
  ll enc = 0;
  while(i){
    enc += i%10;
    i /= 10;
  }
  if(enc > 1)
    return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll log = 1;
  ll fac = 10;
  FOR(i,1,Nmax+1){
    ll i1 = (i * fac) + 1;
    if(reverse(i1) < i1)
    in[i1] = -1;
      i1 = (i * (fac*10)) + 1;
      if(reverse(i1) < i1)
      in[i1] = -1;
    if(awesome(i+1)){
      fac *= 10; log++;
    }
  }
  ll TC;
  cin >> TC;
  FOR(tc, 1, TC+1){
    ll N;
    cin >> N;
    cout << "Case #" << tc << ": " << find(N) << endl;
  }
}
