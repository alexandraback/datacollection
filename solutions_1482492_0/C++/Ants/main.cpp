/* 
 * File:   main.cpp
 * Author: Ants
 *
 * Created on May 6, 2012, 11:52 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

double x[2010];
double t[2010];


int main(int argc, char** argv) {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case #" << tt << ":" << endl;
        
        double D;
        int N, A;
        cin >> D >> N >> A;
        
        for (int i = 0; i < N; i++) {
            cin >> t[i] >> x[i];
        }
        
        for (int i = 0; i < N; i++) {
            if (x[i] > D) {
                if (i == 0) {
                    N = 0;
                    break;
                } else {
                    t[i] -= (t[i] - t[i-1])*(x[i] - D)/(x[i] - x[i-1]);
                    x[i] = D;
                    N = i+1;
                    break;
                }
            }
        }
        
        for (int i = 0; i < A; i++) {
            double a;
            cin >> a;
            double max_ts = 0.0;
            for (int j = 0; j < N; j++) {
                double ts = t[j] - sqrt(2.0*x[j]/a);
                if (ts > max_ts) max_ts = ts;
            }
            
            cout.precision(16);
            cout << fixed << sqrt(2*D/a) + max_ts << endl;
            
        }
        
        
        
        
    }
    return 0;
}

