#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <numeric>
#include <limits.h>
#include <assert.h>

using namespace std;

typedef stringstream ss;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef long long ll;

#define FOR(i,n) for(int i = 0; i < n; i++)
#define SZ(v) int(v.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define ITE(v) typeof(v.begin())
#define FORIT(it,v) for(ITE(v) it = v.begin(); it != v.end(); it++)

multiset<int> keys;
vi chest[20];
int chestk[20];
bool memo[1<<20 + 1];
vi res;

bool go(const int n, int mask, multiset<int> k, int v) {
  if (memo[mask] == false) {
    return false;
  }
  if (!k.count(chestk[v])) {
    return false;
  }
  k.erase(k.find(chestk[v]));
  FORIT(it, chest[v]) k.insert(*it);
  
  if (mask == ((1<<n)-1)) {
    res.pb(v);
    return true;
  }

  FOR(i,n) {
    if ((mask&(1<<i)) == 0) {
      if (go(n, mask|(1<<i), k, i)) {
        res.pb(v);
        return true;
      }
    }
  }
  return memo[mask] = false;
}

void solve() {
  res.clear();
  memset(memo, 1, sizeof(memo));
  FOR(i, 20) chest[i].clear();
  keys.clear();
  int nk, nc;
  cin >> nk >> nc;
  FOR(i, nk) {
    int k;
    cin >> k;
    keys.insert(k);
  }
  FOR(i, nc) {
    int n;
    cin >> chestk[i] >> n;
    FOR(j, n) {
      int k;
      cin >> k;
      chest[i].pb(k);
    }    
  }
  FOR(i, nc) {
    if (go(nc, 1<<i, keys, i)) {
      FOR(i, nc) {
        cout << " " << res[nc-i-1] + 1;
      }
      cout << endl;
      return;
    }
  }
  cout << " IMPOSSIBLE" << endl;
}

int main(int argc, char *argv[]) {
  int ntest;
  cin >> ntest;
  FOR(kk, ntest) {
    cout << "Case #" << kk+1 << ":";
    solve();
  }
  return 0;
}
