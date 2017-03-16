#include <iostream>
#include <cmath>

using namespace std;

typedef long double ld;

int main(){
    cout.setf(ios::fixed);
    cout.precision(7);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t){
        ld C, F, X;
        cin >> C >> F >> X;
        ld rate = 2.0;
        ld time = 0.0;
        while (X*(rate + F) > C*(rate + F) + X*rate){
              time += C/rate;
              rate += F;
        }
        time += X/rate;
        cout << "Case #" << t << ": " << time << endl;
    }
}
