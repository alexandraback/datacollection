#include <bits/stdc++.h>
#define vec vector
#define sz(c) int(c.size())
#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define DOWN(i, a, b) for(int i = (a) - 1; i >= (b); --i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vec<int> vi;

const vector<string> names = {"ZERO", "TWO", "FOUR", "SIX", "EIGHT", "FIVE", "THREE", "SEVEN", "ONE", "NINE"};
const vector<int> values = {0, 2, 4, 6, 8, 5, 3, 7, 1, 9};
const vector<char> key = {'Z', 'W', 'U', 'X', 'G', 'F', 'R', 'V', 'O', 'N'};

void solve(int testcase) {
  cout << "Case #" << testcase << ": ";
  string s;
  cin >> s;
  map<char, int> cnt;
  for (char c : s) {
    cnt[c] += 1;
  }
  vec<int> res(10);
  for (int i = 0; i < 10; ++i) {
    while (cnt[key[i]] > 0) {
      for (char c : names[i]) cnt[c] -= 1;
      res[values[i]] += 1;
    }
  }
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < res[i]; ++j) cout << i;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int testcases;
  cin >> testcases;
  FOR(testcase, 1, testcases + 1) {
    cerr << "Case " << testcase << "/" << testcases << endl;
    solve(testcase);
  }

  return 0;
}
