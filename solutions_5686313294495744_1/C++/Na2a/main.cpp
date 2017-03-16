/* no greedy easy life */

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <ctime>

#define pii pair<int, int>
  
#define pb push_back
#define mp make_pair
  
#define f first
#define s second
  
using namespace std;

typedef long long ll;
typedef double ld;

typedef vector<int> vi;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int INF = (int) 1e9 + 7;
const int MAXN = (int) 3e5 + 7;

string sa[1010];
string sb[1010];

int n;
int a[1010];
int b[1010];

vector<int> g[1010];
int mt[1010];
bool used[1010];

bool dfs(int v) {
  if (used[v]) return 0;
  used[v] = 1;
  for (auto to : g[v]) {
    if (mt[to] == -1 || dfs(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

int main() {                                       
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("outFast", "w", stdout);
  #endif                                                                                          
  
  int t;
  cin >> t;
  for (int cs = 1; cs <= t; cs++) {
    printf("Case #%d: ", cs);
    cin >> n;
    vector<string> va;
    vector<string> vb;
    for (int i = 0; i < n; i++) {
      cin >> sa[i] >> sb[i];
      va.pb(sa[i]);
      vb.pb(sb[i]);
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    va.resize(unique(va.begin(), va.end()) - va.begin());
    vb.resize(unique(vb.begin(), vb.end()) - vb.begin());
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 0; i < n; i++) {
      a[i] = lower_bound(va.begin(), va.end(), sa[i]) - va.begin();
      b[i] = lower_bound(vb.begin(), vb.end(), sb[i]) - vb.begin();
      //cout<<a[i]<<' '<<b[i]<<endl;
      g[a[i]].pb(b[i]);
    }
    memset(mt, -1, sizeof mt);
    memset(used, 0, sizeof used);
    for (int i = 0; i < va.size(); i++) {
      if (dfs(i)) {
        memset(used, 0, sizeof used);
      }
    }
    int pr = 0;
    for (int i = 0; i < vb.size(); i++)
      if (mt[i] != -1)
        pr++;
    int ans = pr + max(0, (int) va.size() - pr) + max(0, (int) vb.size() - pr);
    cout << n - ans << endl;
  }
  return 0;
}