/* This program should be run with its input piped from the input file and its output piped to the output file. */

#include <iostream>

using namespace std;

int main() {
    int iNumTests;
    double C, F, X;
    
    cin >> iNumTests;
    
    cout.precision(7);
    cout << fixed;
    
    for (int test = 1; test <= iNumTests; ++test) {
        cin >> C >> F >> X;
        double dRate = 2.0;
        double dTimeToFarms  = C / dRate;
        double dTimeToFinish = X / dRate;
        
        //   sec to farm        sec from farm   sec to end w/o farm
        while (dTimeToFarms + X / (dRate + F) < dTimeToFinish) {
            dRate         += F;
            dTimeToFinish  = dTimeToFarms + X / dRate;
            dTimeToFarms  += C / dRate;
        }
        
        cout << "Case #" << test << ": " << dTimeToFinish << endl;
    }
    
    return 0;
}
