/*
 * c.cpp
 *
 *  Created on: May 3, 2014
 *      Author: istrandjev
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <functional>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;
vector<string> zips;
bool pred(int x, int y) {
  return zips[x] > zips[y];
}

vector<vector<int> > ne;
string res;

struct help {
  int val;
  help(int v) : val(v) {}
  bool operator<(const help& other) const {
    return zips[val] > zips[other.val];
  }
};

bool can(const vector<vector<int> >& ne, const vector<int>& cur, const vector<char>& non_usable, vector<char> vis) {
  queue<int> tc;
  for (int i = 0; i < (int)cur.size(); ++i) {
    tc.push(cur[i]);
    vis[cur[i]] = 1;
  }
  while (!tc.empty()) {
    int c = tc.front();tc.pop();
    for (int i = 0; i < (int)ne[c].size(); ++i) {
      if (!vis[ne[c][i]] && !non_usable[ne[c][i]]) {
        vis[ne[c][i]] = 1;
        tc.push(ne[c][i]);
      }
    }
  }
  for (int i = 0; i < (int)vis.size(); ++i) {
    if (!vis[i]) {
      return false;
    }
  }
  return true;
}
int main() {
  freopen("google.in", "r", stdin);
  freopen("google.out", "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    int n, m;
    cin >> n >> m;
    zips.clear();
    zips.resize(n);
    string temp;
    getline(cin, temp);
    for (int i = 0; i < n; ++i) {
      getline(cin, temp);
      zips[i] = temp;
    }
    ne.clear();
    ne.resize(n);

    for (int i = 0; i < m; ++i) {
      int f, t;
      scanf("%d %d", &f, &t);
      f--;
      t--;
      ne[f].push_back(t);
      ne[t].push_back(f);
    }

    int root = 0;
    for (int i = 0; i < (int)zips.size(); ++i) {
      if (zips[i] < zips[root]) {
        root = i;
      }
    }

    int lft = n- 1;
    vector<char> vis(n, 0);
    vis[root] = 1;
    string res = zips[root];
    vector<int> cur;
    cur.push_back(root);
    vector<char> non_usable(n, 0);
    while ((int)res.size() < 5 * n) {
      int at_most = 0;
      for (int i = 1; i < (int)cur.size(); ++i) {
        vector<int> temp(cur.begin(), cur.begin() + (int)cur.size() - i);
        non_usable[cur[(int)cur.size() - i]] = 1;
        if (!can(ne, temp, non_usable, vis)) {
          break;
        }
        at_most++;
      }
      for (int i = 0; i < at_most; ++i) {
        non_usable[cur[cur.size() - i - 1]] = 0;
      }
      int dadi = -1;
      int best = -1;
      for (int i = 0; i <= at_most; ++i) {
        int v = cur[cur.size() - 1 - i];
        for (int j = 0; j < (int)ne[v].size(); ++j) {
          int u = ne[v][j];
          if (!vis[u] && !non_usable[u]) {
            if (best == -1 || zips[u] < zips[best]) {
              dadi = cur.size() - 1 - i;
              best = u;
            }
          }
        }
      }

      res += zips[best];
      for (int i = cur.size() - 1; i > dadi; --i) {
        non_usable[cur[i]] = 1;
      }
      cur.erase(cur.begin() + dadi +  1, cur.end());
      cur.push_back(best);
      vis[best] = 1;
      lft--;
    }

    cout << "Case #" << it << ": " << res << endl;
  }
  return 0;
}


