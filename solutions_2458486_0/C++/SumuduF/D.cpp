#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> VI;

int solve(int n, const map<int, int> &keys, const VI &chestT, const vector<VI> &sp, VI &memo, int mask = 0) {
  if (memo[mask] == -1) {
    map<int, int> curK = keys;
    for (int i = 0; i < n; ++i)
      if (mask & (1 << i)) {
        curK[chestT[i]] -= 1;
        for (size_t j = 0; j < sp[i].size(); ++j)
          curK[sp[i][j]] += 1;
        }

    memo[mask] = -2;
    for (int i = 0; (memo[mask] < 0) && (i < n); ++i)
      if (!(mask & (1 << i)) && (curK[chestT[i]] > 0) && (solve(n, keys, chestT, sp, memo, mask | (1 << i)) >= 0))
        memo[mask] = i;
    }
  return memo[mask];
  }

int main() {
  int nc; cin >> nc;
  for (int curC = 1; curC <= nc; ++curC) {
    int k, n; cin >> k >> n;

    map<int, int> keys;
    for (int i = 0; i < k; ++i) {
      int a; cin >> a;
      keys[a] += 1;
      }

    VI chestType(n); vector<VI> spoils(n);
    for (int i = 0; i < n; ++i) {
      int ns; cin >> chestType[i] >> ns;

      spoils[i].resize(ns);
      for (int j = 0; j < ns; ++j)
        cin >> spoils[i][j];
      }

    int maxM = (1 << n);
    VI memo(maxM, -1); memo[maxM-1] = 0;

    cout << "Case #" << curC << ":";
    if (solve(n, keys, chestType, spoils, memo) < 0)
      cout << " IMPOSSIBLE\n";
    else {
      int curM = 0;
      while (curM != maxM-1) {
        cout << ' ' << (memo[curM]+1);
        curM |= (1 << memo[curM]);
        }
      cout << '\n';
      }
    }
  }

