#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<double> VD;

#define TDOUBLE(X) static_cast<double>((X))

double all_right_prob(int n, VD& protab) {
  double t = 1;
  for (int i = 0; i < n; ++i) {
    t *= protab[i];
  }
  return t;
}

void run(istream& in, ostream& ou, int t) {
  int A, B;
  in >> A >> B;
  VD protab, res;
  for (int i = 0; i < A; i++) {
    double p;
    in >> p;
    protab.push_back(p);
  }
  // solution1
  {
    double p = all_right_prob(A, protab);
    res.push_back(TDOUBLE(B-A+1)*p+TDOUBLE(2*B-A+2)*(1.-p));
  }
  // solution2
  {
    for (int n = 1; n <= A; n++) {
      double p = all_right_prob(A-n, protab);
      res.push_back(TDOUBLE(B-A+2*n+1)*p+TDOUBLE(B-A+2*n+1+B+1)*(1.-p));      
    }
  }
  // solution3
  {
    res.push_back(TDOUBLE(1+B+1));
  }
  sort(res.begin(), res.end());
  ou<<"Case #"<<t<<": ";
  ou.precision(6);
  ou.setf(ios::fixed,ios::floatfield);
  ou<<res[0]<<endl;
  
  //for(int i = 0; i < res.size(); i++) {
  //  cout<<"  "<<res[i]<<endl;
  //}
}

int main(int argc, char** argv) {
  ifstream in(argv[1]);
  int c;
  in >> c;
  for (int i = 0; i < c; i++) {
    run(in, cout, i+1);
  }
}
