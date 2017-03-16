#include <cstdio>
#include <iostream>
#include <vector>
#include <set>


using namespace std;


int main() {

 FILE *inf = fopen("i.in", "r");
 FILE *of = fopen("o.out", "w");
 int num_tests;
 fscanf(inf, "%d", &num_tests);
  for (int t = 1; t <= num_tests; ++t) {
    int N, X = 0, c = 0;
    fscanf(inf, "%d", &N);
    vector<int> v(N);
    vector<double> u;
    u.assign(N, -1.0);

    for (int i = 0; i < N; ++i) {
      fscanf(inf, "%d", &v[i]);
      X += v[i];
    }
    double total = 2.0 * X;
    double min_p = total / double(N);
    int x = X;


    for (int i = 0; i < N; ++i) {
      u[i] = (min_p - v[i]) / X * 100.0;
      if (u[i] < 0.0) { u[i] = 0.0; ++c; x -= v[i];}
    }
    
    min_p = (X + x) / double(N-c);
    for (int i = 0; i < N; ++i) {
         u[i] = (min_p - v[i]) / X * 100.0;
         if (u[i] < 0.0) u[i] = 0.0;
      }

    
    fprintf(of, "Case #%d: ", t);
    for (int i = 0; i < N; ++i) {
      fprintf(of, "%.6llf ", u[i]);
    }
    fprintf(of, "\n", t);
  }


  fclose(inf);
  fclose(of);
  return 0;
}