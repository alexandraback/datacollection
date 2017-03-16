#include <iostream>
#include <iomanip>

using namespace std;

double solve(double c, double f, double x){
    double mini = x, time = 0, speed = 2.0;
    while(mini >= time + x / speed){
        mini = time + x / speed;
        time += c / speed;
        speed += f;
    }
    return mini;
}

int main(){
    unsigned t;
    cin >> t;
    for(unsigned i = 1; i <= t; i++){
        double c, f, x;
        cin >> c >> f >> x;
        cout << "Case #" << i << ": " << fixed << setprecision(7) << solve(c, f, x) << endl;
    }
}
