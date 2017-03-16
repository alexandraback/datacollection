#include <cassert>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

const string kNames[] = {"ZERO", "ONE", "TWO",   "THREE", "FOUR",
                         "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

// z -> zero
// w -> two
// x -> six
// u -> four
// f -> five
// v -> seven
// o -> one
// n -> nine
// r -> three
// e -> eight

const size_t kOrder[] = {0, 2, 6, 4, 5, 7, 1, 9, 3, 8};

const size_t kAlphabetSize = 'Z' - 'A' + 1;
const size_t kNumDigits = '9' - '0' + 1;

void GetFreqs(const string &s, size_t freqs[]) {
  for (size_t i = 0; i < kAlphabetSize; ++i)
    freqs[i] = 0;
  for (size_t i = 0; i < s.size(); ++i)
    ++freqs[s[i] - 'A'];
}

size_t EatName(const string &name, size_t freqs[]) {
  size_t nfreqs[kAlphabetSize];
  GetFreqs(name, nfreqs);

  size_t count = numeric_limits<size_t>::max();
  for (size_t i = 0; i < kAlphabetSize; ++i) {
    if (nfreqs[i] != 0)
      count = min(count, freqs[i] / nfreqs[i]);
  }

  if (count == numeric_limits<size_t>::max())
    return 0;

  for (size_t i = 0; i < kAlphabetSize; ++i)
    freqs[i] -= nfreqs[i] * count;

  return count;
}

int main() {
  size_t freqs[kAlphabetSize];

  int num_tests;
  cin >> num_tests;
  for (int test_num = 0; test_num < num_tests; ++test_num) {
    string buf;
    cin >> buf;
    GetFreqs(buf, freqs);

    size_t digits[kNumDigits] = {};
    for (const size_t i : kOrder)
      digits[i] += EatName(kNames[i], freqs);
    for (size_t i = 0; i < kAlphabetSize; ++i)
      assert(freqs[i] == 0);

    string result;
    for (size_t i = 0; i < kNumDigits; ++i)
      result.append(string(digits[i], '0' + i));
    cout << "Case #" << (test_num + 1) << ": " << result << endl;
  }
  return 0;
}
