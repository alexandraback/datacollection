#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>


#define OUT(var) ' ' << #var "=" << var


/*
 * ZERO
 * ONE
 * TWO
 * THREE
 * FOUR
 * FIVE
 * SIX
 * SEVEN
 * EIGHT
 * NINE
 */


class Task {
 public:
  Task(): letters{}, digits{} {}

  friend std::istream &operator>> (std::istream &in, Task &_) {
    std::string str;
    in >> str;

    for (char ch: str) {
      _.letters[ch - 'A'] += 1;
    }

    return in;
  }

  friend std::ostream &operator<< (std::ostream &out, const Task &_) {
    for (int digit = 0; digit < 10; ++digit) {
      int count = _.digits[digit];

      while (count--) {
        out << digit;
      }
    }

    return out;
  }

  void solve () {
    while (dec('Z')) {
      dec('E');
      dec('R');
      dec('O');
      add(0);
    }

    while (dec('W')) {
      dec('T');
      dec('O');
      add(2);
    }

    while (dec('U')) {
      dec('F');
      dec('O');
      dec('R');
      add(4);
    }

    while (dec('X')) {
      dec('S');
      dec('I');
      add(6);
    }

    while (dec('G')) {
      dec('E');
      dec('I');
      dec('H');
      dec('T');
      add(8);
    }

    while (dec('O')) {
      dec('N');
      dec('E');
      add(1);
    }

    while (dec('H')) {
      dec('T');
      dec('R');
      dec('E');
      dec('E');
      add(3);
    }

    while (dec('F')) {
      dec('I');
      dec('V');
      dec('E');
      add(5);
    }

    while (dec('S')) {
      dec('E');
      dec('V');
      dec('E');
      dec('N');
      add(7);
    }

    digits[9] += letters['I' - 'A'];
  }

 private:
  bool dec (char letter) {
    if (letters[letter - 'A']) {
      letters[letter - 'A'] -= 1;
      return true;
    }
    else {
      return false;
    }
  }

  void add (int digit) {
    digits[digit] += 1;
  }

  std::array<int, 26> letters;
  std::array<int, 10> digits;
};


int main () {
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;

  for (int t = 1; t <= T; ++t) {
    Task task;
    std::cin >> task;

    task.solve();

    std::cout << "Case #" << t << ": " << task << '\n';
  }
}
