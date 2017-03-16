#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <map>

using namespace std;

int points[1000];

void solve (int a_case)
{
  int N;
  double sum = 0;
  double target = 0;

  int NN = 0;
  double new_sum = 0;
  double new_target = 0;

  int m = 0;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> points[i];
    sum += points[i];
    if (points[i] > points[m]) m = i;
  }

  target = 2 * sum / N;
  fprintf(stderr, "%lf\n", target);

  for (int i = 0; i < N; ++i) {
    if (target >= points[i]) {
      new_sum += points[i];
      ++NN;
    }
  }

  new_target = (sum + new_sum) / NN;
  fprintf(stderr, "%lf\n", new_target);

  printf("Case #%d:", a_case);
  for (int i = 0; i < N; ++i) {
    if (target < points[i] && new_target < points[i]) {
      printf(" %lf", 0.0);
    } else {
      printf(" %lf", 100.0 * (new_target - points[i]) / sum);
    }
  }
  puts("");
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

