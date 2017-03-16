#include <iostream>
#include <vector>

using namespace std;

void set_digits(vector<bool> &digits, long long num) {
  while (num > 0) {
    digits[num % 10] = true;
    num /= 10;
  }
}

int main() {
  int T;
  cin >> T;

  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";

    long long N;
    cin >> N;

    if (N == 0) {
      cout << "INSOMNIA\n";
    } else {
      vector<bool> digits(10, false);
      int j = 0;
      auto all_true = vector<bool>(10, true);
      while (digits != all_true) {
        j++;
        set_digits(digits, j * N);        
      }

      cout << j * N << "\n";
    }
  }
}
