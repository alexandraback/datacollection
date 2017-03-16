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

void Init() {
  static vector<string> nums = {
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",  
    "EIGHT",
    "NINE",
  };
  for (int t = 0; t < N; ++t) {
    string &s = nums[t];
    sort(s.begin(), s.end());
    for (int i = 0; i < len(s); ) {
      int j = i + 1;
      for (; j < len(s) && s[i] == s[j]; ++j) {

      }
      required[t].push_back({s[i], j - i});
      i = j;
    }
  }
}

bool Find(vector<int> &counts, int i, vector<int> &ans) {
  if (i >= N) {
    for (int x : counts) {
      if (x) {
        return false;
      }
    }
    return true;
  }
  if (Find(counts, i + 1, ans)) {
    return true;
  }
  for (pair<char, int> &req : required[i]) {
    if (counts[req.first] < req.second) {
      return false;
    }
  }
  ans.push_back(i);

  for (pair<char, int> &req : required[i]) {
    counts[req.first] -= req.second;
  }

  if (Find(counts, i, ans)) {
    return true;
  }

  for (pair<char, int> &req : required[i]) {
    counts[req.first] += req.second;
  }

  ans.pop_back();

  return false;
}

void HandleCase() {
  string s;
  getline(cin, s);
  vector<int> counts(128, 0);
  for (char c : s) {
    counts[int(c)]++;
  }
  vector<int> ans;
  assert(Find(counts, 0, ans));
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
