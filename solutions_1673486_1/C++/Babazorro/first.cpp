using namespace std;
#include <iomanip>
#include <assert.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <climits>

long double P;

double doit(int A,int B,vector<float>ps){
  double cont =P*(B-A+1)+(1-P)*(2*B+2);
  double enter = B+2;
  double best = min(cont,enter);

  double bck;
  for(unsigned int i=0;i< ps.size();++i){
    double p=ps[i];
    bck = p*(A-i+B-i-1)+(1-p)*(A-i+B-i+B);
    best = min(best,bck);
  }

  cerr << cont << " " << enter<<" "<<bck<<endl;
  return best;
}

int main(int argc, char **argv) {
  int T;
  cin >> T >> ws;
  for (int t = 1; t <= T; ++t) {
    int A, B;
    cin >> A >>B >>ws;
    vector <float> ps;
    P=1;
    for(int i=0;i<A;++i) {
      float p;
      cin >> p>>ws;
      P*=p;
      ps.push_back(P);
    }
      
    cout << "Case #" << t << ": " <<fixed<< setprecision(6)<< doit(A,B,ps) << endl;
  }
  
}
