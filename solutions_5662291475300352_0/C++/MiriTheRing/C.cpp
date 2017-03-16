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
#define xx first
#define yy second

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin >> TC;
  FOR(tc, 1, TC+1){
    ll N;
    vector<pair<ll, ll>> p(2, mp(-1,-1));
    cin >> N;
    FOR(i,0,N){
      ll d, h, m;
      cin >> d >> h >> m;
      FOR(i,0,h){
        if(p[0].xx == -1){
          p[0] = mp(d,-m);
        }
        else{
          p[1] = mp(d,-m);
        }
        m++;
      }
    }
    sort(all(p));
    p[0].yy *= -1;
    p[1].yy *= -1;
    ll res = 2;
    if(p[1].yy < p[0].yy)
      res = 1;
    if(p[0].yy < p[1].yy + ((360.0-p[1].xx)/p[1].yy * (p[0].xx + 360)))
      res = 1;
    if(p[0].yy < p[1].yy + (360.0-p[1].xx)/p[1].yy * 360)
      res = 0;
    cout << "Case #" << tc << ": " << res << endl;
  }
}
