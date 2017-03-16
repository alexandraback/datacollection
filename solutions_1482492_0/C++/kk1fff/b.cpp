#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

double x[2001];
double t[2001];
int N, A;
double D;

void run(istream& in, ostream& ou, int c) {
  in >> D;
  in >> N;
  in >> A;
  for (int i = 0; i < N; i++) {
    in >> t[i] >> x[i];
  }
  ou << "Case #" << c << ": " << endl;
  for (int aa = 0; aa < A; aa++) {
    double a;
    in >> a;
    // printf("a = %f ===============\n", a);
    double myT = 0.;
    double myX = 0.;
    double myV = 0.;
    for (int i = 0; i < N; i++) {
      double target = min(x[i], D);
      double dist = target - myX;
      // printf("dist = %f\n", dist);
      double targetT = t[i];
      if (D < x[i]) {
        if (i == 0) {
          targetT = 0.;
        } else {
          targetT = dist / ((x[i] - x[i - 1])/(t[i] - t[i-1])) + myT;
        }
      }
      //  printf("targetT = %f\n", targetT);
      double tdiff = targetT - myT;
      if (tdiff == 0.) continue;
      double needa = (2. * (dist - myX - myV * tdiff)) / (tdiff * tdiff);
      if (needa > a) {
        continue;
      } else {
        myX = target;
        myT = targetT;
        myV = myV + needa * tdiff;
      }
    }
    // printf("myX = %f, myT = %f, myV = %f\n", myX, myT, myV);
    if (myX < D) {
      double d = D - myX;
      double dt = (-myV + sqrt(myV*myV+2*a*d))/a;
      myT += dt;
    }
    ou.precision(10);
    ou.setf(ios::fixed,ios::floatfield);
    ou << myT << endl;
  }
}

int main(int c, char** v) {
  ifstream in(v[1]);
  int T;
  in >> T;
  for (int i = 0; i < T; i++) {
    run(in, cout, i+1);
  }
}
