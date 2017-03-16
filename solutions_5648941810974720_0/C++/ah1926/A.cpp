#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int DIGITS = 10;
const int SIGMA = 26;
const string LETTERS[DIGITS] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
const int ORDER[DIGITS] = {0, 2, 4, 5, 6, 7, 8, 1, 9, 3};
const string IDENTIFIER = "ZWUFXSGOIT";

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");
  int testCount;
  in >> testCount;
  for (int test = 1; test <= testCount; ++test) {
    string S;
    in >> S;
    vector<int> charFrequences = vector<int>(SIGMA, 0);
    for (const char &symbol: S)
      ++charFrequences[int(symbol - 'A')];
    vector<int> digitFrequences = vector<int>(DIGITS, 0);
    for (int i = 0; i < DIGITS; ++i) {
      const int digit = ORDER[i];
      const int symbol = int(IDENTIFIER[i] - 'A');
      const int frequency = charFrequences[symbol];
      digitFrequences[digit] = frequency;
      for (const char &letter: LETTERS[digit])
        charFrequences[int(letter - 'A')] -= frequency;
    }
    out << "Case #" << test << ": ";
    for (int digit = 0; digit < DIGITS; ++digit)
      for (int i = 0; i < digitFrequences[digit]; ++i)
        out << digit;
    out << "\n";
  }
  in.close();
  out.close();
  return 0;
}
