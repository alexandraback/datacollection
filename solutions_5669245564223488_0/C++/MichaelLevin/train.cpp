#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
#define PROBLEM_ID "B"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

const int MOD = 1000000007;

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int n;
    cin >> n;
    vector<string> sets(n);
    for (int i = 0; i < n; ++i) {
      cin >> sets[i];
    }
    vvi graph(26, vi(26, 0));
    vi in_degree(26), out_degree(26);
    vi loops(26);
    bool possible = true;
    set<char> middle, border;
    for (int i = 0; i < n; ++i) {
      if (sets[i][0] != sets[i][sets[i].length() - 1]) {
        graph[sets[i][0] - 'a'][sets[i][sets[i].length() - 1] - 'a']++;
        out_degree[sets[i][0] - 'a']++;
        in_degree[sets[i][sets[i].length() - 1] - 'a']++;
      } else {
        loops[sets[i][0] - 'a']++;
      }
      border.insert(sets[i][0]);
      border.insert(sets[i][sets[i].length() - 1]);
      for (int j = 0; j + 2 < sets[i].length(); ++j) {
        if (sets[i][j] != sets[i][j + 1]) {
          for (int k = j + 2; k < sets[i].length(); ++k) {
            if (sets[i][j] == sets[i][k]) {
              possible = false;
              break;
            }
          }
          if (!possible) {
            break;
          }
        }
      }
      if (!possible) {
        break;
      }
      for (int j = 1; j + 1 < sets[i].length(); ++j) {
        if (sets[i][j] != sets[i][0] && sets[i][j] != sets[i][sets[i].length() - 1]) {
          middle.insert(sets[i][j]);
        }
      }
    }
    cout << "Case #" << (test_index + 1) << ": ";
    cerr << "Case #" << (test_index + 1) << ": ";
    if (!possible) {
      cout << 0 << endl;
      continue;
    }
    vector<int> middle_and_border;
    set_intersection(middle.begin(), middle.end(), border.begin(), border.end(), back_inserter(middle_and_border));
    if (!middle_and_border.empty()) {
      possible = false;
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < 26; ++i) {
      if (in_degree[i] > 1 || out_degree[i] > 1) {
        possible = false;
        break;
      }
    }
    if (!possible) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < 26; ++i) {
      if (out_degree[i] > 0) {
        int start = i;
        int cur = start;
        while (out_degree[cur] > 0) {
          for (int j = 0; j < 26; ++j) {
            if (graph[cur][j] == 1) {
              cur = j;
              break;
            }
          }
          if (cur == start) {
            possible = false;
            break;
          }
        }
        if (!possible) {
          break;
        }
      }
    }
    if (!possible) {
      cout << 0 << endl;
      continue;
    }
    int chains = 0;
    for (int i = 0; i < 26; ++i) {
      if (in_degree[i] == 0 && (out_degree[i] > 0 || loops[i] > 0)) {
        ++chains;
      }
    }
    vector<ll> fact(101);
    fact[0] = 1;
    for (int i = 1; i < fact.size(); ++i) {
      fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll result = fact[chains];
    for (int i = 0; i < 26; ++i) {
      result = (result * fact[loops[i]]) % MOD;
    }
    cout << result << endl;
  }
  return 0;
}
