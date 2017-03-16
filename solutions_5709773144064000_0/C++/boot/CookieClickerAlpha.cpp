
#include <cstdio>
#include <iostream>
#include <iomanip>

#define RATE 2.0

using namespace std;

double bestfarm(double rate, double c, double f, double x, double stime, double btime) {
    double t1 = stime + x/rate;
    double t2 = stime + c/rate + x/(rate + f);
    
    if (btime < t1 && btime < t2) {
        return btime;
    } else if (t1 < t2) {
        return t1;
    } else {
        return bestfarm(rate + f, c, f, x, stime + c/rate, t2);
    }
}

int main (void) {
    int cases;
    double c, f, x;
    
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    
    cin >> cases;
    cout << setprecision(7) << fixed;
    
    for (int t = 1; t <= cases; t++) {
        cin >> c >> f >> x;
        cout << "Case #" << t << ": " << bestfarm(RATE, c, f, x, 0, x/RATE) << endl;
    }
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
