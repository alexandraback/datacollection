#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";

    string pancakes;
    cin >> pancakes;

    int num_flips = 0;
    bool good = true;
    if (pancakes[0] == '-') {
      good = false;
    }
    for (int j = 1; j < pancakes.length(); j++) {      
      if (pancakes[j] != pancakes[j - 1]) {
        num_flips++;
        good = !good;
      }
    }

    if (!good) {
      num_flips++;
    }

    cout << num_flips << "\n";
  }
}
