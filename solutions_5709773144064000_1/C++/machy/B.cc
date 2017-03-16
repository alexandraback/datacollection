#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        double C, F, X;
        cin >> C >> F >> X;
        double cps = 2.0; // cookie per second
        double elapse = 0.0;
        double ans = X / cps;
        for(int i = 1; i < X; i++){
            elapse += C / cps;
            cps += F;
            double ans2 = elapse + X / cps;
            if(ans2 > ans) break;
            ans = ans2;
        }
        cout << setprecision(12) << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}



