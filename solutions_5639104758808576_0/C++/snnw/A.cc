
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int Smax;
    cin >> Smax;

    std::string s;
    cin >> s;

    int clapping = 0;
    int invited = 0;

    for (int j = 0; j <= Smax; j++) {
      int num = s[j] - '0';

      if (num == 0) continue;

      if (j > clapping) {
        // too shy...
        invited += j - clapping;
        clapping += j - clapping;
      }

      clapping += num;
    }

    cout << "Case #" << i + 1 << ": " << invited << endl;
  }
}