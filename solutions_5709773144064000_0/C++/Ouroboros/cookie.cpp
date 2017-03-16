#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

// global
int T;
double C,F,X;


double solve() {
  double prod = 2;
  double nextBuild,totalTime,totalBuild,nextTime;
  nextTime = X/prod;
  totalBuild = 0;
  do { 
    totalTime = nextTime;
    nextBuild = C/prod;
    totalBuild += nextBuild;
    prod += F;
    nextTime = X/prod + totalBuild;
    //printf("nextTime = %.7f\n",nextTime);
  } while (nextTime < totalTime);
  return totalTime;
}

int main() {
  cin >> T;
  int run = 0;
  while (run++ < T) {
    fprintf(stderr,"doing case %d\n",run);
    cin >> C >> F >> X;
    //printf("c = %f, f = %f, x = %f\n",C,F,X);
    double result = solve();
    printf("Case #%d: %.7f\n",run,result);
  }
}
