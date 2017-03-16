#include <iostream>
#include <string.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
#include <list>
#include <map>

using namespace std;

long double t[2000];
long double x[2000];
long double a[250];

long double eq2 (long double a, long double b, long double c) {
  long double root = b*b - 4*a*c;

  // printf("%lf %lf %lf = %lf\n", a,b,c,root);
  if (root < 0) {
    //printf("eRROR\n");
    return 0;
  }

  long double neg = (-b - sqrt(root)) / (2*a);
  long double pos = (-b + sqrt(root)) / (2*a);

  if (neg >= 0) return neg;
  if (pos >= 0) return pos;
    //printf("eRROR\n");
  return 0;
}

void solve (int a_case)
{
  int N, A;
  long double D;
  cin >> D >> N >> A;

  for (int i = 0; i < N; ++i) {
    cin >> t[i] >> x[i];
  }

  if (x[N - 1] > D) {
    // interpolate the last.
    t[N - 1] = (t[N] - t[N - 1]) / (x[N] - x[N - 1]) * (D - x[N - 1]) + t[N - 1];
    x[N - 1] = D;
  }

  for (int i = 0; i < A; ++i) { cin >> a[i]; }

  printf("Case #%d:\n", a_case);
  for (int i = 0; i < A; ++i) {
    long double ct = 0;
    long double cx = 0;
    long double cv = 0;
    long double ca = a[i];

    // printf("+++ %lf %lf %lf %lf\n", ct, cx, cv, ca);
    ct = eq2(ca/2, 0, 0 - x[0]);
    cx = x[0];
    cv = cv + ca*ct;

    // printf("+++ %lf %lf %lf %lf\n", ct, cx, cv, ca);
    for (int j = 0; j < N - 1; ++j) {
      long double t2 = ct + eq2(ca/2, cv, x[j] - x[j + 1]);

      // printf("CMP %lf <= %lf\n", t2, t[j + 1]);

      if (t2 <= t[j + 1]) {
        cx = x[j + 1];
        cv = cv + ca*(t2 - t[j]);
        ct = t[j + 1];
      } else {
        cx = x[j + 1];
        cv = cv + ca*(t2 - t[j]);
        ct = t2;
      }
      //printf("+++ %lf %lf %lf %lf\n", ct, cx, cv, ca);
    }

    printf("%llf\n", ct);
  }
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

