#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

#define FILENAME "A-small-attempt0.in"

string solve(int test_number) {
  string data;
  cin >> data;
  vector<int> letters(26, 0), count(10, 0);
  for (int i = 0; i < data.size(); ++i) {
    ++letters[data[i] - 'A'];
  }

  int val;

  val = letters['Z' - 'A'];
  count[0] += val;
  letters['Z' - 'A'] -= val;
  letters['E' - 'A'] -= val;
  letters['R' - 'A'] -= val;
  letters['O' - 'A'] -= val;

  val = letters['W' - 'A'];
  count[2] += val;
  letters['T' - 'A'] -= val;
  letters['W' - 'A'] -= val;
  letters['O' - 'A'] -= val;

  val = letters['U' - 'A'];
  count[4] += val;
  letters['F' - 'A'] -= val;
  letters['O' - 'A'] -= val;
  letters['U' - 'A'] -= val;
  letters['R' - 'A'] -= val;

  val = letters['X' - 'A'];
  count[6] += val;
  letters['S' - 'A'] -= val;
  letters['I' - 'A'] -= val;
  letters['X' - 'A'] -= val;
  
  val = letters['G' - 'A'];
  count[8] += val;
  letters['E' - 'A'] -= val;
  letters['I' - 'A'] -= val;
  letters['G' - 'A'] -= val;
  letters['H' - 'A'] -= val;
  letters['T' - 'A'] -= val;

  val = letters['O' - 'A'];
  count[1] += val;
  letters['O' - 'A'] -= val;
  letters['N' - 'A'] -= val;
  letters['E' - 'A'] -= val;

  val = letters['T' - 'A'];
  count[3] += val;
  letters['T' - 'A'] -= val;
  letters['H' - 'A'] -= val;
  letters['R' - 'A'] -= val;
  letters['E' - 'A'] -= val;
  letters['E' - 'A'] -= val;

  val = letters['F' - 'A'];
  count[5] += val;
  letters['F' - 'A'] -= val;
  letters['I' - 'A'] -= val;
  letters['V' - 'A'] -= val;
  letters['E' - 'A'] -= val;

  val = letters['S' - 'A'];
  count[7] += val;
  letters['S' - 'A'] -= val;
  letters['E' - 'A'] -= val;
  letters['V' - 'A'] -= val;
  letters['E' - 'A'] -= val;
  letters['N' - 'A'] -= val;

  val = letters['I' - 'A'];
  count[9] += val;
  letters['N' - 'A'] -= val;
  letters['I' - 'A'] -= val;
  letters['N' - 'A'] -= val;
  letters['E' - 'A'] -= val;

  for (int i = 0; i < 26; ++i) {
    if (letters[i] != 0) cout << "WTF" << endl;
  }

  string ans = "";
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < count[i]; ++j)
      ans += (char) ((int) '0' + i);
  }
  return ans;
}

int main() {
  freopen(FILENAME, "r", stdin); freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    string ans = solve(i);
    cout << "Case #" << i << ": " << ans << endl;
  }
  return 0;
}