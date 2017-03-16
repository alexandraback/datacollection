include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

typedef unsigned int uint;

#define do_times(N) for (uint i = 0; i < N; i++)

double solve_case(istream &input) {
  // do stuff here
  double C, F, X;
  input >> C >> F >> X;
  double time = 0;
  double rate = 2;
  while (C * (rate + F) < X * F) {
    time += C / rate;
    rate += F;
  }
  time += X / rate;
  return time;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Usage: " << argv[0] << " <filename>" << endl;
    return 0;
  }
  ifstream file(argv[1]);
  if (file == NULL) {
    cerr << "Can't open file " << argv[1] << endl;
  }
  uint N; // Number of cases
  file >> N;
  do_times(N) {
    cout << fixed << setprecision(7);
    cout << "Case #" << i + 1 << ": " << solve_case(file) << endl;
  }
}
