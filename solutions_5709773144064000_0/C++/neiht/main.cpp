#include <iostream>

using namespace std;

int main() {
    int t; // number of test cases;
    int curCase = 1;
    double cost, rateInc, goal;

    cin >> t;
    while (t--) {
       cin >> cost >> rateInc >> goal; 

       double curTime = 0.0;
       double curCookies = 0.0;
       double curRate = 2.0;

       // Keep buying farms until it no long worths it
       while (curCookies < goal) {
           double noFarm = (goal - curCookies) / curRate;
           double buyFarm = ((cost - curCookies) / curRate) +
                            (goal / (curRate + rateInc));

           if (noFarm < buyFarm) {
               curTime += noFarm;
               curCookies = goal;
           } else {
               curTime += (cost - curCookies) / curRate;
               curRate += rateInc;
               curCookies = 0;
           }
       }

       cout.precision(7);
       cout << "Case #" << curCase << ": " << curTime << fixed << endl;
       curCase++;
    }

    return 0;
}
