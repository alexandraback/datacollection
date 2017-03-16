#include<iostream>
#include <cstdio>
#include<vector>

using namespace std;

int main() {
    int T; cin >> T;
    
    for(int t = 1; t <= T; ++t) {
        double R, C, F, X;
        R = 2;
        cin >> C >> F >> X;
        
        double sum = 0;
        while(true) {
            if (C + X*R/(R+F) < X) {
                sum += C / R;
                R += F;
            } else {
                sum += X / R;
                break;
            }
        }
        
        printf("Case #%d: %.7f\n", t, sum);
    }
}