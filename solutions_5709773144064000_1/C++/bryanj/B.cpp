#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ti++) {
    double c, f, x;
    cin >> c >> f >> x;
    double rate = 2;
    double answer = x / rate;
    double offset = 0;
    while (true) {
      double time = c / rate;
      offset += time;
      rate += f;
      if (offset + x / rate > answer)
        break;
      answer = offset + x / rate;
    }
    cout << "Case #" << ti << ": " << setprecision(12) << answer << endl;
  }
}
