#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <tuple>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int testCase=0; testCase < T; ++testCase)
  {
      long long solve = 0; 
      long long N;
      bool INSOMNIA = false;

      cin >> N;
      vector<bool> digits(10, false);
      int digitsCount = 0;
      long long steps = 0;

      while (digitsCount != 10) {
        solve += N;

        long long x = solve;
        while (x != 0) {
          int lastDigit = x % 10;
          if (!digits[lastDigit]) {
            digitsCount++;
            digits[lastDigit] = true;
          }
          x /= 10;
        }
        steps++;
        if (steps == 1000) {
          INSOMNIA = true;
          break;
        }
      }

      cout << "Case #" << testCase + 1 << ": ";

      if (!INSOMNIA)
        cout << solve << endl;
      else
        cout << "INSOMNIA" << endl;
  }

  return 0;
}