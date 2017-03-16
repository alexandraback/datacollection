#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

double besttime (double c, double f, double x, double rate) {
  // Stop condition
  if (c + x*rate/(rate + f) > x) return x/rate;
  else return besttime (c,f,x,rate+f) + c/rate;
}

int main () {
  ifstream input;
  input.open("input");

  int ntest;
  input >> ntest;

  cout.precision(15);

  for (int k=0;k<ntest;k++) {
    double c,f,x;
    input >> c >> f >> x;

    cout << "case #" << k+1 << ": " << besttime(c,f,x,2) << endl;
  }

  input.close();
  return 0;
}
