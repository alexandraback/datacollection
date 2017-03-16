#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

//#define NDEBUG

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

const char INPUT[] = "HelloWorld.inp";
const char OUTPUT[] = "SmallTest.out";

const int ORDER_DIGIT[] = {0, 2, 6, 7, 8, 5, 4, 1, 3, 9};
const string DIGIT_STR[] = {"ZERO", "TWO", "SIX", "SEVEN", "EIGHT", "FIVE", "FOUR", "ONE", "THREE", "NINE"};
const char SPECIAL_CHAR[] = {'Z', 'W', 'X', 'S', 'G', 'V', 'F', 'O', 'R', 'I'};

int main() {
  freopen(INPUT, "r", stdin);
  freopen(OUTPUT, "w", stdout);

  int numTest;
  cin >> numTest;

  int countChar['Z' - 'A' + 1 + 10];
  int numOfDigit[10];

  for (int idTest = 0; idTest < numTest; ++ idTest) {
    string inputStr;
    cin >> inputStr;

    for (char c = 'A'; c <= 'Z'; ++c) {
      countChar[c - 'A'] = 0;
    }
    for (int idDigit = 0; idDigit <= 9; ++ idDigit) {
      numOfDigit[idDigit] = 0;
    }


    for (int id = 0; id < inputStr.size(); ++ id) {
      ++ countChar[inputStr[id] - 'A'];
    }

    // for (char c = 'A'; c <= 'Z'; ++c) {
    //   cout << c << " " << countChar[c - 'A'] << " ";
    // }
    // cout << endl;

    for (int idDigit = 0; idDigit <= 9; ++ idDigit) {
      int digit = ORDER_DIGIT[idDigit];
      numOfDigit[digit] = countChar[SPECIAL_CHAR[idDigit] - 'A'];
      for (int count = 0; count < numOfDigit[digit]; ++ count) {
        for (int idStr = 0; idStr < DIGIT_STR[idDigit].size(); ++ idStr) {
          -- countChar[DIGIT_STR[idDigit][idStr] - 'A'];
        }
      }

      // for (char c = 'A'; c <= 'Z'; ++c) {
      //   cout << c << " " << countChar[c - 'A'] << " ";
      // }
      // cout << endl;
    }

    cout << "Case #" << idTest + 1 << ": ";

    for (int digit = 0; digit <= 9; ++ digit) {
      for (int count = 0; count < numOfDigit[digit]; ++ count) {
        cout << digit;
      }
    }

    cout << endl;
  }

  return 0;
}
