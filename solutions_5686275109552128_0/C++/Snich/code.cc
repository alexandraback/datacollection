#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl; 

//const int kN = 1050;

class Solver {
  int num_plates_;
  vector<int> num_pancakes_;

  int ans_;

public:
  void InputData();
  void Solve();
  void OutputData();
};

void Solver::InputData() {
  cin >> num_plates_;
  num_pancakes_.resize(num_plates_);
  for (int i = 0; i < num_plates_; ++i) {
    cin >> num_pancakes_[i];
  }
}

void Solver::Solve() {
  int biggest_plate = *max_element(begin(num_pancakes_), end(num_pancakes_));
  ans_ = biggest_plate;
  for (int num_special_minutes = 0; num_special_minutes <= biggest_plate;
       ++num_special_minutes) {
    //dbg(num_special_minutes);
    int min_time = num_special_minutes;
    int max_time = ans_;
    while (min_time + 1 < max_time) {
      int used_special_minutes = 0;
      int time = (min_time + max_time) / 2;
      bool ok = true;
      for (int i = 0; i < num_plates_; ++i) {
        if (num_pancakes_[i] + num_special_minutes > time) {
          int k = (num_pancakes_[i] + time - num_special_minutes - 1)
                  / (time - num_special_minutes) - 1;
          used_special_minutes += k;
          //dbg(time);
          //dbg(used_special_minutes)
          if (used_special_minutes > num_special_minutes) {
            min_time = time;
            ok = false;
            break;
          }
        }
      }
      if (ok) max_time = time;
    }
    //dbg(max_time);
    ans_ = min(ans_, max_time);
  }
}

void Solver::OutputData() {
  cout << ans_;
}

int main()
{
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";

        Solver solver;
        solver.InputData();
        solver.Solve();
        solver.OutputData();

        cout << endl;
    }
    return 0;
}
