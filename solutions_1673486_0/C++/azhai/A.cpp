#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <iomanip>

using namespace std;

const int N_MAX = 100005;

int A, B;
double p[N_MAX];
double success_prob[N_MAX];

double keep_typing_expectation(int num_delete) {
  int baseline = B - A + 2 * num_delete + 1;
  return baseline + (1 - success_prob[A - num_delete]) * (B + 1);
}

void solve_case(int case_num) {
  cin >> A >> B;
  for (int i = 0; i < A; i++) 
    cin >> p[i];
  success_prob[0] = 1.0;
  for (int i = 1; i <= A; i++) 
    success_prob[i] = p[i - 1] * success_prob[i - 1];

  double min_expectation = B + 2;
  for (int i = 0; i <= A; i++)
    min_expectation = min(min_expectation, keep_typing_expectation(i));
  cout << "Case #" << case_num << ": " 
       << setprecision(8) << fixed << min_expectation << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++)
    solve_case(i);
}
