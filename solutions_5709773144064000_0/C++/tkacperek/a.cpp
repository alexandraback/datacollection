#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    cout.precision(7);
    cout.setf(ios::fixed);
    int i,j,k,T;
    double C,F,X,p,tmin,t,fsum; // farm, farm+, goal
    cin >> T;
    for (i=0; i<T; i++) {
        cin >> C >> F >> X;
        p=2; // per second
        fsum=0; // farm sum
        
        tmin=t=X/p; // t0
        
        // t 1..n
        while (t<=tmin) {
            tmin=t;
            fsum+=C/p;
            p+=F;
            t=fsum+X/p;
        }
        printf("Case #%d: ",i+1);
        cout << tmin << endl;
    }
    return 0;
}