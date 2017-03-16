#include <bits/stdc++.h>

using namespace std;

template<class T> inline T sqr(const T& a) {
  return a * a;
}

template<class T> inline T middle(const T &a, const T &b) {
  return (a + b) / 2;
}

template<class T> inline int len(const T &c) {
  return static_cast<int>(c.size());
}

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 10;

vector<pair<char, int>> required[N];
vector<int> digit;

void Init() {
  static vector<pair<string, int>> nums = {
    {"ZERO", 0},
    {"TWO", 2},
    {"FOUR", 4},
    {"SIX", 6},
    {"EIGHT", 8},
    {"FIVE", 5},
    {"THREE", 3},
    {"SEVEN", 7}, 
    {"ONE", 1},
    {"NINE", 9},
  };
  for (int t = 0; t < N; ++t) {
    string &s = nums[t].first;
    sort(s.begin(), s.end());
    for (int i = 0; i < len(s); ) {
      int j = i + 1;
      for (; j < len(s) && s[i] == s[j]; ++j) {

      }
      required[t].push_back({s[i], j - i});
      i = j;
    }
    digit.push_back(nums[t].second);
  }
}

void HandleCase() {
  string s;
  getline(cin, s);
  vector<int> counts(128, 0);
  for (char c : s) {
    counts[int(c)]++;
  }
  vector<int> ans;
  for (int i = 0; i < N; ++i) {
    bool found = true;
    while (found) {
      found = true;
      for (pair<char, int> &req : required[i]) {
        if (counts[req.first] < req.second) {
          found = false;
          break;
        }
      }
      if (found) {
        ans.push_back(digit[i]);
        for (pair<char, int> &req : required[i]) {
          counts[req.first] -= req.second;
        }
        //printf("%d found\n", i);
      }
    }
  }
  for (int x : counts) {
    assert(x == 0);
  }
  sort(ans.begin(), ans.end());
  for (int x : ans) {
    printf("%d", x);
  }
  puts("");
}

int main() {
  Init();

  int tests;
  scanf("%d\n", &tests);
  for (int test = 1; test <= tests; ++test) {
    printf("Case #%d: ", test);
    HandleCase();
  }
  return 0;
}
