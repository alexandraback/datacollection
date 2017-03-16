#include <cstdio>
#include <iostream>
using namespace std;

int i, t, T;
double C, F, X, R, M, time, cur;

int main(){ 
  cin >> T;
  while (++t<=T) {
    cin >> C >> F >> X;
    cur = 2;
    M = X/cur;
    time = 0;
    R = time + C/cur + X/(cur+F);
    while (R < M) {
      M = R;
      time += C/cur;
      cur += F;
      R = time + C/cur + X/(cur+F);
    }
    printf("Case #%d: %.7f\n", t, M);
  }
}

