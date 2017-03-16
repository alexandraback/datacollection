#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
using namespace std;

string digs[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}; 

int check(vector<int> test, string s) {
  
  int freq[256] = {0};
  for (int i = 0; i < s.length(); i++) {
    freq[s[i]]++;
  }
  int f[10] = {};
  while (1) {
    int found = 0;
    for (int i : test) {
      int need[256] = {0};
      for (char d : digs[i]) {
        need[d]++;
      }
      int ok = 1;
      for (char d : digs[i]) {
        if (freq[d] < need[d]) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        f[i]++;
        for (char d : digs[i]) {
          freq[d]--;
        }
        found = 1;
      }
    }
    if (!found) break;
  }
  for (int i = 0; i < 256; i++) {
    if (freq[i]) {
      return 0;
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < f[i]; j++) {
      cout << i;
    }
  }
  return 1;
}

void solve() {
  string s;
  cin >> s;
  for (int mask = 0; mask < (1<<10); mask++) {
    vector<int> test;
    for (int i = 0; i < 10; i++) {
      if (mask&(1<<i)) {
        test.push_back(i);
      }
    }
    if (check(test, s)) {
      return;
    }
  }
  assert(false);
}

int main() { _
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
