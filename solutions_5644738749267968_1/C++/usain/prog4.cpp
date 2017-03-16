#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

double a[1000], b[1000];
int u[1000];

int comp(const void *x, const void *y) {
  double v1 = *(double *)x;
  double v2 = *(double *)y;
  if (v1 < v2)
    return 1;
  if (v2 < v1)
    return -1;
  return 0;
}

int best_war(int n, double v) {
  int p = -1;
  int l = -1;
  for (int i = 0; i < n; i++) {
    if (!u[i]) {
      if (v < b[i]) {
        if (p >= 0)
          return p;
        else 
          l = i;
      } else
        p = i;
    }
  }

  if (l >= 0)
    return l;

  return p;
}
        

int war(int n) {
  int v = 0;

  for (int i = 0; i < n; i++)
    u[i] = 0;

  for (int i = 0; i < n; i++) {
    int pos = best_war(n, a[i]);
    if (pos < 0)
      cout << "unextected value " << pos << endl;
    u[pos] = 1;
    if (a[i] > b[pos])
      v++;
  }

  return v;
}

int best_dwar(int n, double v) {
  int p = -1;

  for (int i = 0; i < n; i++) {
    if (!u[i]) {
      if (v > a[i]) {
        if (p >= 0)
          return p;
        else
          return -1;
      } else
        p = i;
    }
  }

  return p;
}

int dwar(int n) {
  int v = 0;

  for (int i = 0; i < n; i++)
    u[i] = 0;

  for (int i = n-1; i >= 0; i--) {
    int pos = best_dwar(n, b[i]);
    if (pos < 0)
      break;

    u[pos] = 1;
    v++;
  }

  return v;
}

int main() {
  ifstream in("D-large.in");
  ofstream out("D-large.out");

  int tests;
  in >> tests;
  for (int i = 1; i <= tests; i++) {
    int n;
    in >> n;
    for (int j = 0; j < n; j++)
      in >> a[j];
    for (int j = 0; j < n; j++)
      in >> b[j];

    qsort(a, n, sizeof(double), comp);
    qsort(b, n, sizeof(double), comp);

    out << "Case #" << i << ": " << dwar(n) << " " << war(n) << endl;
  }

  in.close();
  out.close();

  return 0;
}
