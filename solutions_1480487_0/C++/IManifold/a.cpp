#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const double EPS = 1e-15;
const int MAX = 210;
double points[MAX], sum;
int n;

double solve(int index) {
  double min = 0.0;
  double max = 1.0;
  double mid = 0.5;
  //printf("min = %lf max = %lf mid = %lf\n", min, max, mid);
  while (max - min > EPS) {
    mid = (min + max) / 2.0;
    double score = mid * sum + points[index];
    double votes = 1.0 - mid;
    for (int i = 0; i < n; i++) {
      if (i == index) continue;
      if (points[i] < score) {
        votes -= ((score - points[i]) / sum);
        if (votes < 0) break;
      }
    }
    if (votes < 0) max = mid;
    else min = mid;
  }
  return mid * 100.0;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int t = 1; t <= tt; t++) {
    scanf("%d", &n);
    sum = 0.0;
    for (int i = 0; i < n; i++) {
      scanf("%lf", &points[i]);
      sum += points[i];
      //printf("%lf ", points[i]);
    }
    //printf("\n");
    printf("Case #%d:", t);
    for (int i = 0; i < n; i++) {
      printf(" %lf", solve(i));
    }
    printf("\n");
  }
  return 0;
}
