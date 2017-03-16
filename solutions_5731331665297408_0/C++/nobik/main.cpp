#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>
#include <cassert>
#include <complex>

using namespace std;

/* Constants begin */
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-7;
const double PI = 2*acos(0.0);
const double E = 2.71828;
/* Constants end */

/* Defines begin */
#define pb push_back
#define mp make_pair
#define ll long long
#define double long double
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int (i)=0; (i)<(n); ++(i))
#define random (rand()<<16|rand())
#define sqr(x) (x)*(x)
#define base complex<double>
/* Defines end */

int a[105], b[105];

vector<int> g[105];

string s[105];

vector<string> r;

bool was[105];

int good(int v, int pr = -1){
  int res = 1 << v;
 // cout << v << endl;
  was[v] = true;
  forn(i, g[v].size()){
    int to = g[v][i];
    if(was[to]) continue;
    res |= good(to, v);
  }
  return res;
}

string dfs(int v, int pr = -1){
  string res = s[v];
  vector<string> r;
  forn(i, g[v].size()){
    int to = g[v][i];
    if(to != pr) r.pb(dfs(to, v));
  }
  sort(all(r));
 // cout << s[v] << " + " << " " << g[v].size() << " " << pr << endl;
  forn(i, r.size()) res += r[i];
 /* forn(i, r.size()){
    cout << r[i] << " ";
  }
  cout << endl;*/
  r.clear();
  return res;
}

bool gen(int a[], int n, int k){
  for(int i = k - 1; i >= 0; --i){
    if(a[i] < n - k + i){
      ++a[i];
      for(int j = i + 1; j < k; ++j){
        a[j] = a[j - 1] + 1;
      }
      return true;
    }
  }
  return false;
}

void Solve(){
  int n, m; cin >> n >> m;
  forn(i, n) cin >> s[i];
  forn(i, m){
    cin >> a[i] >> b[i]; --a[i]; --b[i];
  }
  string res = "";
  forn(i, n){
    int cnt = 0;
    int w[15];
    forn(i, n - 1) w[i] = i;
    do{
    //  forn(i, n - 1) cout << w[i] << " ";
    //  cout << endl;
      int cnt = 0;
      forn(i, n) g[i].clear(), was[i] = false;
      forn(i, n - 1){
        g[a[w[i]]].pb(b[w[i]]);
        g[b[w[i]]].pb(a[w[i]]);
      }
      int val = good(i);
     // cout << val << endl;
      if(val != (1 << n) - 1) continue;
     // cout << 1 << endl;
      string now = dfs(i);
      if(res == "") res = now;
      res = min(res, now);
    } while(gen(w, m, n - 1));
  }
  cout << res << "\n";
}

int main(void){
  #ifdef nobik
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  forn(i, t){
    cerr << i << endl;
    cout << "Case #" << i + 1 << ": ";
    Solve();
  }
  return 0;
}
