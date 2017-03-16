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
#define PROBLEM_ID "1"

#pragma comment(linker, "/STACK:36777216")

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;


int GetPref(const string& line) {
  for (int i = 1; i < line.size(); ++i) {
    bool prefix = true;
    for (int j = 0; j < line.size() - i; ++j) {
      if (line[i + j] != line[j]) {
        prefix = false;
      }
    }
    if (prefix) {
      return i;
    }
  }
  return line.size();
}

double GetWordProb(string key, string line) {
  map<char, int> keys;
  for (int i = 0; i < key.size(); ++i) {
    keys[key[i]] += 1;
  }
  int keys_count = key.size();
  if (keys_count == 0) return 0;

  double prob = 1;
  for (int i = 0; i < line.size(); ++i) {
    prob *= (double)keys[line[i]] / keys_count;
  }
  return prob;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int k, l, s;
    cin >> k >> l >> s;
    string keyboard, line, empty;

    getline(cin, empty);
    getline(cin, keyboard);
   
    getline(cin, line);
    //getline(cin, empty);

    int pref = GetPref(line);
    int rest = line.size() - pref;
    int worst = (s - rest) / pref;

    double prob = GetWordProb(keyboard, line);
    double exp = (s - line.size() + 1) * prob;

    double res = worst - exp;
    if (prob == 0)
      res = 0;

    cout << "Case #" << test_index + 1 << ": " << res << endl;
  }
  return 0;
}
