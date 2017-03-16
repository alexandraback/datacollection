#include <string>
#include <iostream>
#include <cassert>

using namespace std;

const string digits[] = {
  "ZERO", // Z
  "TWO",  // W
  "FOUR", // U
  "SIX",  // X
  "EIGHT", // G
  "ONE", // O
  "THREE",  // H
  "FIVE",  // F
  "SEVEN",  // V
  "NINE",  // I
};

char mainch[] = { 'Z', 'W', 'U', 'X', 'G', 'O', 'H', 'F', 'V', 'I' };
int digit[] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };

string solve(string input) {
  int count[26];
  fill(count, count+26, 0);
  for (char ch : input) {
    count[ch - 'A']++;
  }
  int ans[10];
  fill(ans, ans+10, 0);
  for (int i = 0; i < 10; i++) {
    while (count[mainch[i] - 'A'] > 0) {
      for (char letter : digits[i])
        count[letter-'A']--;
      ans[digit[i]]++;
    }
  }
  for (int i = 0; i < 26; i++) {
    assert(count[i] == 0);
  }
  string res;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < ans[i]; j++)
      res.push_back('0'+i);
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    string s;
    cin >> s;
    cout << "Case #" << i << ": " << solve(s) << endl;
  }
}
