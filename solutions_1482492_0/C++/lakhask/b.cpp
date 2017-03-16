#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;
double X[200];
double T[200];
int main() {
    int t;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w+", stdout);

    cin>>t;
    int caseno = 1;
    while (t--!=0) {
        double D;
        int N,A;
        cin>>D;
        cin>>N>>A;
        for (int i=0;i<N;i++) {
            cin>>T[i]>>X[i];
        }
        printf("Case #%d:\n", caseno++);
        for (int i=0;i<A;i++) {
            double a;
            cin>>a;
            double t = sqrt(2.*D/a);
            if (N==2 && X[0] < D) {
                double V = (X[1] - X[0]) / (T[1] - T[0]);
                double tT = (D-X[0])/V + T[0];
                if (t < tT) t = tT;
            }
            printf("%.8lf\n", t);
        }
    }
    return 0;
}