#include <bits/stdc++.h>
using namespace std;

bool try_do(int *freqs, string word) {
  map<char, int> number;
  for (const char c : word) {
    number[c] += 1;
  }
  for (const auto& d : number) {
    if (freqs[d.first] < d.second) {
      return false;
    }
  }
  for (const auto& d : number) {
    freqs[d.first] -= d.second;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  for (int i=1; i<=n; i++) {
    string s;
    cin >> s;
    int freqs[256] = {0};
    for (int j=0; j<s.size(); j++) {
      freqs[s[j]] += 1;
    }
    int ans_freqs[10] = {0};
    while (try_do(freqs, "TWO")) ans_freqs[2] += 1;
    while (try_do(freqs, "SIX")) ans_freqs[6] += 1;
    while (try_do(freqs, "EIGHT")) ans_freqs[8] += 1;
    while (try_do(freqs, "ZERO")) ans_freqs[0] += 1;
    while (try_do(freqs, "FOUR")) ans_freqs[4] += 1;
    while (try_do(freqs, "ONE")) ans_freqs[1] += 1;
    while (try_do(freqs, "SEVEN")) ans_freqs[7] += 1;
    while (try_do(freqs, "FIVE")) ans_freqs[5] += 1;
    while (try_do(freqs, "THREE")) ans_freqs[3] += 1;
    while (try_do(freqs, "NINE")) ans_freqs[9] += 1;
    cout << "Case #" << i << ": ";
    for (int j=0; j<10; j++) {
      for (int k=0; k<ans_freqs[j]; k++) {
        cout << j;
      }
    }
    cout << endl;
  }
  return 0;
}
