#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> NUMBER_STRINGS{"ZERO","ONE","TWO","THREE",
    "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const vector<pair<int, char>> NUMBER_UNIQUE_CHAR{
  {0,'Z'}, {2,'W'}, {6,'X'}, {8, 'G'}, {3, 'H'}, {4, 'R'}, {5, 'F'}, {7, 'V'}, {9, 'I'}, {1, 'O'}
};
const int NUM_CHARS = 26;
const int NUM_DIGITS = 10;

void decrementCount(vector<unsigned int> &charCount, const string &numberString) {
  for (char c : numberString) --charCount[c - 'A'];
}

string decodeNumber(string S) {
  vector<unsigned int> charCount(NUM_CHARS, 0);
  vector<unsigned int> digitCount(NUM_DIGITS, 0);  
  for (char c : S) ++charCount[c - 'A'];
  int N = 0; // number length
  for (pair<int, char> numberCharPair : NUMBER_UNIQUE_CHAR) {
    digitCount[numberCharPair.first] = charCount[numberCharPair.second - 'A'];
    N += digitCount[numberCharPair.first];
    while (charCount[numberCharPair.second - 'A'] > 0) {
      decrementCount(charCount, NUMBER_STRINGS[numberCharPair.first]);
    }
  }
  string newS; newS.reserve(N);
  char currentChar = '0';
  for (int i = 0; i < NUM_DIGITS; ++i, ++currentChar) {
    for (int j = 0; j < digitCount[i]; ++j) newS += currentChar;
  }
  return newS;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    string S; cin >> S;
    cout << "Case #" << t << ": "
         << decodeNumber(S)
         << '\n';
  }
  cout << flush;
  return 0;
}
