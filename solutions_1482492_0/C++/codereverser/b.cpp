#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

double X[2001];
double T[2001];
double As[250];
bool found;
set<int> seen;
double newton(double x, double v, double a, double d) { 
    double oldx = x;
    double nextx = oldx;
    do { 
        oldx = nextx;
        nextx = oldx - (v*oldx + 0.5*a*oldx*oldx - d)/(v+a*oldx);
    } while (fabs(nextx-oldx) > 0.000000001);
    return nextx;
}
double timecalc(double D, int N, double A) { 
    double result = 0.0;
    double distance = 0.0;
    double startX = 0.0;
    double startT = 0.0;
    double startV = 0.0;
    for (int i=0; i<N; i++) { 
        double endX = X[i]; double endT = T[i];
        double deltaT = endT - startT;
        double carVel = (endX-startX)/deltaT;
        if (endX >= D) { 
            double time_us = newton(0.1, startV, A, D-distance);
            distance = D;
            double time_car = (D-startX)/carVel;
            if (time_car > time_us) result += time_car;
            else result += time_us;
            break;
        } else { 
            double dist = distance + startV*deltaT + 0.5*A*deltaT*deltaT;
            if (dist > endX) {
                result += deltaT;
                double time_us = newton(0.1, 0, A, endX - distance);
                distance = endX;
                startV = A*time_us;
            } else { 
                distance += dist;
                result += deltaT;
                startV += A*deltaT;
            }
            startX = endX;
            startT = endT;
        }
    }
    return result;
}

main() {
  int C, N, A, prob = 1;
  int M;
  int i, j, from, to;
  double D;
  for (cin >> C; C--;) {
    cin >> D >> N >> A;
    for (i=0; i<N; i++) {
        cin >> T[i] >> X[i];
    }
    for (i=0; i<A; i++) {
        cin >> As[i];
    }
    printf("Case #%d:\n", prob++);
    
    for (i=0; i<A; i++) { 
        printf("%0.10lf\n", timecalc(D, N, As[i]));
    }
  }
}
