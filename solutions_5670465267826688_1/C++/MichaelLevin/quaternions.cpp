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

bool SolveSlow(const string& s, ll x, map<char, int> symbol_table, const vvi& mult_table) {
  string all;
  for (int i = 0; i < x; ++i) {
    all += s;
  }
  vi prefixes(all.length() + 1);
  prefixes[0] = 3;
  int first_i_prefix = -1;
  for (int i = 0; i < all.length(); ++i) {
    prefixes[i + 1] = mult_table[prefixes[i]][symbol_table[all[i]]];
    if (first_i_prefix == -1 && prefixes[i + 1] == 0) {
      first_i_prefix = i;
    }
  }
  if (prefixes[all.length()] != 7) {
    return false;
  }
  if (first_i_prefix == -1) {
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
  if (last_k_suffix <= first_i_prefix) {
    return false;
  }
  return true;
}

bool SolveFast(const string& s, ll x, map<char, int> symbol_table, const vvi& mult_table) {
  vi prefixes(s.length() + 1);
  prefixes[0] = 3;
  for (int i = 0; i < s.length(); ++i) {
    prefixes[i + 1] = mult_table[prefixes[i]][symbol_table[s[i]]];
  }
  int whole_string = prefixes[s.length()];
  int all = 3;
  for (int i = 0; i < x % 4; ++i) {
    all = mult_table[all][whole_string];
  }
  if (all != 7) {
    return false;
  }
  vi suffixes(s.length() + 1);
  suffixes[s.length()] = 3;
  for (int i = s.length() - 1; i >= 0; --i) {
    suffixes[i] = mult_table[symbol_table[s[i]]][suffixes[i + 1]];
  }
  int first_i_prefix = -1;
  for (int i = 0; i < s.length(); ++i) {
    int value = prefixes[i + 1];
    if (value == 0) {
      if (first_i_prefix == -1 || i < first_i_prefix) {
        first_i_prefix = i;
      }
    }
    int period = mult_table[suffixes[i + 1]][prefixes[i]];
    for (int j = 1; j <= min(3LL, x - 1); ++j) {
      value = mult_table[value][period];
      if (value == 0) {
        if (first_i_prefix == -1 || i + j * s.length() < first_i_prefix) {
          first_i_prefix = i + j * s.length();
        }
      }
    }
  }
  if (first_i_prefix == -1) {
    return false;
  }
  ll last_k_suffix = -1;
  for (int i = 0; i < s.length(); ++i) {
    int value = suffixes[i];
    if (value == 2) {
      if (i + ll(x - 1) * s.length() > last_k_suffix) {
        last_k_suffix = i + ll(x - 1) * s.length();
      }
    }
    int period = mult_table[suffixes[i + 1]][prefixes[i]];
    for (int j = 1; j <= min(3LL, x - 1); ++j) {
      value = mult_table[period][value];
      if (value == 2) {
        if (i + ll(x - 1 - j) * s.length() > last_k_suffix) {
          last_k_suffix = i + ll(x - 1 - j) * s.length();
        }
      }
    }
  }
  if (first_i_prefix >= last_k_suffix) {
    return false;
  }
  return true;
}

int main() {
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
  /*while (true) {
    int l = rand() % 100 + 1;
    int x = rand() % 100 + 1;
    string s = "";
    for (int i = 0; i < l; ++i) {
      s += ('i' + rand() % 3);
    }
    cerr << x << ' ' << s << endl;
    bool res1 = SolveSlow(s, x, symbol_table, mult_table);
    bool res2 = SolveFast(s, x, symbol_table, mult_table);
    if (res1 != res2) {
      cerr << "Wrong answer!" << endl;
      cerr << "Slow: " << res1 << ", Fast: " << res2 << endl;
      break;
    } else {
      cerr << "OK: " << res1 << endl;
    }
  }*/
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int l;
    ll x;
    cin >> l >> x;
    string s;
    cin >> s;
    if (s.length() != l) {
      abort();
    }
    bool result = SolveFast(s, x, symbol_table, mult_table);
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
