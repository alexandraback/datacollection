#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int caseIdx = 1; caseIdx <= T; ++ caseIdx)
    {
        double C,F,X;
        cin >> C >> F >> X;
        double minTime = X/2.0;
        double cookiePerSec = 2.0;
        double accumulateTime = 0.0;
        for(int nFarm = 0; nFarm <= X/C ; ++nFarm)
        {
            double curTime = accumulateTime + C/cookiePerSec + X/(cookiePerSec + F);
            if(curTime < minTime)
                minTime = curTime;
            accumulateTime += C/cookiePerSec;
            cookiePerSec += F;
        }
        cout << "Case #" << caseIdx << ": " << setprecision(18) << minTime << endl;
    }
    return 0;
}
