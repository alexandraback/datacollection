#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;

ifstream in;
ofstream out;

int T;
double C,F,X;

int main ()
{
    // Create input/Output Streams
    in.open("A.in");
    out.open("A.out");
    
    //Read N
    in >> T;
    
    for (int t = 0; t < T; t++)
    {
        double cps = 2;

        
        //Read Data
        in >> C >> F >> X;
        
        //C - cost to buy farm
        //F - increase in cookie production with farm
        //X - Goal
        double ans = 0;
        
        while(1)
        {
            //Figure out if we should wait, or buy a new farm
            
            double secondsIfWeWait = X/cps;
            
            double secondsTillBuyFarm = C/cps;
            double cpsAfterFarm = cps+F;
            double secondsWithFarm = secondsTillBuyFarm + X/cpsAfterFarm;
            
            if(secondsIfWeWait <= secondsWithFarm)
            {
                ans += secondsIfWeWait;
                break;
            }
            else
            {
                cps = cpsAfterFarm;
                ans += secondsTillBuyFarm;
            }
        }
        
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(7);
        
        out.setf(ios::fixed);
        out.setf(ios::showpoint);
        out.precision(7);
        
        out << "Case #" << t+1 << ": " << ans;
        cout << "Case #" << t+1 << ": " << ans;
        
        out << endl;
        cout << endl;

    }
    
    return 0;
}
