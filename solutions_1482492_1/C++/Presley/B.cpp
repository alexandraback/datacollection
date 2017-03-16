#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

double solve(double a, double b, double c) {
  return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int ti = 0; ti < t; ti++) {
    double d;
    int n, m;
    scanf("%lf %d %d", &d, &n, &m);
    
    vector<double> t(n), x(n);
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf", &t[i], &x[i]);
    }
    
    if (n > 1) {
      t[n - 1] = t[n - 2] + (t[n - 1] - t[n - 2]) * (d - x[n - 2]) / (x[n - 1] - x[n - 2]);
    }
    x[n - 1] = d;
    
    printf("Case #%d:\n", ti + 1);
    for (int i = 0; i < m; i++) {
      double a;
      scanf("%lf", &a);
    
      double mx = 0, mt = 0, mv = 0;
      for (int i = 0; i < n; i++) {
        double dx = x[i] - mx;
        double dt = solve(0.5 * a, mv, -dx);
        if (t[i] <= mt + dt) {
          mt += dt;
          mv += dt * a;
        }
        else {
          mt = t[i];
          mv = dx / (t[i] - t[i - 1]);
        }
        mx = x[i];
      }
      printf("%.9lf\n", mt);
    } 
  }
  return 0;
}
