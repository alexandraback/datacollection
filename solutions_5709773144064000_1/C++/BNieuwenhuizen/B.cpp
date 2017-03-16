#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;


void testCase(unsigned id) {
  double C, F, X;
  double t = 0.0;
  double rate = 2.0;
  cin >> C >> F >> X;
  while(C/rate + X/(rate + F) < X/rate) {
    t += C/rate;
    rate += F;
  } 
  t += X/rate;
  cout.precision(10);
  cout.setf(ios::fixed);
  cout << "Case #" << id << ": " << t << "\n";
}


int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i)
    testCase(i);
  return 0;
}
