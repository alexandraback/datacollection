#include <iostream>
#include <iomanip>
using namespace std;

double solve(double priceOfFarm, double farmProduction, double target) {
    double production = 2.0, elapsed_t = 0.0, new_t, current_t;
    while(1) {
        new_t = (target / (production + farmProduction)) + (priceOfFarm / production);
        current_t = target / production;
        if(new_t < current_t) {
            elapsed_t += priceOfFarm / production;
            production += farmProduction;
        } else {
            return (elapsed_t + current_t);
        }
    }
}

int main()
{
    int T;
    double C, F, X;
    cin >> T;
    cout << fixed << setprecision(7);
    for(int t = 1; t <= T; t++) {
        cin >> C >> F >> X;
        cout << "Case #" << t << ": " << solve(C, F, X) << '\n';
    }
    cout << flush;
    return 0;
}