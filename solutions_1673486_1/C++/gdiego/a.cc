#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;
double solvecase() {
  int A, B;
  cin >> A >> B;
  vector<double> probs(A + 1, 1);
  for (int x = 1; x <= A; x++) {
    cin >> probs[x];
  }

  double prob = 1;
  double expected = 1 + B + 1;
  for (int x = 0; x <= A; x++) {
    prob *= probs[x];
    int keystrokes = (A - x) * 2 + B - A + 1;
    int keystrokesM = keystrokes + B + 1;
    expected = min(expected, prob * keystrokes + (1 - prob) * (keystrokesM));
  }  
  
  return expected;
}
int main() {
  int N;
  cin >> N;
  for (int x = 1; x <= N; x++) {
    cout << "Case #" << x << ": ";
    printf("%.6f\n", solvecase());
  }
  return 0;
}

