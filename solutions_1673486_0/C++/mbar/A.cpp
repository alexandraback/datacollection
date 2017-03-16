#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>

using namespace std;

typedef vector<double> vd;

int main() {
    int T;
    cin >> T;
    for (int cs=1; cs<=T; ++cs) {
        int A, B;
        cin >> A >> B;
        vd p(A+1);
        p[0] = 1.0;
        for (int j=1; j<=A; ++j) {
            cin >> p[j];
            p[j] *= p[j-1];
        }

        double E, M=10000000;
        for (int d=0; d<=A; ++d) {
            E = 2*d + B + 1 + (1-p[A-d])*(B+1);
            if (M>E) M=E;
        }
        E = A+B+2;
        if (M>E) M=E;
        M -= A;
        printf("Case #%d: %.6f\n", cs, M);
    }
}
