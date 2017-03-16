/* 
 * File:   main.cpp
 * Author: warlock
 *
 * Created on April 11, 2014, 9:41 PM
 */

#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    double c;
    double f;
    double x;
    int totalCases;
    int farms;
    double time;
    
    scanf("%d", &totalCases);
    for(int currCase = 1; currCase <= totalCases; currCase++)
    {// 30 1 2
        scanf("%lf %lf %lf", &c, &f, &x);
        farms = 0;
        time = 0;
        /*
         * While the time to get to X is greater than
         * the time to get another farm plus the time 
         * to get to X, get more farms         
         */
        while((x/(2 + (f * farms))) > ((c/(2 + (f * farms))) + (x/(2 + (f * (farms + 1))))))
        {
            time += c/(2 + (f * farms));
            farms++;
        }
        time += x/(2 + (f * farms));
        cout << "Case #" << currCase << ": " << setprecision(7) << fixed << showpoint << time << endl;
    }
    return 0;
}

