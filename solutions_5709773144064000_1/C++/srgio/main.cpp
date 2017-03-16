#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int tests, t = 1;
    double c,f,x,cps,tt,t1,t2,t3;
    cin >> tests;
    while(tests--){
        cps = 2;
        tt = 0;
        cin >> c >> f >> x;
        t1 = x/cps;
        t2 = c/cps;
        t3 = x/(cps+f);
        while( t1 > (t2+t3)){
            tt += t2;
            cps += f;
            t1 = x/cps;
            t2 = c/cps;
            t3 = x/(cps+f);
        }
        tt += t1;
        cout << "Case #" << t << ": " << fixed << setprecision(7) << tt << endl;
        t++;
    }
    return 0;
}
