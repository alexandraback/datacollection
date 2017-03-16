#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

#define REAL double

void main_1C_B() {
    unsigned int T;

    cin >> T;
    for (unsigned int i=0;i<T;++i) {
        REAL D;
        unsigned int N,A;

        cin >> D >> N >> A;

        vector<REAL> t(N);
        vector<REAL> x(N);

        for(unsigned int j=0;j<N;++j) {
            cin >> t[j] >> x[j];
        }
        for(unsigned int j=0;j<N;++j) {
            if (x[j] >= D) {
                if (j == 0) {
                    x[j] = D;
                } else {
                    t[j] = t[j-1] + (t[j]-t[j-1])*(D-x[j-1])/(x[j]-x[j-1]);
                    x[j] = D;
                }
                x.resize(j+1);
                t.resize(j+1);
                N = j+1;
                break;
            }
        }

        cout << "Case #" << (i+1) << ":" << endl;

        for(unsigned int j=0;j<A;++j) {
            REAL a;
            cin >> a;

            REAL v = 0;
            REAL pos = 0;
            REAL tau;
            for (unsigned int k=1;k<N;++k) {
                tau = t[k]-t[k-1];
                if ((sqrt(v*v+2*a*(x[k]-pos))-v)/a < tau) {
                    pos = x[k];
                    v = sqrt(v*v+2*a*x[k]);
                } else {
                    pos = pos + v*tau + a*tau*tau/2;
                    v = v+a*tau;
                }
            }
            cout << fixed << setprecision(7) << t[N-1]+(sqrt(v*v+2*a*(x[N-1]-pos))-v)/a << endl;
        }
    }
}

