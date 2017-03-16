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
#define PROBLEM_ID "C"

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

bool SolveSlow(const string& s, int x, map<char, int> symbol_table, const vvi& mult_table) {
  string all;
  for (int i = 0; i < x; ++i) {
    all += s;
  }
  vi prefixes(all.length() + 1);
  prefixes[0] = 3;
  int first_i_suffix = -1;
  for (int i = 0; i < all.length(); ++i) {
    prefixes[i + 1] = mult_table[prefixes[i]][symbol_table[all[i]]];
    if (first_i_suffix == -1 && prefixes[i + 1] == 0) {
      first_i_suffix = i;
    }
  }
  if (prefixes[all.length()] != 7) {
    return false;
  }
  if (first_i_suffix == -1) {
    return false;
  }
  vi suffixes(all.length() + 1);
  suffixes[all.length()] = 3;
  int last_k_suffix = -1;
  for (int i = all.length() - 1; i >= 0; --i) {
    suffixes[i] = mult_table[symbol_table[all[i]]][suffixes[i + 1]];
    if (last_k_suffix == -1 && suffixes[i] == 2) {
      last_k_suffix = i;
    }
  }
  if (last_k_suffix == -1) {
    return false;
  }
  if (last_k_suffix <= first_i_suffix) {
    return false;
  }
  return true;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int l, x;
    cin >> l >> x;
    string s;
    cin >> s;
    map<char, int> symbol_table;
    symbol_table['i'] = 0;
    symbol_table['j'] = 1;
    symbol_table['k'] = 2;
    vvi mult_table(8, vi(8));
    for (int i = 0; i < 8; ++i) {
      mult_table[i][i] = 7;
    }
    mult_table[3][3] = mult_table[7][7] = 3;
    for (int i = 0; i < 3; ++i) {
      mult_table[i][(i + 1) % 3] = (i + 2) % 3;
      mult_table[(i + 1) % 3][i] = (i + 2) % 3 + 4;
      mult_table[i][(i + 2) % 3] = (i + 1) % 3 + 4;
      mult_table[(i + 2) % 3][i] = (i + 1) % 3;
    }
    for (int i = 0; i < 8; ++i) {
      mult_table[i][3] = mult_table[3][i] = i;
      mult_table[i][7] = mult_table[7][i] = (i + 4) % 8;
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        mult_table[i + 4][j] = mult_table[i][j + 4] = (mult_table[i][j] + 4) % 8;
        mult_table[i + 4][j + 4] = mult_table[i][j];
      }
    }
    bool result = SolveSlow(s, x, symbol_table, mult_table);
    cout << "Case #" << (test_index + 1) << ": ";
    cerr << "Case #" << (test_index + 1) << ": ";
    if (result) {
      cout << "YES" << endl;
      cerr << "YES" << endl;
    } else {
      cout << "NO" << endl;
      cerr << "NO" << endl;
    }
  }
  return 0;
}
