#include <iostream>
#include <iomanip>

using namespace std;

main() {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    double C, F, X, result;

    cin >> C >> F >> X;

    double best_time = X /2.0; 
    if (X>C) {
      // simulate;
      int k = 0; // number of farms so far
      double current_time = 0.0;
      while (current_time<=best_time) {
	current_time += C / (2.0 + k*F); 
	k++;
	best_time = min( best_time, current_time + X / (2.0 + k*F)); 
      };
    };
    cout << "Case #" << t << ": " << setprecision(10) << best_time << endl;
  };
};
