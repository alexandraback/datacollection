#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double ti[2], xi[2];

int main() {
    int T;
    cin >> T;
    for(int te=1;te<=T;te++) {
        double D;
        int N, A;
        cin >> D >> N >> A;
        for(int i=0;i<N;i++) cin >> ti[i] >> xi[i];
        cout << "Case #" << te << ":" << endl;
        if(N == 1) {
            while(A--) {
                double ac;
                cin >> ac;
                cout << fixed << setprecision(8) << sqrt(D*2/ac) << endl;
            }
            continue;
        }
        double u = (xi[1] - xi[0]) / ti[1];
        double mt = (D - xi[0]) / u;
        while(A--) {
            double ac;
            cin >> ac;
            
            double tr = (u + sqrt(u*u + ac*xi[0]*2)) / ac;
            if(tr <= mt) cout << fixed << setprecision(8) << mt << endl;
            else cout << fixed << setprecision(8) << sqrt(D*2 / ac) << endl;
        }
    }
    return 0;
}
