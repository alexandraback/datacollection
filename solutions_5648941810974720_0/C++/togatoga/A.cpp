#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <bitset>

#include <tuple>
#include <unordered_map>
#include <assert.h>

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1 << 29;
const double EPS = 1e-9;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const string digits[10] = {"ZERO",  "TWO", "FOUR", "ONE",   "FIVE",
                           "SEVEN", "SIX", "NINE", "THREE", "EIGHT"};
// 0 2 4 1 5 7 6 9 3 8
void solve(int case_id, const string &str) {
  int N = str.size();
  map<char, int> cnt_digit;
  vector<int> dic_digits = {0, 2, 4, 1, 5, 7, 6, 9, 3, 8};
  for (int i = 0; i < N; i++) {
    cnt_digit[str[i]]++;
  }
  string ans = "";
  for (int i = 0; i < 10; i++) {
    map<char, int> cnt_tmp;
    // cout << i << " " << ans << endl;
    for (int j = 0; j < digits[i].size(); j++) {
      cnt_tmp[digits[i][j]]++;
    }
    while (true) {
      bool ok = true;
      for (const auto &val : cnt_tmp) {
        if (val.second > cnt_digit[val.first]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans += to_string(dic_digits[i]);
        for (const auto &val : cnt_tmp) {
          cnt_digit[val.first] -= val.second;
        }
      } else {
        break;
      }
    }
  }
  // cout << ans << endl;
  for (const auto &val : cnt_digit) {
    assert(val.second == 0);
  }
  sort(ans.begin(), ans.end());
  printf("Case #%d: %s\n", case_id, ans.c_str());
  return;
}

int main() {
  int T;
  cin >> T;

  for (int case_id = 1; case_id <= T; case_id++) {
    string tmp;
    cin >> tmp;
    solve(case_id, tmp);
  }
  return 0;
}