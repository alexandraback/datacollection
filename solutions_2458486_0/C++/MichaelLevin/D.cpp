#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

#define PROBLEM_ID "D"

bool CanOpen(int mask, map<int, int>& keys, const vi& open, const vector<map<int, int> >& inside, vector<int>& cache) {
  if (mask + 1 == (1 << open.size())) {
    return cache[mask] = 1;
  }
  if (cache[mask] != -1) {
    return cache[mask];
  }
  cache[mask] = 0;
  for (int bit = 0; bit < open.size(); ++bit) {
    if ((mask >> bit) & 1) {
      continue;
    }
    if (keys[open[bit]] > 0) {
      keys[open[bit]]--;
      for (map<int, int>::const_iterator it = inside[bit].begin(); it != inside[bit].end(); ++it) {
        keys[it->first] += it->second;
      }
      if (CanOpen(mask | (1 << bit), keys, open, inside, cache)) {
        cache[mask] = 1;
      }
      keys[open[bit]]++;
      for (map<int, int>::const_iterator it = inside[bit].begin(); it != inside[bit].end(); ++it) {
        keys[it->first] -= it->second;
      }
    }
  }
  return cache[mask];
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n, k;
    cin >> k >> n;
    map<int, int> initial;
    for (int i = 0; i < k; ++i) {
      int key;
      cin >> key;
      initial[key]++;
    }
    vector<int> open(n);
    vector<map<int, int> > inside(n);
    for (int i = 0; i < n; ++i) {
      cin >> open[i];
      int cnt;
      cin >> cnt;
      for (int j = 0; j < cnt; ++j) {
        int key;
        cin >> key;
        inside[i][key]++;
      }
    }
    cerr << "Case #" << test_index + 1 << ":";
    cout << "Case #" << test_index + 1 << ":";
    /*if (n < 12) {
      vector<int> perm;
      for (int i = 0; i < n; ++i) {
        perm.push_back(i);
      }
      bool result = false;
      do {
        map<int, int> keys = initial;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
          if (keys[open[perm[i]]] == 0) {
            ok = false;
            break;
          }
          keys[open[perm[i]]]--;
          for (map<int, int>::const_iterator it = inside[perm[i]].begin(); it != inside[perm[i]].end(); ++it) {
            keys[it->first] += it->second;
          }
        }
        if (ok) {
          result = true;
          break;
        }
      } while (next_permutation(perm.begin(), perm.end()));
      if (!result) {
        cout << " IMPOSSIBLE" << endl;
      } else {
        for (int i = 0; i < perm.size(); ++i) {
          cout << ' ' << perm[i] + 1;
        }
        cout << endl;
      }
      continue;
    }*/
    vector<int> cache(1 << n, -1);
    bool result = CanOpen(0, initial, open, inside, cache);    
    if (!result) {
      cout << " IMPOSSIBLE" << endl;
    } else {
      int mask = 0;
      map<int, int> keys = initial;
      for (int step = 0; step < n; ++step) {        
        for (int i = 0; i < n; ++i) {
          if ((mask >> i) & 1) {
            continue;
          }
          if (keys[open[i]] > 0) {
            keys[open[i]]--;
            for (map<int, int>::const_iterator it = inside[i].begin(); it != inside[i].end(); ++it) {
              keys[it->first] += it->second;
            }
            if (CanOpen(mask | (1 << i), keys, open, inside, cache)) {
              cout << ' ' << i + 1;
              mask |= (1 << i);
              break;
            }
            keys[open[i]]++;
            for (map<int, int>::const_iterator it = inside[i].begin(); it != inside[i].end(); ++it) {
              keys[it->first] -= it->second;
            }
          }
        }
      }
      cout << endl;
    }
  }
  return 0;
}
