#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <vector>
#include <thread>
#include <stdint.h>

using namespace std;

int main(){
    int tests;
    cin >> tests;
    for(int i1 = 0; i1 < tests; i1++){
        double c, f, x;
        cin >> c >> f >> x;
        int facts = 0;
        double currentGoalTime = x / (facts * f + 2);
        double lastFactTime = 0;
        for(;;){
            double buildTime = c / (facts * f + 2);
            lastFactTime += buildTime;
            facts++;
            double newGoalTime = x / (facts * f + 2) + lastFactTime;
            if(newGoalTime > currentGoalTime)
                break;
            else
                currentGoalTime = newGoalTime;
            //TODO: add factory
            //TODO: calc new time
        }
        cout << setprecision(9);
        cout << "Case #" << i1 + 1 << ": ";
        printf("%.7lf", currentGoalTime);
        cout << endl;
    }
}
