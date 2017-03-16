#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>


using namespace std;

#define PI acos(-1.)
#define EPS 1e-7
#define LL long long
#define U unsigned int
#define LU long unsigned
#define LLU long long unsigned


LLU factorial(LU n) {
  LU base = 1;
  LLU fac = 1;
  while (base <= n) {
    fac *= base;
    ++base;
  }
  return fac;
}

int main() {
  // Declare members
  int num_case;
  cin >> num_case;
  LU N, X, Y;

  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    double p = 0.0;
    cin >> N;
    long int temp;
    cin >> temp;
    if (temp < 0) X = -temp;
    else X = temp;

    cin >> Y;
    LU sum = ((X + Y)/2)*(X + Y - 1);
    LU min;
    if (X != 0) {
      min = sum + X + Y + Y + 1;

      if (min <= N) {
        p = 1;
      } else if (N < sum + Y + 1) {
        p = 0;
      } else {
        LU left = N - sum;
        LLU num = 0;
        for (LU Z = Y + 1 ; Z <= left; ++Z) {
          //cerr << "fact " << left << " " << Z << endl;
          num += factorial(left)/(factorial(Z)*factorial(left - Z));
          //cerr << "done" << endl;
        }
        p = num*pow(0.5, left);
      }
    } else {
      min = ((X + Y + 2)/2)*(X + Y + 1);
      if (N >= min) p = 1.0;
      else p = 0.0;
    }

    // Print output for case j
    cout << "Case #" << nc << ": " << setprecision(6) << p << endl;
  }


  return 0;
}

