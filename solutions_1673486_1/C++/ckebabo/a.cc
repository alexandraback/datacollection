#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

double foo(int A, int B, vector<double> &v) {
    double ret = B*3;
    double r;

    // keep typing
    r = 1;
    for(int i=0;i<A;i++) r *= v[i];
    ret = r*(B-A+1) + (1-r)*(B-A+1+B+1);

    // enter right away
    ret = min(ret, 1+B+1.);

    // remove all
    ret = min(ret, A+B+1.);

    // press backspace
    for(int i=1;i<A;i++) {
        int n = A-i;
        r = 1;
        for(int j=0;j<n;j++) r *= v[j];
        ret = min(ret, r*(B-n+1+i) + (1-r)*(B-n+1+B+1+i));
    }

    return ret;
}

int main() {
    int T;
    int A,B;

    cin >> T;
    for(int cs=1;cs<=T;cs++) {
        cin >> A >> B;
        vector<double> v(A);
        for(int i=0;i<A;i++) cin >> v[i];

        printf("Case #%d: %f\n", cs, foo(A,B,v));
    }

    return 0;
}
