#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <ctime>
#include <functional>

#define pb push_back
#define mk make_pair
#define sqr(N) ((N)*(N))
#define F first
#define S second
#define maxn 101010

using namespace std;                         

typedef long long ll;

vector < int > g[111];

int i, j, n, m, zip[111], was[111], pos[111];
string zp[111], best;

void check() {
  vector < int > r;
  r.pb(pos[1]);
  for(int i = 2; i <= n; i++) {
    bool ok = false;
    while(!ok && r.size() > 0) {
      int t = r[r.size() - 1];
      for(int j = 0; j < g[t].size(); j++) if(g[t][j] == pos[i]) {
        ok = true;
        r.pb(pos[i]);
        break;
      }
      if(!ok) r.erase(r.end() - 1); 
    }
    if(!r.size()) break;
  }
  if(r.size() > 0) {
    string t = "";
    for(int i = 1; i <= n; i++) t += zp[pos[i]];
    if(best == "" || best > t) best = t;
  }
}

void go(int k, int c) {
  was[k] = 1;
  pos[c] = k;
  if(c == n) {
    check();
  }
  for(int i = 1; i <= n; i++) if(!was[i]) go(i, c + 1);
  was[k] = 0;
}

int main(){
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif
  int t;
  cin >> t;
  for(int test = 1; test <= t; test++) {
    printf("Case #%d: ", test);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
      cin >> zip[i];
      int r = zip[i];
      string c  = "";
      while(r > 0) {
        c += (r % 10) + 48;
        r /= 10;
      }
      reverse(c.begin(), c.end());
      zp[i] = c;
    }
    for(i = 1; i <= n; i++) g[i].clear();
    for(i = 1; i <= m; i++) {
      int a, b;
      cin >> a >> b;
      g[a].pb(b);
      g[b].pb(a);
    }
    int num = 1;
    for(i = 2; i <= n; i++)
      if(zip[i] < zip[num]) num = i;
    best = "";
    memset(was, 0, sizeof(was));
    go(num, 1);
    cout << best << endl;
  }
  return 0;
}         