#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

string d[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

// Z -> zero
// W -> two
// U -> four
// X -> six
// G -> eight
//
// F -> five
// H -> three
// V -> seven
//
// O -> one
// I -> nine

void check(int* alpha, int* digits, char i, int letter) {
  if (alpha[i - 'A'] > 0) {
    digits[letter] = alpha[i - 'A'];

    for (int j=0; j<d[letter].length(); j++) {
      alpha[d[letter][j] - 'A'] -= digits[letter];
    }
  }
}

string solve(string s, int from) {
  string result;

  int alpha[26] = {0};

  for (int i=0; i<s.size(); i++) {
    alpha[s[i]-'A']++;
  }

  int digits[10] = {0};

  // Z -> zero
  check(alpha, digits, 'Z', 0);
  // W -> two
  check(alpha, digits, 'W', 2);
  // U -> four
  check(alpha, digits, 'U', 4);
  // X -> six
  check(alpha, digits, 'X', 6);
  // G -> eight
  check(alpha, digits, 'G', 8);
  //
  // F -> five
  check(alpha, digits, 'F', 5);
  // H -> three
  check(alpha, digits, 'H', 3);
  // V -> seven
  check(alpha, digits, 'V', 7);
  //
  // O -> one
  check(alpha, digits, 'O', 1);
  // I -> nine
  check(alpha, digits, 'I', 9);

  for (int i=0; i<10; i++) {
    while (digits[i] > 0) {
      result += char(i + int('0'));
      digits[i]--;
    }
  }

  return result;
}

int main() {
  int t;

  cin >> t;

  for (int i=0; i<t; i++) {
    string s;

    cin >> s;

    string result = solve(s, 0);

    cout << "Case #" << (i+1) << ": " << result << endl;
  }

  return 0;
}
