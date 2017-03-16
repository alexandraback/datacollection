#include <map>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void solve (int a_case) {

  int A, B;
  cin >> A >> B;

  double P = 1.0;
  double best = A + B + 1;

  for (int i = 1; i <= A; ++i) {
    double p;
    cin >> p;
    P *= p;

    double x = (A - i) + (A - i) + (B - A) + 1 + (1 - P) * (B + 1);
    if (x < best) best = x;
  }

  double x = 1 + B + 1;
  if (x < best) best = x;

  printf("Case #%d: %lf\n", a_case, best);
}

int main ()
{
  int n;
  string dummy;

  cin >> n;
  getline(cin, dummy);
  for (int i = 0; i < n; ++i) solve(i+1);

  return 0;
}



