#include <bits/stdc++.h>
using namespace std;

const string v[] =
{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT",
  "NINE"};

const pair<char, int> d[] = {{'Z', 0}, {'W', 2}, {'G', 8}, {'T', 3}, {'X', 6},
  {'S', 7}, {'R', 4}, {'V', 5}, {'O', 1}, {'I', 9}};

string to_str(int val) {
  string res;
  if (!val) {
    res += '0';
  } else {
    while (val) {
      res += val % 10 + '0';
      val /= 10;
    }
    reverse(res.begin(), res.end());
  }
  return res;
}

string solve() {
  string s;
  cin >> s;

  map<char, int> p;
  for (char c : s) {
    ++p[c];
  }

  vector<pair<int, int>> x;
  for (int i = 0; i < 10; ++i) {
    char c = d[i].first;
    x.push_back({d[i].second, p[c]});
    int val = p[c];
    for (char k : v[d[i].second]) {
      assert(p[k] >= val);
      p[k] -= val;
    }
  }
  for (const auto& el : p) {
    assert(el.second == 0);
  }

  sort(x.begin(), x.end());
  string res;
  for (pair<int, int> cur : x) {
    for (int i = 0; i < cur.second; ++i) {
      res += to_str(cur.first);
    }
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    printf("Case #%d: %s\n", test, solve().c_str());
  }
}
