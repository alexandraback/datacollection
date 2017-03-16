#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int tests;
  cin >> tests;
  cout.precision(7);
  cout.setf(ios::fixed, ios::floatfield);    
  for (int t = 0; t < tests; t++) {
    double c, f, x;
    cin >> c >> f >> x;
    double speed = 2;
    double total_time = 0;
    while (true) {
      double cur_time = x / speed;
      double new_time = c / speed + x / (speed + f);
      if (cur_time < new_time)
        break;
      else {
        total_time += c / speed;
        speed += f;
      }
    }
    double const res = total_time + x / speed;
    cout << "Case #" << (t + 1) << ": " << res << '\n';
  }
     
}
