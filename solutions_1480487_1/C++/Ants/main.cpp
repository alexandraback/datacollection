/* 
 * File:   main.cpp
 * Author: Ants
 *
 * Created on May 5, 2012, 6:54 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N0;
        cin >> N0;
        double points[210];
        bool winner[210];
        double sum0 = 0;
        for (int n = 0; n < N0; n++) {
            cin >> points[n];
            winner[n] = false;
            sum0 += points[n];
        }
        
        int N = N0;
        double sum = sum0;
        
        bool cont = true;
        while (cont) {
            cont = false;
            for (int i = 0; i < N0; i++) {
                if (winner[i]) continue;
                if (points[i] > (sum0 + sum)/N) {
                    cont = true;
                    winner[i] = true;
                    sum -= points[i];
                    N -= 1;
                }
            }
        }
        cout << "Case #" << t << ": ";
        for (int n = 0; n < N0; n++) {
            double result = 100*((sum + sum0)/N - points[n])/sum0;
            if (result < 0.0) result = 0.0;
            cout.precision(16);  
            cout << fixed << result << " ";
        }
        cout << endl;
    }
    return 0;
}

