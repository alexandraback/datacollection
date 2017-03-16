#include <iostream>

using namespace std;

int main(int arg, char* argv[]) {
  int T;
  cin >> T;
  for (int c = 1; c <= T; c++) {
    double C, F, X;
    cin >> C >> F >> X;
    double ans = X/2;
    double time = 0;
    double rate = 2;
    while (true) {
      time += C / rate;
      rate += F;
      double score = time + X / rate;
      if (score > ans) {
        break;
      }
      ans = score;
    }
    printf("Case #%d: %.09f\n", c, ans);
  }
}
