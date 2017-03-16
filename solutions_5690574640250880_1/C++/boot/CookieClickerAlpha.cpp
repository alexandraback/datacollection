
#include <cstdio>
#include <iostream>
#include <iomanip>

#define RATE 2.0

using namespace std;

double bestfarm (double rate, double c, double f, double x) {
    double t1, t2, 
        stime = 0.0, 
        btime = x/rate;
    
    do {
        t1 = stime + x/rate;
        t2 = stime + c/rate + x/(rate + f);
        stime += c/rate;
        rate += f;
    
        if (t1 < btime) {
            btime = t1;
        }
        if (t2 < btime) {
            btime = t2;
        }
    } while(t2 <= btime);
    
    return btime;
}

int main (void) {
    int cases;
    double c, f, x;
    
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    
    cin >> cases;
    cout << setprecision(7) << fixed;
    
    for (int t = 1; t <= cases; t++) {
        cin >> c >> f >> x;
        cout << "Case #" << t << ": " << bestfarm(RATE, c, f, x) << endl;
    }
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
