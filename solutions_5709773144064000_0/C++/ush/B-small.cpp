
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define ALLOF(s) ((s).begin()), ((s).end())

typedef long long ll;



inline double calcT(double target, double d) {
  return target / d;
}

int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    double cost, farmGain, goal;
    cin >> cost >> farmGain >> goal;
    double gain = 2;
    double res = goal;
    double t = 0;
    while(true){
      if(res < t + calcT(goal, gain)){
	break;
      }
      res = t + calcT(goal, gain);
      t += calcT(cost, gain);
      gain += farmGain;
    }
    
    printf("Case #%d: %.10f\n", iCase+1, res);
  }
  
  return 0;
}
