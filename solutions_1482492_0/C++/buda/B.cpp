#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>

using namespace std;

double t[2000], x[2000];
double a[250];
const double EPS = 1e-12;
double calc(double a, double b, double c) {
    double D = b*b - 4*a*c;
    return (-b + sqrt(D))/2/a;
}
int main() {
    cin.sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(6);
    int T;
    cin >> T;
    for (int c=1; c<=T; ++c) {
        double D;
        int N, A;
        cin >> D >> N >> A;
        for (int i=0; i<N; ++i) {
            cin >> t[i] >> x[i];
        }
        for (int i=0; i<A; ++i) {
            cin >> a[i];
        }

        cout << "Case #" << c << ":\n";
        for (int i=0; i<A; ++i) {
            if (x[0] >= D-EPS) {
                cout << sqrt(2*D/a[i]) << '\n';
                continue;
            }
            double curt = sqrt(2*x[0]/a[i]);
            double curv = a[i]*curt;
            for (int j=1; j<N; ++j) {
                double dt = t[j] - t[j-1];
                double dx = x[j] - x[j-1];
                double v_other = dx/dt;
                if (x[j] >= D-EPS) {
                    double t_me = calc(a[i]/2, curv, x[j-1]-D);
                    cout << max(t[j-1] + (D-x[j-1])/v_other, curt + t_me) << '\n';
                    break;
                } else {
                    double t_me = calc(a[i]/2, curv, -dx);
                    if (curt+t_me >= t[j]-EPS) {
                        curt += t_me;
                        curv += a[i]*t_me;
                    } else {
                        curt = t[j];
                        curv = v_other;
                    }
                }
            }
        }
    }
	return 0;
}
