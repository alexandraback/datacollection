#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 20;

vector<int> inside[N];
int need[N];
int pick[1 << N];
int dp[1 << N];
int target;

int go(int curr, map<int, int>& keys) {
  if (curr == target) return 1;
  if (dp[curr] >= 0) return dp[curr];
  for (int i = 0, m = 1; i < N; i++, m <<= 1) if ((curr & m) == 0) {
    if (keys[need[i]] == 0) continue;
    keys[need[i]]--;
    for (int j = 0; j < inside[i].size(); j++) keys[inside[i][j]]++;
    int res = go(curr | m, keys);
    for (int j = 0; j < inside[i].size(); j++) keys[inside[i][j]]--;
    keys[need[i]]++;
    if (res) {
      pick[curr] = i;
      return dp[curr] = 1;
    }
  }
  return dp[curr] = 0;
}

int main() {
  int cases; cin >> cases;
  for (int caseNo = 1; caseNo <= cases; caseNo++) {
    int k, n; cin >> k >> n;
    map<int, int> keys;

    for (int i = 0; i < k; i++) {
      int type; cin >> type;
      keys[type]++;
    }

    for (int i = 0; i < n; i++) {
      cin >> need[i];
      int x; cin >> x;
      inside[i].clear();
      for (int j = 0; j < x; j++) {
        int type; cin >> type;
        inside[i].push_back(type);
      }
    }

    memset(dp, 0xff, sizeof(dp));
    target = (1 << n) - 1;

    int res = go(0, keys);
    cout << "Case #" << caseNo << ":";
    if (!res)
      cout << " IMPOSSIBLE" << endl;
    else {
      int curr = 0;
      while (curr != target) {
        int next = pick[curr];
        cout << " " << (next+1);
        curr |= (1 << next);
      }
      cout << endl;
    }
  }
  return 0;
}