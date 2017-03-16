#include<iostream>
#include <cstdio>
#include<vector>

using namespace std;

double solve(double R, double C, double F, double X) {
    if (C + X*R/(R+F) < X) {
        return C / R + solve(R + F, C, F, X);
    } else {
        return X / R;
    }
}

int main() {
    int T; cin >> T;
    
    for(int t = 1; t <= T; ++t) {
        double R, C, F, X;
        R = 2;
        cin >> C >> F >> X;
        printf("Case #%d: %.7f\n", t, solve(R, C, F, X));
    }
}