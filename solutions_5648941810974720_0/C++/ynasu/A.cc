#include <iostream>
#include <map>
#include <string>

using namespace std;

namespace {

string Solve(string S) {
  map<char, int> counts;
  for (char c : S) {
    ++counts[c];
  }
  map<int, int> numbers;
  numbers[0] = counts['Z'];
  numbers[2] = counts['W'];
  numbers[6] = counts['X'];
  numbers[8] = counts['G'];
  numbers[3] = counts['H'] - numbers[8];
  numbers[7] = counts['S'] - numbers[6];
  numbers[5] = counts['V'] - numbers[7];
  numbers[4] = counts['F'] - numbers[5];
  numbers[1] = counts['O'] - numbers[0] - numbers[2] - numbers[4];
  numbers[9] = counts['I'] - numbers[5] - numbers[6] - numbers[8];

  string res;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < numbers[i]; ++j) {
      res += '0' + i;
    }
  }
  return res;
}

}

int main(void) {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    string S;
    cin >> S;
    cout << "Case #" << i << ": " << Solve(S) << endl;
  }

  return 0;
}
