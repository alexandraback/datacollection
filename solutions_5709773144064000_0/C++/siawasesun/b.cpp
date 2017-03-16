#include <bits/stdc++.h>

using namespace std;

double C, F, X;
map<int, double> time_to_buy;

void Input() {
  cin >> C >> F >> X;
}

inline double Speed(int k) {
  return 2.0 + F * k;
}

double Calc(int k) {
  if (k == 0) {
    time_to_buy[0] = 0.0;
  } else {
    time_to_buy[k] = time_to_buy[k - 1] + C / Speed(k - 1);
  }
  return time_to_buy[k] + X / Speed(k);
}

double Calc2(int k) {
  
}

void Solve() {
  time_to_buy.clear();

  double res = X / 2.0;
  for (int i = 0; i <= 50010; i++) {
    res = min(res, Calc(i));
  }

  printf("%.7f", res);
}

int main(int argc, char **argv) {
  int T;
  scanf("%d", &T);

  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");
  }
  return 0;
}
