#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  cout.setf(ios::fixed);
  cout.precision(7);
  int T, cas;
  cin >> T;
  cas = 1;
  while (cas <= T){
    double D;
    int N, A;
    cin >> D >> N >> A;
    vector<double> x(N);
    vector<double> t(N);
    vector<double> acc(A);
    for (int i = 0; i < N; ++i) cin >> t[i] >> x[i];
    for (int i = 0; i < A; ++i) cin >> acc[i];
    cout << "Case #" << cas << ':' << endl;
    for (int i = 0; i < A; ++i) {
      double time = 0.0, vel = 0.0, pos = 0.0;
      if (N == 1) time = sqrt(2*acc[i]*D)/acc[i];
      else {
        for (int j = 1; j < N; ++j) {
          if (x[j] < D) {
            time = max((vel + sqrt(vel*vel + 2*acc[i]*(x[j]-pos)))/acc[i] + time, t[j]);
            vel += acc[i]*time;
            pos = x[j];
          }
          else {
            time = max((vel + sqrt(vel*vel + 2*acc[i]*(D-pos)))/acc[i] + time, (t[j] - t[j-1])*(D-x[j-1])/(x[j] - x[j-1]) + t[j - 1]);
            break;
          }
          cerr << "j: " << j << " time: " << time << endl;
        }
      }
      cout << time << endl;
    }
    ++cas;
  }
}