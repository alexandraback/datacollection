#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

double x[2001];
double t[2001];
double v[2001];
double ai[251];

int main() {
  int T, N, A, num=1;
  double D;
  int i,j;
  double x0, v0; // our position at the beginning of each cycle
  double x1, v1; // our position at the end       of each cycle
  double tc    ; // time of collision
  double vi,xi ; // for ease of notation
  double dt    ; // t[i+1] - t[i]
  double dx    ; // x[i+1] - x[i]
  double a     ; // a[i]
  double endt  ;
  double vp    ;
  for (cin >> T; T--;) {
    cin >> D >> N >> A;
    for (i = 0; i < N; i++) cin >> t[i] >> x[i];
    for (i = 0; i < A; i++) cin >> ai[i];

    for (i = 0; i < N-1; i++) v[i] = (x[i+1]-x[i])/(t[i+1]-t[i]);
#if 0
    if (x[N-1] >= D) {
      x[N-1] = D;
      t[N-1] = t[N-2] + (D - x[N-2])/v[N-2];
    }
#endif

    printf("Case #%d:\n", num++);

    for (j = 0; j < A; j++) {
      a = ai[j];

      // Init
      x0   = 0.;
      v0   = 0.;

      for (i = 0; i < N-2; i++) {
        // If no brake applied, position at the end of this cycle
        dt = t[i+1] - t[i];
        x1 = x0 + v0*dt + a*dt*dt/2;

        if (x1 > x[i+1]) {  // collision
          x0 = x[i+1];
          dx = x[i+1] - x[i];
          vp = sqrt(2*a*dx);
          v0 = max(vp,v[i]);
        } else {            // no collision
          x0 = x1;
          v0 = v0 + a*(t[i+1] - t[i]);
        }
      }

      if (N < 2) endt = 0;
      else       endt = t[N-2];
      dt = (-v0 + sqrt(2*a*D+v0*v0-2*a*x0))/a; // time to get to the finish line
      if (x[i] + v[i]*dt >= D) {
        endt += dt;
      }
      else {
        endt += (D - x[N-2])/v[N-2];
      }


#if 0
      endt = t[N-1];
      if (x0 < D)
        endt += (-v0 + sqrt(2*a*D+v0*v0-2*a*x0))/a;
#endif

#if 0
      for (i = 0; i < N-1; i++) {
        vi = v[i];
        xi = x[i];
        dt = t[i+1] - t[i];
        tc = (vi - v0 + sqrt(v0*v0 - 2*v0*vi + vi*vi + 2*a*xi - 2*a*x0))/a;
        if (i != N-1) {
          if (tc >= dt) {            // no collision this cycle
            x0 = x0 + v0*dt + a*dt*dt/2;
            v0 = v0 + a*dt;
          } else {                   // collision this cycle
            x0   = x[i+1];
            v0   = vi;
          }
        }
      }
#endif

#if 0
      endt = t[N-1];
      if (x0 < D)
        endt += (-v0 + sqrt(2*a*D+v0*v0-2*a*x0))/a;
#endif

      printf("%.10lf\n", endt);
    }

  }

}
