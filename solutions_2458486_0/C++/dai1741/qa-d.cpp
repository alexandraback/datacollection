#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define rep(i,n) for (int i=0; i < (n); i++)

int n, k;
VI keys;
VVI chestKeys;
VI t;
VI prevChest;
bool dfs(int curState, int prev) {
  if (prevChest[curState]) return false;
  prevChest[curState] = prev;
  if (curState == (1 << n) - 1) return true;

  rep (i, n) {
    if ((curState & (1 << i)) != 0 || keys[t[i]] == 0) continue;
    // go this!!!
    keys[t[i]]--;
    rep(j, chestKeys[i].size()) keys[chestKeys[i][j]]++;
    if (dfs(curState | (1 << i), i)) return true;

    // undo
    keys[t[i]]++;
    rep(j, chestKeys[i].size()) keys[chestKeys[i][j]]--;
  }
  return false;
}

void solve() {
  cin >> k >> n;
  chestKeys = VVI(n);
  keys = VI(200);
  t = VI(n);
  prevChest = VI(1 << n);

  rep(i, k) {
    int key;
    cin >> key;
    keys[key-1]++;
  }

  rep(i, n) {
    cin >> t[i];
    t[i]--;
    int numK;
    cin >> numK;
    chestKeys[i] = VI(numK);
    rep (j, numK) {
      cin >> chestKeys[i][j];
      chestKeys[i][j]--;
    }
  }
  if (!dfs(0, -1)) {
    cout << "IMPOSSIBLE"; 
    return;
  }
  VI ans;
  for (int cur = (1 << n) - 1; cur != 0; cur &= ~(1 << prevChest[cur])) {
    ans.push_back(prevChest[cur]+1);
  }
  rep (i, n-1) cout << ans[n-1-i] << " ";
  cout << ans[0];
}

int main() {
  int t;
  cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
    cout << endl;
  }
  return 0;
}