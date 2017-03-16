#include <iostream>
#include <iomanip>

#include <cmath>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
double A[256];

int main() {
    int T;
    cin >> T;
    FOR(te,1,T+1) {
        int N;
        cin >> N;
        double su = 0;
        FOR(i,0,N) {
            cin >> A[i];
            su += A[i];
        }
        FOR(i,0,N) A[i] /= su;
        cout << "Case #" << te << ":";
        FOR(i,0,N) {
            double ma = 1.0, mi = 0.0;
            int it = 100;
            while(fabs(ma-mi) > 1e-8 && it) {
                double mid = (mi+ma)/2;
                double su = 0;
                FOR(j,0,N) {
                    if(j==i) continue;
                    su += max(0.0, A[i]+mid-A[j]);
                }
                if(su+mid < 1.0 - 1e-9) mi = mid;
                else ma = mid;
                it--;
            }
            cout << " " << fixed << setprecision(6) << (mi+ma)*50;
        }
        cout << endl;
    }
    return 0;
}
