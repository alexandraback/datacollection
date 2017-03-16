#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int _A_MAX = 100010;
int _A, _B;
double _p[_A_MAX];
double _pp[_A_MAX];

void solve(int run) {
  scanf("%d %d", &_A, &_B);
  for (int i = 1; i <= _A; ++i)
    scanf("%lf", &_p[i]);
  _pp[0] = 1;
  for (int i = 1; i <= _A; ++i) {
    _pp[i] = _pp[i-1] * _p[i];
  }
  double expect = 0;
  //keep typing
  expect = _pp[_A] * (_B-_A+1) + (1-_pp[_A]) * (_B-_A+1+_B+1);
  //press enter right away
  expect = min(expect, _B + 2.0);
  //backspace to ith
  for (int i = 1; i <= _A; ++i) {
    expect = min(expect, _pp[i-1]*(_A-i+1.0+_B-i+2)+(1-_pp[i-1])*(_A-i+1+_B-i+2+_B+1));
  }
  printf("Case #%d: %.6lf\n", run, expect);
}


int main() {
  int runs;
  scanf("%d", &runs);
  for (int i = 1; i <= runs; ++i) {
    solve(i);
  }
  return 0;
}
